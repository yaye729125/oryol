#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::glShaderFactory
    @ingroup _priv
    @brief private: GL implementation of class shaderFactory
*/
#include "Gfx/base/renderSimpleFactory.h"
#include "Gfx/Core/mesh.h"
#include "Gfx/Core/Enums.h"

namespace Oryol {
namespace _priv {
    
class shader;
    
class glShaderFactory : public renderSimpleFactory<shader, ResourceType::Shader> {
public:
    /// constructor
    glShaderFactory();
    /// destructor
    ~glShaderFactory();
    
    /// setup the factory
    void Setup();
    /// discard the factory
    void Discard();
    /// return true if the object has been setup
    bool IsValid() const;

    /// setup shader resource (directly setup shader, no loaders)
    void SetupResource(shader& shd);
    /// destroy the shader
    void DestroyResource(shader& shd);
    
    /// compile a GL shader (return 0 if failed)
    GLuint compileShader(ShaderType::Code type, const String& src) const;
    
private:
    bool isValid;
};
    
} // namespace _priv
} // namespace Oryol