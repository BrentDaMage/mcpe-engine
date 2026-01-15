#include <string.h>

#include "VertexFormat.h"
#include "Core/Math/Vec3.h"

using namespace mce;

const VertexFormat VertexFormat::EMPTY = VertexFormat();
const unsigned int VertexFormat::FieldSize[] = {
    /* VERTEX_FIELD_POSITION */ sizeof(Vec3),
    /* VERTEX_FIELD_COLOR */    sizeof(uint32_t),
    /* VERTEX_FIELD_NORMAL */   sizeof(uint32_t),
    /* VERTEX_FIELD_UV0 */      sizeof(float), // 4 on 0.12.1, but shouldn't it be 8 for both floats?
    /* VERTEX_FIELD_UV1 */      sizeof(float),
    /* VERTEX_FIELD_UV2 */      0,
    /* VERTEX_FIELD_PBR_IDX */  0,
    /* VERTEX_FIELD_BONEID_0 */ 0
};

VertexFormat::VertexFormat()
{
    m_fieldMask = 0;
    m_vertexSize = 0;
    memset(m_fieldOffset, UINT8_MAX, sizeof(m_fieldOffset));
}

void VertexFormat::enableField(VertexField vertexField)
{
    if (hasField(vertexField)) return;

    m_fieldOffset[vertexField] = m_vertexSize;
    m_vertexSize += VertexFormat::FieldSize[vertexField];
    if (m_vertexSize != 4 * (m_vertexSize >> 2))
        m_vertexSize  = 4 * (m_vertexSize >> 2) + 4;
    m_fieldMask |= (1 << vertexField);
}

bool VertexFormat::hasField(VertexField vertexField) const
{
    return (m_fieldMask >> vertexField) & 1;
}

const void* VertexFormat::getFieldOffset(VertexField vertexField, const void *vertexData) const
{
    return (void*)((uintptr_t)vertexData + m_fieldOffset[vertexField]);
}

bool VertexFormat::operator==(const VertexFormat &other) const
{
    return m_fieldMask == other.m_fieldMask
        && m_vertexSize == other.m_vertexSize
        && memcmp(m_fieldOffset, other.m_fieldOffset, sizeof(m_fieldOffset)) == 0;
}

bool VertexFormat::operator!=(const VertexFormat &other) const
{
    return !(*this == other);
}

bool VertexFormat::operator<(const VertexFormat &other) const
{
    return memcmp(this, &other, sizeof(VertexFormat)) < 0;
}
