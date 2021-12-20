#include "SpotLight.h"
#include<iostream>
SpotLight::SpotLight(const Vec3& position, const Vec3& angles, float thetaInner, float thetaOutter , float constant, float linear, float quadratic, const Vec3& diffuse, const Vec3& ambient, const Vec3& specular)
{
	this->_angles = angles;
	this->_position = position;
	this->_diffuse = diffuse;
	this->_ambient = ambient;
	this->_specular = specular;

	this->_constant = constant;
	this->_linear = linear;
	this->_quadratic = quadratic;

	if (thetaOutter <= thetaInner) thetaOutter = thetaInner + 1.0f;
	this->_cosInner = cosf(MATH_DEG_TO_RAD(thetaInner));
	this->_cosOutter = cosf(MATH_DEG_TO_RAD(thetaOutter ));
	
	updateDirection();

}
