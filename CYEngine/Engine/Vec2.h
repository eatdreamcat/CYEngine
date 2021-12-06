#pragma once
#include "CObject.h"
#include"MathBase.h"
class Vec2 :
    public CObject
{
private:
public:
    float x;
    float y;
    Vec2() :x(0.0f), y(0.0f) {};
    Vec2(const Vec2& other) {
        x = other.x;
        y = other.y;
    };
    Vec2(float x, float y) { this->x = x; this->y = y;  };
    Vec2(const float* array) {
        set(array);
    };

    inline Vec2 Vec2::operator+(const Vec2& v) const
    {
        Vec3 result(*this);
        result.add(v);
        return result;
    };

    inline Vec2& Vec2::operator+=(const Vec2& v)
    {
        add(v);
        return *this;
    };

    inline Vec2 Vec2::operator-(const Vec2& v) const
    {
        Vec2 result(*this);
        result.subtract(v);
        return result;
    };

    inline Vec2& Vec2::operator-=(const Vec2& v)
    {
        subtract(v);
        return *this;
    };

    inline Vec2 Vec2::operator-() const
    {
        Vec2 result(*this);
        result.negate();
        return result;
    };

    inline Vec2 Vec2::operator*(float s) const
    {
        Vec2 result(*this);
        result.scale(s);
        return result;
    };

    inline Vec2& Vec2::operator*=(float s)
    {
        scale(s);
        return *this;
    };

    inline Vec2 Vec2::operator/(const float s) const
    {
        return Vec2(this->x / s, this->y / s);
    };

    inline bool Vec2::operator==(const Vec2& v) const
    {
        return x == v.x && y == v.y
    };

    inline bool Vec2::operator!=(const Vec2& v) const
    {
        return x != v.x || y != v.y 
    };

    inline Vec2 operator*(float x, const Vec2& v)
    {
        Vec2 result(v);
        result.scale(x);
        return result;
    };

    inline bool operator < (const Vec2& rhs) const
    {
        if (x < rhs.x && y < rhs.y)
            return true;
        return false;
    };

    inline bool operator >(const Vec2& rhs) const
    {
        if (x > rhs.x && y > rhs.y)
            return true;
        return false;
    };

    inline bool Vec2::isZero() const
    {
        return x == 0.0f && y == 0.0f;
    };

    inline bool Vec2::isOne() const
    {
        return x == 1.0f && y == 1.0f;
    };


    inline Vec2 Vec2::lerp(const Vec2& target, float alpha) const
    {
        return *this * (1.f - alpha) + target * alpha;
    };

    inline void set(const float* array) {
        x = array[0];
        y = array[1];
    };

    inline void Vec2::set(const Vec2& p1, const Vec2& p2)
    {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    };

    inline void Vec2::set(float xx, float yy)
    {
        this->x = xx;
        this->y = yy;
    };

    inline void Vec2::add(const Vec2& v)
    {
        x += v.x;
        y += v.y;
    };

    inline void Vec2::add(float xx, float yy)
    {
        x += xx;
        y += yy;
    };

    inline void Vec2::scale(float scalar)
    {
        x *= scalar;
        y *= scalar;
    };


    inline void Vec2::setZero()
    {
        x = y  = 0.0f;
    };

    inline void Vec2::subtract(const Vec2& v)
    {
        x -= v.x;
        y -= v.y;
    };

    inline float Vec2::length() const
    {
        return std::sqrt(x * x + y * y );
    };

    inline float Vec2::lengthSquared() const
    {
        return (x * x + y * y );
    };

    inline void Vec2::negate()
    {
        x = -x;
        y = -y;
    };

    inline bool Vec2::equals(const Vec2& target) const
    {
        return (std::abs(this->x - target.x) < FLT_EPSILON)
            && (std::abs(this->y - target.y) < FLT_EPSILON);
    };

    inline bool Vec2::fuzzyEquals(const Vec2& b, float var) const
    {
        if (x - var <= b.x && b.x <= x + var)
            if (y - var <= b.y && b.y <= y + var)
                return true;
        return false;
    };

    void Vec2::normalize()
    {
        float n = x * x + y * y;
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
    };

    inline Vec2 Vec2::getNormalized() const
    {
        Vec2 v(*this);
        v.normalize();
        return v;
    };

    inline float Vec2::getAngle(const Vec2& other) const
    {
        Vec2 a2 = getNormalized();
        Vec2 b2 = other.getNormalized();
        float angle = atan2f(a2.cross(b2), a2.dot(b2));
        if (std::abs(angle) < FLT_EPSILON) return 0.f;
        return angle;
    };


    inline float Vec2::dot(const Vec2& v1, const Vec2& v2)
    {
        return (v1.x * v2.x + v1.y * v2.y);
    };


    inline float Vec2::distance(const Vec2& v) const
    {
        float dx = v.x - x;
        float dy = v.y - y;

        return std::sqrt(dx * dx + dy * dy);
    };

    inline void Vec2::clamp(const Vec2& v, const Vec2& min, const Vec2& max, Vec2* dst)
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
    };

    inline void Vec2::clamp(const Vec2& min, const Vec2& max)
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
    };

    inline float Vec2::angle(const Vec2& v1, const Vec2& v2)
    {
        float dz = v1.x * v2.y - v1.y * v2.x;
        return atan2f(fabsf(dz) + MATH_FLOAT_SMALL, dot(v1, v2));
    };

    // cross product of 2 vector. A->B X C->D
    float crossProduct2Vector(const Vec2& A, const Vec2& B, const Vec2& C, const Vec2& D)
    {
        return (D.y - C.y) * (B.x - A.x) - (D.x - C.x) * (B.y - A.y);
    };


    bool Vec2::isLineParallel(const Vec2& A, const Vec2& B,
        const Vec2& C, const Vec2& D)
    {
        // FAIL: Line undefined
        if ((A.x == B.x && A.y == B.y) || (C.x == D.x && C.y == D.y))
        {
            return false;
        }

        if (crossProduct2Vector(A, B, C, D) == 0)
        {
            // line overlap
            if (crossProduct2Vector(C, D, C, A) == 0 || crossProduct2Vector(A, B, C, A) == 0)
            {
                return false;
            }

            return true;
        }

        return false;
    };

    bool Vec2::isLineOverlap(const Vec2& A, const Vec2& B,
        const Vec2& C, const Vec2& D)
    {
        // FAIL: Line undefined
        if ((A.x == B.x && A.y == B.y) || (C.x == D.x && C.y == D.y))
        {
            return false;
        }

        if (crossProduct2Vector(A, B, C, D) == 0 &&
            (crossProduct2Vector(C, D, C, A) == 0 || crossProduct2Vector(A, B, C, A) == 0))
        {
            return true;
        }

        return false;
    };
    

    bool Vec2::isLineIntersect(const Vec2& A, const Vec2& B,
        const Vec2& C, const Vec2& D,
        float* S, float* T)
    {
        // FAIL: Line undefined
        if ((A.x == B.x && A.y == B.y) || (C.x == D.x && C.y == D.y))
        {
            return false;
        }

        const float denom = crossProduct2Vector(A, B, C, D);

        if (denom == 0)
        {
            // Lines parallel or overlap
            return false;
        }

        if (S != nullptr) *S = crossProduct2Vector(C, D, C, A) / denom;
        if (T != nullptr) *T = crossProduct2Vector(A, B, C, A) / denom;

        return true;
    };

    inline float Vec2::getAngle(const Vec2& other) const
    {
        Vec2 a2 = getNormalized();
        Vec2 b2 = other.getNormalized();
        float angle = atan2f(a2.cross(b2), a2.dot(b2));
        if (std::abs(angle) < FLT_EPSILON) return 0.f;
        return angle;
    };

    /** equals to Vec2(0,0) */
    static const Vec2 ZERO;
    /** equals to Vec2(1,1) */
    static const Vec2 ONE;
    /** equals to Vec2(1,0) */
    static const Vec2 UNIT_X;
    /** equals to Vec2(0,1) */
    static const Vec2 UNIT_Y;
    /** equals to Vec2(0.5, 0.5) */
    static const Vec2 ANCHOR_MIDDLE;
    /** equals to Vec2(0, 0) */
    static const Vec2 ANCHOR_BOTTOM_LEFT;
    /** equals to Vec2(0, 1) */
    static const Vec2 ANCHOR_TOP_LEFT;
    /** equals to Vec2(1, 0) */
    static const Vec2 ANCHOR_BOTTOM_RIGHT;
    /** equals to Vec2(1, 1) */
    static const Vec2 ANCHOR_TOP_RIGHT;
    /** equals to Vec2(1, 0.5) */
    static const Vec2 ANCHOR_MIDDLE_RIGHT;
    /** equals to Vec2(0, 0.5) */
    static const Vec2 ANCHOR_MIDDLE_LEFT;
    /** equals to Vec2(0.5, 1) */
    static const Vec2 ANCHOR_MIDDLE_TOP;
    /** equals to Vec2(0.5, 0) */
    static const Vec2 ANCHOR_MIDDLE_BOTTOM;

    ~Vec2() {};
};

const Vec2 Vec2::ZERO(0.0f, 0.0f);
const Vec2 Vec2::ONE(1.0f, 1.0f);
const Vec2 Vec2::UNIT_X(1.0f, 0.0f);
const Vec2 Vec2::UNIT_Y(0.0f, 1.0f);
const Vec2 Vec2::ANCHOR_MIDDLE(0.5f, 0.5f);
const Vec2 Vec2::ANCHOR_BOTTOM_LEFT(0.0f, 0.0f);
const Vec2 Vec2::ANCHOR_TOP_LEFT(0.0f, 1.0f);
const Vec2 Vec2::ANCHOR_BOTTOM_RIGHT(1.0f, 0.0f);
const Vec2 Vec2::ANCHOR_TOP_RIGHT(1.0f, 1.0f);
const Vec2 Vec2::ANCHOR_MIDDLE_RIGHT(1.0f, 0.5f);
const Vec2 Vec2::ANCHOR_MIDDLE_LEFT(0.0f, 0.5f);
const Vec2 Vec2::ANCHOR_MIDDLE_TOP(0.5f, 1.0f);
const Vec2 Vec2::ANCHOR_MIDDLE_BOTTOM(0.5f, 0.0f);