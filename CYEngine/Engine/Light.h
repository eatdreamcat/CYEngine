#pragma once
#include "CObject.h"
#include "Vec3.h"
class Light :
    public CObject
{

public:
	enum class Type
	{
		SPOT,
		DIRECTIONAL,
		POINT
	};


protected:
	Vec3 _position = Vec3::ZERO;
	Vec3 _diffuse = Vec3::ONE;
	Vec3 _ambient = Vec3::ONE;
	Vec3 _specular = Vec3::ONE;
	Light::Type _type= Light::Type::DIRECTIONAL;
public:
	virtual const Vec3& getPosition() const {
		return _position;
	}

	virtual const Vec3& getAmbient() const {
		return _ambient;
	}

	virtual const Vec3& getSpecular() const {
		return _specular;
	}

	virtual const Vec3& getDiffuse() const {
		return _diffuse;
	}

	virtual ~Light();
};

