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
        uint8_t m_fieldMask;
        uint8_t m_fieldOffset[5];
        uint8_t m_vertexSize;

    public:
        VertexFormat();

        void enableField(mce::VertexField vertexField);

        bool hasField(mce::VertexField vertexField) const;
        const void* getFieldOffset(mce::VertexField vertexField, void *vertexData = nullptr) const;

        unsigned int getID() const { return m_fieldMask; }
        unsigned int getVertexSize() const { return m_vertexSize; }

        bool operator==(const mce::VertexFormat &other) const;
        bool operator!=(const mce::VertexFormat &other) const;
        bool operator<(const mce::VertexFormat &other) const;
        operator bool() const { return this != &mce::VertexFormat::EMPTY; }
    };
}