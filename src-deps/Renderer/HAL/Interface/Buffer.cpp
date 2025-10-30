#include "Buffer.h"

using namespace mce;

void Buffer::createIndexBuffer(RenderContext& context, unsigned int sizeOfSingleIndice, const void *indices, unsigned int numberOfIndices)
{
    createBuffer(context, sizeOfSingleIndice, indices, numberOfIndices, BUFFER_TYPE_INDEX);
}

void Buffer::createVertexBuffer(RenderContext& context, unsigned int vertexStride, const void *vertices, unsigned int numberOfVertices)
{
    createBuffer(context, vertexStride, vertices, numberOfVertices, BUFFER_TYPE_VERTEX);
}

void Buffer::createDynamicIndexBuffer(RenderContext& context, unsigned int size)
{
    createDynamicBuffer(context, size, BUFFER_TYPE_INDEX, nullptr);
}

void Buffer::createDynamicIndexBuffer(RenderContext& context, unsigned int size)
{
    createDynamicBuffer(context, size, BUFFER_TYPE_VERTEX, nullptr);
}