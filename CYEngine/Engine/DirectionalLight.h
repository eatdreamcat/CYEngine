#pragma once
#include "Light.h"
class DirectionalLight :
    public virtual Light
{
protected:
    Vec3 _angles= Vec3::ZERO;
    // ³¯ÆÁÄ»Íâ
    Vec3 _direction = Vec3::UNIT_Z;
public:
    DirectionalLight() {}
    DirectionalLight(const Vec3& angles, const Vec3& diffuse = Vec3::ONE, const Vec3& ambient = Vec3::ONE, const Vec3& specular = Vec3::ONE);
    const Vec3& getDirection() const {
        return _direction;
    }
    void updateDirection();

};

