#pragma once
#include "CObject.h"
#include"MathBase.h"
class Vec3 :
    public CObject
{
private:
public:
    float x;
    float y;
    float z;
    Vec3():x(0.0f),y(0.0f),z(0.0f) {};
    Vec3(const Vec3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
    };
    Vec3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; };
    Vec3(const float* array) {
        set(array);
    };

    inline Vec3 operator+(const Vec3& v) const
    {
        Vec3 result(*this);
        result.add(v);
        return result;
    };

    inline Vec3& operator+=(const Vec3& v)
    {
        add(v);
        return *this;
    };

    inline Vec3 operator-(const Vec3& v) const
    {
        Vec3 result(*this);
        result.subtract(v);
        return result;
    };

    inline Vec3& operator-=(const Vec3& v)
    {
        subtract(v);
        return *this;
    };

    inline Vec3 operator-() const
    {
        Vec3 result(*this);
        result.negate();
        return result;
    };

    inline Vec3 operator*(float s) const
    {
        Vec3 result(*this);
        result.scale(s);
        return result;
    };

    inline Vec3& operator*=(float s)
    {
        scale(s);
        return *this;
    };

    inline Vec3 operator/(const float s) const
    {
        return Vec3(this->x / s, this->y / s, this->z / s);
    };

    inline bool operator==(const Vec3& v) const
    {
        return x == v.x && y == v.y && z == v.z;
    };

    inline bool operator!=(const Vec3& v) const
    {
        return x != v.x || y != v.y || z != v.z;
    };

    inline bool operator < (const Vec3& rhs) const
    {
        if (x < rhs.x && y < rhs.y && z < rhs.z)
            return true;
        return false;
    };

    inline bool operator >(const Vec3& rhs) const
    {
        if (x > rhs.x && y > rhs.y && z > rhs.z)
            return true;
        return false;
    };


    Vec3 fromColor(unsigned int color)
    {
        float components[3];
        int componentIndex = 0;
        for (int i = 2; i >= 0; --i)
        {
            int component = (color >> i * 8) & 0x0000ff;

            components[componentIndex++] = static_cast<float>(component) / 255.0f;
        }

        Vec3 value(components);
        return value;
    };

    inline float angle(const Vec3& v1, const Vec3& v2)
    {
        float dx = v1.y * v2.z - v1.z * v2.y;
        float dy = v1.z * v2.x - v1.x * v2.z;
        float dz = v1.x * v2.y - v1.y * v2.x;

        return std::atan2(std::sqrt(dx * dx + dy * dy + dz * dz) + MATH_FLOAT_SMALL, dot(v1, v2));
    };



    inline void clamp(const Vec3& min, const Vec3& max)
    {
      
        // Clamp the x value.
        if (x < min.x)
            x = min.x;
        if (x > max.x)
            x = max.x;

        // Clamp the y value.
        if (y < min.y)
            y = min.y;
        if (y > max.y)
            y = max.y;

        // Clamp the z value.
        if (z < min.z)
            z = min.z;
        if (z > max.z)
            z = max.z;
    };

    inline void clamp(const Vec3& v, const Vec3& min, const Vec3& max, Vec3* dst)
    {
    
        // Clamp the x value.
        dst->x = v.x;
        if (dst->x < min.x)
            dst->x = min.x;
        if (dst->x > max.x)
            dst->x = max.x;

        // Clamp the y value.
        dst->y = v.y;
        if (dst->y < min.y)
            dst->y = min.y;
        if (dst->y > max.y)
            dst->y = max.y;

        // Clamp the z value.
        dst->z = v.z;
        if (dst->z < min.z)
            dst->z = min.z;
        if (dst->z > max.z)
            dst->z = max.z;
    };

    inline bool isZero() const
    {
        return x == 0.0f && y == 0.0f && z == 0.0f;
    };

    inline bool isOne() const
    {
        return x == 1.0f && y == 1.0f && z == 1.0f;
    };


    inline Vec3 lerp(const Vec3& target, float alpha) const
    {
        return *this * (1.f - alpha) + target * alpha;
    };

    inline void set(const float* array) {
        x = array[0];
        y = array[1];
        z = array[2];
    };

    inline void set(const Vec3& p1, const Vec3& p2)
    {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
        z = p2.z - p1.z;
    };

    inline void set(float xx, float yy, float zz)
    {
        this->x = xx;
        this->y = yy;
        this->z = zz;
    };

    inline void add(const Vec3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    };

    inline void add(float xx, float yy, float zz)
    {
        x += xx;
        y += yy;
        z += zz;
    };

    inline void scale(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    };

    inline void rotate() {

    };

    inline void setZero()
    {
        x = y = z = 0.0f;
    };

    inline void subtract(const Vec3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    };

    inline float length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    };

    inline float lengthSquared() const
    {
        return (x * x + y * y + z * z);
    };

    inline void negate()
    {
        x = -x;
        y = -y;
        z = -z;
    };

    void normalize()
    {
        float n = x * x + y * y + z * z;
        // Already normalized.
        if (n == 1.0f)
            return;

        n = std::sqrt(n);
        // Too close to zero.
        if (n < MATH_TOLERANCE)
            return;

        n = 1.0f / n;
        x *= n;
        y *= n;
        z *= n;
    };

    Vec3 getNormalized() const
    {
        Vec3 v(*this);
        v.normalize();
        return v;
    };

    void smooth(const Vec3& target, float elapsedTime, float responseTime)
    {
        if (elapsedTime > 0)
        {
            *this += (target - *this) * (elapsedTime / (elapsedTime + responseTime));
        }
    };


    inline float dot(const Vec3& v) const
    {
        return (x * v.x + y * v.y + z * v.z);
    };

    inline void cross(const Vec3& v)
    {
        cross(*this, v, this);
    };

    inline void cross(const Vec3& v1, const Vec3& v2, Vec3* dst)
    {
        MathUtil::crossVec3(&v1.x, &v2.x, &dst->x);
    };

    static float dot(const Vec3& v1, const Vec3& v2)
    {
        return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
    };

    /** equals to Vec3(0,0,0) */
    static const Vec3 ZERO;
    /** equals to Vec3(1,1,1) */
    static const Vec3 ONE;
    /** equals to Vec3(1,0,0) */
    static const Vec3 UNIT_X;
    /** equals to Vec3(0,1,0) */
    static const Vec3 UNIT_Y;
    /** equals to Vec3(0,0,1) */
    static const Vec3 UNIT_Z;

    ~Vec3() {};
};

const Vec3 Vec3::ZERO(0.0f, 0.0f, 0.0f);
const Vec3 Vec3::ONE(1.0f, 1.0f, 1.0f);
const Vec3 Vec3::UNIT_X(1.0f, 0.0f, 0.0f);
const Vec3 Vec3::UNIT_Y(0.0f, 1.0f, 0.0f);
const Vec3 Vec3::UNIT_Z(0.0f, 0.0f, 1.0f);
