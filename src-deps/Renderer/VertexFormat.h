#pragma once

#include <stdint.h>

#include "VertexField.h"

namespace mce
{
    class VertexFormat
    {
        struct FieldOffset
        {
            uint8_t m_offset;
            uint8_t m_size;
        };

    public:
        static const mce::VertexFormat EMPTY;
        static const unsigned int FieldSize[8];

    private:
        uint8_t m_formatId;
        uint8_t m_fieldOffset[5];
        uint8_t m_vertexSize;

    public:
        VertexFormat();

        void enableField(mce::VertexField vertexField);

        bool hasField(mce::VertexField vertexField) const;
        unsigned int getFieldOffset(mce::VertexField vertexField, void *vertexData) const { return (unsigned int)vertexData + m_fieldOffset[vertexField]; }

        unsigned int getID() const { return m_formatId; }
        unsigned int getVertexSize() const { return m_vertexSize; }

        bool operator==(const mce::VertexFormat &other) const;
        bool operator!=(const mce::VertexFormat &other) const;
        bool operator<(const mce::VertexFormat &other) const;
        operator bool() const { return this != &mce::VertexFormat::EMPTY; }
    };
}