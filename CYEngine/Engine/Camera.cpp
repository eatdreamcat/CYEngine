#include "Camera.h"

Camera* Camera::createPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
{
    return nullptr;
}

Camera* Camera::createOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane)
{
    return nullptr;
}

Camera* Camera::create()
{
    return nullptr;
}

const Camera* Camera::getVisitingCamera()
{
    return nullptr;
}

const Viewport& Camera::getDefaultViewport()
{
    // TODO: 在此处插入 return 语句
    
     return Viewport{0,0,0,0};
}

void Camera::setDefaultViewport(const Viewport& vp)
{
}

Camera* Camera::getDefaultCamera()
{
    return nullptr;
}

Camera::Camera(const Vec3& position, const Vec3& target, const Vec3& worldup)
{
    _position = position;
    _worldUp = worldup;
    _forward = (target - position).getNormalized();
    _right = Vec3::cross(_forward, worldup).getNormalized();
    _up = Vec3::cross(_forward, _right).getNormalized() ;
}

Camera::~Camera()
{
}
