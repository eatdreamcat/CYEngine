#include "RenderableComponent.h"
#include <iostream>
const Material& RenderableComponent::getSharedMaterial()
{
    return getMaterial(0);
}

const Material& RenderableComponent::getMaterial(int index)
{
    if (index < 0 || index > _materials.size()) {
        std::cout << " index out of range." << std::endl;
        return _materials[0];
    }

    return _materials[index];
}

RenderableComponent::~RenderableComponent()
{
}
