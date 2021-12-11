#pragma once
#include "CObject.h"
#include "Entity.h"
struct Viewport
{
    int x = 0;
    int y = 0;
    unsigned int w = 0;
    unsigned int h = 0;
};


class Camera :
    public CObject
{

    
public:
    enum class Type
    {
        PERSPECTIVE = 1,
        ORTHOGRAPHIC = 2
    };
private:
    Entity* entity;
    Type _type = Type::PERSPECTIVE;
    int _priority = 0;
    Vec3 _position;
    Vec3 _forward;
    Vec3 _right;
    Vec3 _up;
    Vec3 _worldUp;
    Matrix4x4 _viewMat;
    Matrix4x4 _proMat;
    Matrix4x4 _matViewProj;

public:
    static Camera* createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane);
    static Camera* createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane);
    static Camera* create();
    static const Camera* getVisitingCamera();
    static const Viewport& getDefaultViewport();
    static void setDefaultViewport(const Viewport& vp);
    static Camera* getDefaultCamera();

    Camera(const Vec3& position, const Vec3& target, const Vec3& worldup);
    Camera::Type getType() const { return _type; }
    ~Camera();


    // ¡Ÿ ±
    const Matrix4x4 getViewMatrix() {
        Matrix4x4 viewMat;
        Matrix4x4::createLookAt(_position, _position + _forward, _worldUp, &viewMat);
        return viewMat;
    }
};


