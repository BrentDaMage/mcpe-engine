#include <string.h>

#include "VertexFormat.h"

const mce::VertexFormat mce::VertexFormat::EMPTY = mce::VertexFormat();
const unsigned int mce::VertexFormat::FieldSize[8] = { 0xC, 4, 4, 4, 4, 0, 0, 0 };

mce::VertexFormat::VertexFormat()
{
    m_formatId = 0;
    m_vertexSize = 0;
    if (m_vertexSize != m_fieldOffset[0])
        memset(m_fieldOffset, -1, sizeof(m_fieldOffset));
}

void mce::VertexFormat::enableField(mce::VertexField vertexField)
{
    if (hasField(vertexField)) return;

    m_fieldOffset[vertexField] = m_vertexSize;
    uint8_t v6 = m_vertexSize + mce::VertexFormat::FieldSize[vertexField];
    uint8_t v8 = v6 & 3;
    m_vertexSize = v6;
    if (v8)
        m_vertexSize += 4 - v8;
    m_formatId = (1 << vertexField) | m_formatId;
}

bool mce::VertexFormat::hasField(mce::VertexField vertexField) const
{
    return ((int)m_formatId >> vertexField) & 1;
}

bool mce::VertexFormat::operator==(const mce::VertexFormat &other) const
{
    return m_formatId == other.m_formatId
        && m_vertexSize == other.m_vertexSize
        && memcmp(m_fieldOffset, other.m_fieldOffset, sizeof(m_fieldOffset)) == 0;
}

bool mce::VertexFormat::operator!=(const mce::VertexFormat &other) const
{
    return !(*this == other);
}

bool mce::VertexFormat::operator<(const mce::VertexFormat &other) const
{
    return (unsigned int)memcmp(this, &other, sizeof(mce::VertexFormat)) >> 31;
}
