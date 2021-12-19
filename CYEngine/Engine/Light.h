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
	Vec3 _color = Vec3::ONE;
	Light::Type _type= Light::Type::DIRECTIONAL;
public:
	const Vec3& getPosition() const {
		return _position;
	}

	const Vec3& getColor() const {
		return _color;
	}


	virtual ~Light();
};

