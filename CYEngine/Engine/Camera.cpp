#include "Camera.h"

void Camera::_updateCamera()
{

    auto pitchRad = MATH_DEG_TO_RAD(_eular.x);
    auto yawRad = MATH_DEG_TO_RAD(_eular.y);

    _forward.x = cosf(pitchRad) * sinf(yawRad);
    _forward.y = sinf(pitchRad);
    _forward.z = cosf(pitchRad) * cosf(yawRad);
    _forward.normalize();
    _right = Vec3::cross(_forward, _worldUp).getNormalized();
    _up = Vec3::cross(_right,_forward ).getNormalized();
}

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
    _worldUp = worldup.getNormalized();
    _forward = (target - position).getNormalized();
    _right = Vec3::cross(_forward, _worldUp).getNormalized();
    _up = Vec3::cross(_right, _forward).getNormalized() ;
}

Camera::Camera(const Vec3& position, float pitchAngle, float yawAngle, float rollAngle, const Vec3& worldUp)
{
    _eular.x = pitchAngle;
    _eular.y = yawAngle;
    _eular.z = rollAngle;
    _position = position;
    _worldUp = worldUp.getNormalized();
    _updateCamera();

}

Camera::~Camera()
{
}

void Camera::processMouseInput(float deltaX, float deltaY)
{
    _eular.x += deltaY;
    _eular.y += deltaX;
    _updateCamera();
}

void Camera::move(float deltaX, float deltaY, float deltaZ)
{

    _position += _forward * deltaZ*0.1 + _right * deltaX*0.1 + _up * deltaY*0.1;

}
