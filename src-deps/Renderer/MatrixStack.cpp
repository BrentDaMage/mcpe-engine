#include "MatrixStack.h"

Matrix::Matrix()
{
    proj[4 * 0 + 0] = proj[4 * 1 + 1] = proj[4 * 2 + 2] = proj[4 * 3 + 3] = 1.0f;
	proj[1] = proj[2] = proj[3] = proj[4] = proj[6] = proj[7] =
	proj[8] = proj[9] = proj[11] = proj[12] = proj[13] = proj[14] = 0.0f;
}

void Matrix::rotate(float, const Vec3&) {}
void Matrix::scale(const Vec3&) {}
void Matrix::setOrtho(float left, float right, float top, float bottom, float Znear, float Zfar) {}
void Matrix::setPerspective(float fov, float aspect, float Znear, float Zfar) {}
void Matrix::transform3(Vec3&, float&) {}
void Matrix::translate(const Vec3&) {}