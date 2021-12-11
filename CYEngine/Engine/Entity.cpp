#include "Entity.h"


void Entity::setPosition(float x, float y, float z) {

}

void Entity::setPosition(const Vec3& pos) {

}



void Entity::setScale(float x, float y, float z) {

}
void Entity::setScale(const Vec3& scale) {

}

void Entity::setRotation(float x, float y, float z, float w) {

}

void Entity::setRotation(const Quaternion& scale) {

}


void Entity::setActive(bool active) {

    if (active == _active) return;
    _active = active;
}

int Entity::getTag() const
{
    return 0;
}

void Entity::setTag(int tag)
{
}

void Entity::setCameraMask(unsigned short mask, bool applyChildren)
{
}

void Entity::addChild(Entity& child)
{
}

void Entity::setParent(Entity& parent)
{
}

Entity Entity::getChildrenByName(const std::string& name) const
{
    return Entity();
}
