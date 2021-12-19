#pragma once
#include "Light.h"
class DirectionalLight :
    public Light
{
protected:
    Vec3 _angles= Vec3::ZERO;
    Vec3 _direction = Vec3::UNIT_Z;
public:
    DirectionalLight() {}
    DirectionalLight(const Vec3& position, const Vec3& angles, const Vec3& color = Vec3::ONE);
    const Vec3& getDirection() const {
        return _direction;
    }
    void updateDirection();

};

