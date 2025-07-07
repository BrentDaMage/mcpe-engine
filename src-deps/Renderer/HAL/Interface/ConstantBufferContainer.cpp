#include "ConstantBufferContainer.h"

mce::ConstantBufferContainer::ConstantBufferContainer()
{
    mce::ConstantBufferContainerOGL::ConstantBufferContainerOGL();
}

mce::ConstantBufferContainer::ConstantBufferContainer(mce::ConstantBufferContainer& other)
{
    mce::ConstantBufferContainerOGL::ConstantBufferContainerOGL(other);
}

mce::ConstantBufferContainer::~ConstantBufferContainer()
{
    mce::ConstantBufferContainerOGL::~ConstantBufferContainerOGL();
}

mce::ShaderConstant* mce::ConstantBufferContainer::getUnspecializedShaderConstant(const std::string& name)
{
    for (std::vector<mce::ShaderConstant*>::iterator it = m_shaderConstants.begin(); it != m_shaderConstants.end(); it++)
    {
        if ((*it)->getName() == name)
        {
            return;
        }
    }
}

void mce::ConstantBufferContainer::registerReflectedShaderParameter(const mce::UniformMetaData& uniMeta)
{
    mce::ConstantBufferContainerOGL::registerReflectedShaderParameter(uniMeta);
}

void mce::ConstantBufferContainer::finalizeConstantBufferLayout()
{
    mce::ConstantBufferContainerOGL::finalizeConstantBufferLayout();
}

bool mce::ConstantBufferContainer::isDirty() const
{
    return mce::ConstantBufferContainerOGL::isDirty();
}

std::string mce::ConstantBufferContainer::getConstantBufferName() const
{
    return mce::ConstantBufferContainerOGL::getConstantBufferName();
}