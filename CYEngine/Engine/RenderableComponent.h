#pragma once
#include "Component.h"
#include "CVector.h"
#include "Material.h"
class RenderableComponent :
    public Component
{

public:
    enum class Layers {
        NONE
    };

    const Material& getSharedMaterial();
    const Material& getMaterial(int index);
    virtual ~RenderableComponent();
protected:
    CVector<Material> _materials;
    Layers _visibility = Layers::NONE;
private:

};

