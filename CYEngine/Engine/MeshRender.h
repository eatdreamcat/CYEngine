#pragma once
#include "RenderableComponent.h"
#include "Mesh.h"
class MeshRender :
    public RenderableComponent
{
private:
    void _onMeshChanged(const Mesh& old);
    void _updateModels();
protected:
    Mesh _mesh;
public:
    const Mesh& getMesh() { return _mesh; }

    void setMesh(const Mesh& mesh);



};

