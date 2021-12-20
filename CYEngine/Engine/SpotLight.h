#pragma once
#include "DirectionalLight.h"
#include "PointLight.h"
class SpotLight :
    public  DirectionalLight, public PointLight
{
private :
    float _cosInner = cosf(MATH_DEG_TO_RAD(30.0f));
    float _cosOutter = cosf(MATH_DEG_TO_RAD(45.0f));
   
public :
    SpotLight(const Vec3& position, const Vec3& angles, float thetaInner,float thetaOutter , float constant, float linear, float quadratic, const Vec3& diffuse = Vec3::ONE, const Vec3& ambient = Vec3::ONE, const Vec3& specular = Vec3::ONE);
   
    float getCosInner() const {
        return _cosInner;
    }

    float getCosOutter() const {
        return _cosOutter;
    }
};

