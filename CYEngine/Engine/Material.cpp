#include "Material.h"
#include <iostream>
void Material::setLightFactor()
{
	_shader->setFloatArray("material.ambient", 3, _lightFactor.ambient);
	_shader->setTexture("material.diffuse", _lightFactor.diffuse->getSlot());
	_shader->setTexture("material.specular",_lightFactor.specular->getSlot());
	_shader->setTexture("material.emission", _lightFactor.emission->getSlot());
	_shader->setInt("material.shininess", _lightFactor.shininess);
}
