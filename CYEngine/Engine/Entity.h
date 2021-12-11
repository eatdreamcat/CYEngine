#pragma once
#include "CObject.h"
#include "Vec3.h"
#include "Quaternion.h"
#include "Matrix4x4.h"
#include "CVector.h"



class Entity :
    public CObject
{

public :
    enum class TransformBit {
        /**
         * @zh
         * 无改变
         */
        NONE = 0,
        /**
         * @zh
         * 节点位置改变
         */
        POSITION = (1 << 0),
         /**
          * @zh
          * 节点旋转
          */
         ROTATION = (1 << 1),
          /**
           * @zh
           * 节点缩放
           */
         SCALE = (1 << 2),
    };

    

private:
    TransformBit  _transformBit = TransformBit::NONE;
    unsigned short _cameraMask = 0;
    std::string _name;
    Entity* _parent = nullptr;
    CVector<Entity*> _children;
    bool _active = true;
protected:
    // world
    Matrix4x4 worldMat;
    Vec3 worldPosition;
    Vec3 worldScale;
    Quaternion worldRotation;

    // local
    Vec3 localPosition;
    Vec3 localScale;
    Quaternion localRotation;
    Vec3 eular;

    int tag = 0;
public:
    Entity() {};
    Entity(const std:: string& name ) {
        _name = name;
    };

    Entity(const std::string& name, const Vec3& position) {
        _name = name;
        localPosition = position;
    };

    virtual const std::string& getName() const {
        return this->_name;
    }

    virtual void setName(const std::string& name) {
        this->_name = name;
    }

    bool isActive() const { return _active; }


    void setActive(bool active);
    const Vec3& getPosition() const { return localPosition; };
    void setPosition(float x, float y, float z);
    void setPosition(const Vec3& pos);
    
    const Quaternion& getRotation() const { return localRotation; }
    void setRotation(float x, float y, float z, float w);
    void setRotation(const Quaternion& scale);

    const Vec3& getScale() const { return localScale; };
    void setScale(float x, float y, float z);
    void setScale(const Vec3& scale);

    const Matrix4x4& getWorldMatrix() { return worldMat; };

    /**
    * Returns a tag that is used to identify the node easily.
    *
    * @return An integer that identifies the node.
    *
    * Please use `getTag()` instead.
    */
    virtual int getTag() const;
    /**
     * Changes the tag that is used to identify the node easily.
     *
     * Please refer to getTag for the sample code.
     *
     * @param tag   A integer that identifies the node.
     *
     * Please use `setName()` instead.
     */
    virtual void setTag(int tag);

    /**
    * get & set camera mask, the node is visible by the camera whose camera flag & node's camera mask is true
    */
    unsigned short getCameraMask() const { return _cameraMask; }
    /**
     * Modify the camera mask for current node.
     * If applyChildren is true, then it will modify the camera mask of its children recursively.
     * @param mask A unsigned short bit for mask.
     * @param applyChildren A boolean value to determine whether the mask bit should apply to its children or not.
     */
    virtual void setCameraMask(unsigned short mask, bool applyChildren = true);

    void addChild(Entity& child);
    void setParent(Entity& parent);

    CVector<Entity*> getChildren() const { return this->_children; };
    Entity getChildrenByName(const std::string & name) const;
    unsigned int getChildrenCount() const { return  this->_children.size(); };

    virtual ~Entity() {};
};

