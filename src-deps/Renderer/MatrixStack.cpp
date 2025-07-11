#include <typeinfo>
#include "MatrixStack.h"

MatrixStack MatrixStack::View = MatrixStack();
MatrixStack MatrixStack::World = MatrixStack();
MatrixStack MatrixStack::Projection = MatrixStack();

Matrix::Matrix()
{
    _m = glm::tmat4x4<float>();
}

void Matrix::rotate(float, const Vec3&) {}
void Matrix::scale(const Vec3&) {}
void Matrix::setOrtho(float left, float right, float top, float bottom, float Znear, float Zfar) {}
void Matrix::setPerspective(float fov, float aspect, float Znear, float Zfar) {}
void Matrix::transform3(Vec3&, float&) {}
void Matrix::translate(const Vec3&) {}

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