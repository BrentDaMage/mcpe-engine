#include <typeinfo>
#include <glm/glm.hpp>
#include "MatrixStack.h"

MatrixStack MatrixStack::View = MatrixStack();
MatrixStack MatrixStack::World = MatrixStack();
MatrixStack MatrixStack::Projection = MatrixStack();

Matrix::Matrix()
{
    _m = glm::tmat4x4<float>();
}

void Matrix::rotate(float angle, const Vec3& vector)
{
    _m = glm::rotate(_m, glm::radians(angle), glm::normalize(glm::vec3(vector.x, vector.y, vector.z)));
}

void Matrix::scale(const Vec3& vector)
{
    _m = glm::scale(_m, glm::vec3(vector.x, vector.y, vector.z));
}

void Matrix::setOrtho(float left, float right, float top, float bottom, float Znear, float Zfar)
{
    _m = glm::ortho(_m, left, right, top, bottom, Znear, Zfar);
}

void Matrix::setPerspective(float fov, float aspect, float Znear, float Zfar)
{
    _m = glm::perspective(glm::radians(fov), aspect, Znear, Zfar);
}

void Matrix::transform3(Vec3& var1, float& var2)
{
    // todo
}

void Matrix::translate(const Vec3& vector)
{
    _m = glm::translate(_m, vector);
}

MatrixStack::MatrixStack()
{
    m_bIsDirty = true;
    _pushIdentity();
}

MatrixStack::Ref* MatrixStack::push()
{
    m_bIsDirty = true;
    return new Ref(*this, *_push());
}

MatrixStack::Ref* MatrixStack::pushIdentity()
{
    m_bIsDirty = true;
    return new Ref(*this, *_pushIdentity());
}

Matrix* MatrixStack::_push()
{
    // todo
}

Matrix* MatrixStack::_pushIdentity()
{
    // todo
}

Matrix* MatrixStack::top()
{
    return m_stack.top();
}

Matrix* MatrixStack::getTop()
{
    m_bIsDirty = true;
    return m_stack.top();
}

void MatrixStack::pop()
{
    m_bIsDirty = true;

    if (empty())
    {
        //LOG_E("Bad stack usage");
        throw std::bad_cast();
    }

    m_stack.pop();
}

MatrixStack::Ref::Ref()
{
	m_mtxStack = nullptr;
	m_matrix = nullptr;
}

MatrixStack::Ref::Ref(MatrixStack& mtxStk, Matrix& mtx)
{
	m_mtxStack = &mtxStk;
	m_matrix = &mtx;
}

MatrixStack::Ref::Ref(Ref& other)
{
	_move(other);
}

Matrix* MatrixStack::Ref::operator*()
{
	if (!m_matrix)
	{
		//LOG_E("Dereferencing a null reference");
		throw std::bad_cast();
	}
	m_mtxStack->m_bIsDirty = true;
	return m_matrix;
}