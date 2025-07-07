#include "ConstantBufferContainerOGL.h"

mce::ConstantBufferContainerOGL::ConstantBufferContainerOGL()
{
    mce::ConstantBufferContainerBase::ConstantBufferContainerBase(); 
}

mce::ConstantBufferContainerOGL::ConstantBufferContainerOGL(mce::ConstantBufferContainerOGL& other)
{
    mce::ConstantBufferContainerBase::ConstantBufferContainerBase(other);
}

mce::ConstantBufferContainerOGL::~ConstantBufferContainerOGL()
{
    mce::ConstantBufferContainerBase::~ConstantBufferContainerBase();
}

void mce::ConstantBufferContainerOGL::sync()
{
    
}