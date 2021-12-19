#pragma once
#include "CObject.h"
#include "Shader.h"
#include "Vec3.h"
#include "GlTexture.h"

struct LighttingFactor {
    float *ambient;
    GlTexture *diffuse;
    GlTexture* specular;
    GlTexture* emission;
    unsigned int shininess;
};


class Material :
    public CObject
{
private:
   
    GlTexture* _glTexture = nullptr;
    LighttingFactor _lightFactor = { 0, 0, 0, 0,1 };

    
public:
    Shader* _shader = nullptr;
    Material(Shader* shader, GlTexture* texture, GlTexture* diffuse, const float* ambient, GlTexture* specular, GlTexture* emission, unsigned int shininess):
    _shader(shader),
    _glTexture(texture),
        _lightFactor({ new float[3]{ambient[0],ambient[1],ambient[2]} , diffuse ,specular,emission, shininess })
    {
    
        setLightFactor();

    };
    void setLightFactor();
    ~Material() {};
};

