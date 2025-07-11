#pragma once

#include <stack>
#include <glm/glm.hpp>
#include "Core/Math/Vec3.h"

class Matrix
{
private:
    glm::tmat4x4<float> _m;

public:
	Matrix();         // create an empty matrix
	Matrix(float a);  // create an identity matrix
	Matrix(float* p); // load matrix from memory
	Matrix(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
    Matrix(const glm::tmat4x4<float>& m)
    {
        _m = m;
    }

    void rotate(float, const Vec3&);
	void scale(const Vec3&);
	void setOrtho(float, float, float, float, float, float);
	void setPerspective(float, float, float, float);
	void transform3(Vec3&, float&);
	void translate(const Vec3&);
    
    friend Matrix operator*(const Matrix& a, const Matrix& b)
    {
        return Matrix(a._m * b._m);
    }
};

class MatrixStack
{
    class Ref;

public:
    static MatrixStack View;
    static MatrixStack World;
    static MatrixStack Projection;

private:
    std::stack<Matrix> m_stack;
    bool m_bIsDirty;

public:
    MatrixStack();
    
private:
    Matrix* _push();
    Matrix* _pushIdentity();

public:
    Matrix* top();
    Matrix* getTop();
    bool empty() const { return m_stack.empty(); }
    bool isDirty() const { return m_bIsDirty; }
    void makeClean() { m_bIsDirty = false; };
    void pop();
    size_t size() const { return m_stack.size(); }
    Ref push();

    class Ref
    {
    private:
        MatrixStack* m_mtxStack;
        Matrix* m_matrix;
    public:
        Ref();
        Ref(MatrixStack& mtxStk, Matrix& mtx);
        Ref(Ref& other);
        
    private:
        void _move(Ref& other);

    public:
        void release();

        Matrix* operator*();
        void operator=(const Matrix& other);
        void operator=(Ref&& other);
    }
};