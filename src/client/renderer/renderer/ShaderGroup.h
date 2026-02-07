#pragma once

#include "ShaderGroupBase.h"
#include "AppPlatformListener.hpp"

namespace mce
{
    class ShaderGroup : public ShaderGroupBase, public AppPlatformListener
    {
    protected:
        static ShaderGroup* singletonPtr;

    public:
        ShaderGroup();
        ~ShaderGroup();

    protected:
        void _clearShaders();
        void _clearPrograms();
    
    public:
        void onAppSuspended() override;

        ShaderProgram& getShaderProgram(ShaderType shaderType, const std::string& codeOrPath, const std::string& header);
        Shader& loadShader(const std::string& header, const std::string& vertexCodeOrPath, const std::string& fragmentCodeOrPath, const std::string& geometryCodeOrPath);

        static ShaderGroup* singleton();
    };
}