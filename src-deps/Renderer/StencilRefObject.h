#pragma once

namespace mce
{
    class StencilRefObject
    {
    public:
        unsigned int stencilRef;

        StencilRefObject(unsigned int ref);

        bool operator==(const mce::StencilRefObject& other) const;
        bool operator!=(const mce::StencilRefObject& other) const;
    };
}