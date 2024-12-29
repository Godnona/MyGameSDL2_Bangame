#ifdef GAMEENGINE_API_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)  // Export to create DLL
#else
#define GAMEENGINE_API __declspec(dllimport)  // Import to use DLL
#endif

#ifndef INCLUDED_FORMAT
#define INCLUDED_FORMAT
#include <functional>
#include <memory>
#include <DirectXMath.h>
#include <wrl.h>

namespace BanZ
{
    typedef void* pPointer;
    typedef std::shared_ptr<void> SmartPointer;
    template <class T>
    T* GetFrom(SmartPointer cast)
    {
        return static_cast<T*>(cast.get());
    }
    template <class T>
    T* GetFrom(pPointer cast)
    {
        return static_cast<T*>(cast);
    }
    template <class T>
    pPointer SetTo(T* invCast)
    {
        return static_cast<pPointer>(invCast);
    }
    template <class T>
    std::shared_ptr<T> GetFromPoint(SmartPointer cast)
    {
        return std::static_pointer_cast<T>(cast);
    }
    template <class T>
    SmartPointer SetToPoint(std::shared_ptr<T> invCast)
    {
        return std::static_pointer_cast<void>(invCast);
    }


    extern "C" GAMEENGINE_API inline LPWSTR HRTrace(HRESULT hr);


    struct GAMEENGINE_API VECTOR4;
    struct GAMEENGINE_API VECTOR3;
    struct GAMEENGINE_API VECTOR2
    {
    public:
        VECTOR2();
        VECTOR2(float x, float y);
        VECTOR2(const VECTOR2& v);
        VECTOR2(const VECTOR3& v);
        VECTOR2(const VECTOR4& v);
        VECTOR2(DirectX::XMFLOAT2);
        ~VECTOR2();

        VECTOR2& operator=(const VECTOR2&);
        VECTOR2& operator=(const VECTOR3&);
        VECTOR2& operator+=(const VECTOR2&);
        VECTOR2& operator-=(const VECTOR2&);

        VECTOR2& operator*=(float);
        VECTOR2& operator/=(float);


        VECTOR2 operator+() const;
        VECTOR2 operator-() const;

        VECTOR2 operator+(const VECTOR2&) const;
        VECTOR2 operator-(const VECTOR2&) const;
        VECTOR2 operator/(const VECTOR2&) const;
        VECTOR2 operator*(const VECTOR3&);
        VECTOR2 operator*(float) const;
        friend VECTOR2 operator*(float, const VECTOR2&);
        VECTOR2 operator/(float) const;

        bool operator == (const VECTOR2&) const;
        bool operator != (const VECTOR2&) const;
        bool operator<(const VECTOR2&);

        float x, y;
    };




    struct GAMEENGINE_API VECTOR3
    {
    public:
        VECTOR3();
        VECTOR3(float x, float y, float z);
        VECTOR3(const VECTOR3& v);
        VECTOR3(const VECTOR4& v);
        VECTOR3(DirectX::XMFLOAT3);
        ~VECTOR3();

        VECTOR3& operator=(const VECTOR3& v);
        VECTOR3& operator=(const VECTOR4& v);
        VECTOR3& operator=(const float& v);

        VECTOR3& operator+=(const VECTOR3&);
        VECTOR3& operator-=(const VECTOR3&);

        VECTOR3& operator*=(float);
        VECTOR3& operator/=(float);

        VECTOR3 operator+() const;
        VECTOR3 operator-() const;

        VECTOR3 operator+(const VECTOR3&) const;
        VECTOR3 operator-(const VECTOR3&) const;
        VECTOR3 operator*(const VECTOR3&) const;
        VECTOR3 operator*(float) const;

        friend VECTOR3 operator*(float, const VECTOR3&);
        VECTOR3 operator/(float) const;

        bool operator == (const VECTOR3&) const;
        bool operator != (const VECTOR3&) const;
        bool operator != (const float&) const;

        VECTOR3(const VECTOR2& v);
        VECTOR3& operator=(const VECTOR2&);

        float x, y, z;
    };


    struct GAMEENGINE_API VECTOR4
    {
    public:
        VECTOR4();
        VECTOR4(float x, float y, float z, float w);
        VECTOR4(DirectX::XMFLOAT4);

        VECTOR4& operator+=(const VECTOR4&);
        VECTOR4& operator-=(const VECTOR4&);
        VECTOR4& operator+=(const VECTOR3&);
        VECTOR4& operator/=(const VECTOR2&);
        VECTOR4& operator=(const VECTOR3&);

        VECTOR4 operator-(const VECTOR4&) const;
        VECTOR4 operator*(const VECTOR4&) const;

        VECTOR4& operator*=(float);
        VECTOR4& operator/=(float);


        ~VECTOR4();

        float x, y, z, w;
    };

}
#endif // !INCLUDED_FORMAT

