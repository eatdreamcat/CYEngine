#include "PointLight.h"

PointLight::PointLight(const Vec3& position, float constant, float linear, float quadratic, const Vec3& color):
	_constant(constant),
	_linear(linear),
	_quadratic(quadratic)
{
	_position = position;
	_color = color;
}
