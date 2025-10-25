#include "ConstantBufferContainer.h"

using namespace mce;

ConstantBufferContainer::ConstantBufferContainer()
    : ConstantBufferContainerOGL()
{
}

ConstantBufferContainer::ConstantBufferContainer(ConstantBufferContainer&& other)
    : ConstantBufferContainerOGL(std::move(other))
{
}

ShaderConstant* ConstantBufferContainer::getUnspecializedShaderConstant(const std::string& name)
{
    return ConstantBufferContainerOGL::getUnspecializedShaderConstant(name);
}

void ConstantBufferContainer::registerReflectedShaderParameter(const UniformMetaData& uniMeta)
{
    ConstantBufferContainerOGL::registerReflectedShaderParameter(uniMeta);
}

void ConstantBufferContainer::finalizeConstantBufferLayout()
{
    ConstantBufferContainerOGL::finalizeConstantBufferLayout();
}

bool ConstantBufferContainer::isDirty() const
{
    return ConstantBufferContainerOGL::isDirty();
}

std::string ConstantBufferContainer::getConstantBufferName() const
{
    return ConstantBufferContainerOGL::getConstantBufferName();
}