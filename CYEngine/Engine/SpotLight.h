#pragma once
#include "DirectionalLight.h"
class SpotLight :
    public DirectionalLight
{
private :
    float _cosInner = cosf(MATH_DEG_TO_RAD(30.0f));
    float _cosOutter = cosf(MATH_DEG_TO_RAD(45.0f));
   
public :
    SpotLight(const Vec3& position, const Vec3& angles, float thetaInner,float thetaOutter ,const Vec3& color = Vec3::ONE);
   
    float getCosInner() const {
        return _cosInner;
    }

    float getCosOutter() const {
        return _cosOutter;
    }
};

