#pragma once
#include "CObject.h"
#include "Vec3.h"
#include "Vec2.h"
#include "CVector.h"
#include "OpenGLMacros.h"

struct Vertex {
    Vec3 position;
    Vec3 normal;
    Vec2 texCoords;
};


class Mesh :
    public CObject
{
public:
    enum PrimitiveMode {
        POINT_LIST,
        LINE_LIST,
        LINE_STRIP,
        LINE_LOOP,
        LINE_LIST_ADJACENCY,
        LINE_STRIP_ADJACENCY,
        ISO_LINE_LIST,
        // raycast detectable:
        TRIANGLE_LIST,
        TRIANGLE_STRIP,
        TRIANGLE_FAN,
        TRIANGLE_LIST_ADJACENCY,
        TRIANGLE_STRIP_ADJACENCY,
        TRIANGLE_PATCH_ADJACENCY,
        QUAD_PATCH_LIST,
    };
private:
    CVector<Vertex> _vertices;
    CVector<unsigned int> _indices;
    unsigned int _VAO, _VBO, _EBO;
public:
    Mesh(const CVector<Vertex>& vertex, const CVector<unsigned int > indices);
    void initialize();
};

