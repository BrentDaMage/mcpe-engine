#include <typeinfo>
#include "BufferOGL.h"

using namespace mce;

GLenum glTargetFromBufferType(BufferType bufferType)
{
    switch (bufferType)
    {
        case BUFFER_TYPE_VERTEX:
            return GL_ARRAY_BUFFER;
        case BUFFER_TYPE_INDEX:
            return GL_ELEMENT_ARRAY_BUFFER;
        default:
            //LOG_E("Unknown bufferType: %d", bufferType);
            throw std::bad_cast();
    }
}