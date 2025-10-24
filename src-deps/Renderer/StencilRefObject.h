#pragma once

namespace mce
{
    class StencilRefObject
    {
    public:
        unsigned int stencilRef;

        StencilRefObject(unsigned int ref = 0);

        bool operator==(const mce::StencilRefObject& other) const;
        bool operator!=(const mce::StencilRefObject& other) const;
    };
}