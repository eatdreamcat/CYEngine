#include "SpotLight.h"

SpotLight::SpotLight(const Vec3& position, const Vec3& angles, float thetaInner, float thetaOutter ,const Vec3& color)
{
	_angles = angles;
	_position = position;
	_color = color;
	if (thetaOutter <= thetaInner) thetaOutter = thetaInner + 1.0f;
	_cosInner = cosf(MATH_DEG_TO_RAD(thetaInner));
	_cosOutter = cosf(MATH_DEG_TO_RAD(thetaOutter ));
	updateDirection();
}
