#pragma once
#include "Light.h"

class PointLight :
    public virtual Light
{
protected :
    float _constant = 0.0f;
    float _linear = 0.0f;
    float _quadratic = 0.0f;
public:
    PointLight() {};
    PointLight(const Vec3& position, float constant, float linear, float quadratic, const Vec3& diffuse = Vec3::ONE, const Vec3& ambient = Vec3::ONE, const Vec3& specular = Vec3::ONE);

   float getConstant() const  {
        return _constant;
    }

     float getLinear() const {
        return _linear;
    }

    float getQuadratic() const {
        return _quadratic;
    }
};

