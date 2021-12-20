#include "PointLight.h"

PointLight::PointLight(const Vec3& position, float constant, float linear, float quadratic, const Vec3& diffuse, const Vec3& ambient, const Vec3& specular):
	_constant(constant),
	_linear(linear),
	_quadratic(quadratic)
{
	_position = position;
	_diffuse = diffuse;
	_ambient = ambient;
	_specular = specular;
}
