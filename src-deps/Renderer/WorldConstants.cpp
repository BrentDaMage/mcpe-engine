#include <glm/glm.hpp>
#include "MatrixStack.h"
#include "GlobalConstantBufferManager.h"
#include "RenderContextImmediate.h"
#include "WorldConstants.h"

mce::WorldConstants::WorldConstants()
{
    WORLDVIEWPROJ = nullptr;
    WORLD = nullptr;
}

void mce::WorldConstants::refreshWorldConstants()
{
    if (!MatrixStack::Projection.isDirty() &&
        !MatrixStack::View.isDirty() &&
        !MatrixStack::World.isDirty())
    {
        // Exit early if no matrices have been updated since the last frame.
        return;
    }

    // Get the current transformation matrices from the global stacks.
    const Matrix& projectionMatrix = *MatrixStack::Projection.top();
    const Matrix& viewMatrix       = *MatrixStack::View.top();
    const Matrix& worldMatrix      = *MatrixStack::World.top();

    // Calculate the combined World-View-Projection matrix.
    // The order is crucial: Projection * View * World.
    Matrix worldViewProjMatrix = (projectionMatrix * viewMatrix) * worldMatrix;

    if (WORLDVIEWPROJ)
        WORLDVIEWPROJ->setData(&worldViewProjMatrix);

    if (WORLD)
        WORLD->setData(&worldMatrix);

    // Mark the stacks as clean to prevent redundant calculations in subsequent calls.
    MatrixStack::Projection.makeClean();
    MatrixStack::View.makeClean();
    MatrixStack::World.makeClean();

    // Sync the updated constant buffer data to the GPU.
    mce::RenderContext& renderContext = mce::RenderContextImmediate::get();
    m_constantBuffer->sync(renderContext);
}

void mce::WorldConstants::init()
{
    mce::GlobalConstantBufferManager* pBufferManager = mce::GlobalConstantBufferManager::getInstance();
    m_constantBuffer = pBufferManager->findConstantBufferContainer("WorldConstants");

    mce::ShaderConstantBase* pWorldViewProj = m_constantBuffer->getUnspecializedShaderConstant("WORLDVIEWPROJ");
    if (pWorldViewProj)
    {
        if (pWorldViewProj->getType() == SHADER_PRIMITIVE_MATRIX4x4)
        {
            WORLDVIEWPROJ = (mce::ShaderConstantMatrix4x4*)pWorldViewProj;
        }
        else
        {
            WORLDVIEWPROJ = nullptr;
        }
    }

    mce::ShaderConstantBase* pWorld = m_constantBuffer->getUnspecializedShaderConstant("WORLD");
    if (pWorld)
    {
        if (pWorld->getType() == SHADER_PRIMITIVE_MATRIX4x4)
        {
            WORLD = (mce::ShaderConstantMatrix4x4*)pWorld;
        }
        else
        {
            WORLD = nullptr;
        }
    }
}