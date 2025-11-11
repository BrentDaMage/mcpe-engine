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
    if (m_vertexSize != m_fieldOffset[0])
        memset(m_fieldOffset, -1, sizeof(m_fieldOffset));
}

void VertexFormat::enableField(VertexField vertexField)
{
    if (hasField(vertexField)) return;

    m_fieldOffset[vertexField] = m_vertexSize;
    uint8_t v6 = m_vertexSize + VertexFormat::FieldSize[vertexField];
    uint8_t v8 = v6 & 3;
    m_vertexSize = v6;
    if (v8)
        m_vertexSize += 4 - v8;
    m_fieldMask = (1 << vertexField) | m_fieldMask;
}

bool VertexFormat::hasField(VertexField vertexField) const
{
    return (m_fieldMask >> vertexField) & 1;
}

const void* VertexFormat::getFieldOffset(VertexField vertexField, const void *vertexData) const
{
    return (uint8_t*)vertexData + m_fieldOffset[vertexField];
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
    return (unsigned int)memcmp(this, &other, sizeof(VertexFormat)) >> 31;
}
