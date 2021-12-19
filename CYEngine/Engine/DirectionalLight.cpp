#include "DirectionalLight.h"
#include "Quaternion.h"

DirectionalLight::DirectionalLight(const Vec3& position, const Vec3& angles, const Vec3& color):
	_angles(angles)
{
	_position = position;
	_color = color;
	updateDirection();
}

void DirectionalLight::updateDirection()
{
	Quaternion  quaZ;
	Quaternion::createFromAxisAngle(Vec3::UNIT_Z, _angles.z, &quaZ);
	_direction = quaZ * _direction;

	Quaternion  quaX;
	Quaternion::createFromAxisAngle(Vec3::UNIT_X, _angles.x, &quaX);
	_direction = quaX * _direction;

	Quaternion  quaY;
	Quaternion::createFromAxisAngle(Vec3::UNIT_Y, _angles.y, &quaY);
    _direction = quaY * _direction;
	_direction.negate();
}
