#pragma once
#include "Light.h"

class PointLight :
    public Light
{
private :
    float _constant;
    float _linear;
    float _quadratic;
public:
    PointLight(const Vec3& position, float constant, float linear, float quadratic, const Vec3& color = Vec3::ONE);

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

