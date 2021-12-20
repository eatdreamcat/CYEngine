#include "DirectionalLight.h"
#include <iostream>
DirectionalLight::DirectionalLight(const Vec3& angles, const Vec3& diffuse, const Vec3& ambient, const Vec3& specular):
	_angles(angles)
{
	
	_diffuse = diffuse;
	_ambient = ambient;
	_specular = specular;
	updateDirection();
}

void DirectionalLight::updateDirection()
{
	
	_direction.rotateZ(_angles.z);
	
	_direction.rotateX(_angles.x);
	
	_direction.rotateY(_angles.y);
	
	_direction.negate();
	
}
