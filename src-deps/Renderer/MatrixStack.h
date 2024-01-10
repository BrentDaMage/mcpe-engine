#pragma once

class Matrix
{
private:
    float proj[16];

public:
    Matrix();

    void rotate(float, const Vec3&);
	void scale(const Vec3&);
	void setOrtho(float, float, float, float, float, float);
	void setPerspective(float, float, float, float);
	void transform3(Vec3&, float&);
	void translate(const Vec3&);
}

class MatrixStack
{
private:
    std::vector<Matrix> m_stack;
    bool m_bIsDirty;

public:
    MatrixStack();
    
    Matrix* _push();
    Matrix* _pushIdentity();
    Matrix* getTop();
    bool empty() const;
    bool isDirty();
    bool makeClean();
    void pop();
    size_t size();
    Ref push();

    class Ref
    {
    private:
        MatrixStack* m_refMtxStack;
        Matrix* m_refMatrix;
    public:
        Ref();
        Ref(MatrixStack& mtxStk, Matrix& mtx);
        Ref(Ref&& other);
        
        void _move(Ref& other);

        Matrix& operator*();
        void operator=(const Matrix& other);
        void operator=(Ref&& other);

        void release();
    }
}