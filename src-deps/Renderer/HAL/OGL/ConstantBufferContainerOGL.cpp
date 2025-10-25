#include "ConstantBufferContainerOGL.h"

using namespace mce;

ConstantBufferContainerOGL::ConstantBufferContainerOGL()
    : ConstantBufferContainerBase()
{
}

ConstantBufferContainerOGL::ConstantBufferContainerOGL(ConstantBufferContainerOGL&& other)
    : ConstantBufferContainerBase(std::move(other))
{
}

void ConstantBufferContainerOGL::sync()
{
    
}