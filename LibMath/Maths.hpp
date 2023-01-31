#pragma once
#include <cmath>

#define PRINT_FUNCTION true

//-------USED_TO_ENABLE_CLASS-------
#define ENABLE_VEC2 true
#define ENABLE_IVEC2 true

#define ENABLE_VEC3 true
#define ENABLE_IVEC3 true

#define ENABLE_VEC4 true
#define ENABLE_IVEC4 true

#define ENABLE_MAT3 true

#define ENABLE_MAT4 true
//----------------------------------

#define PI_NUM 3.141592653589793238462643383279f
#define DEG2RAD PI_NUM/180

namespace Maths
{
// Vector Using float as Value
#if ENABLE_VEC2
    class Vec2
    {
    public:
        //MEMBERS
        float x, y;

        //CONSTRUCTORS
        inline Vec2(void);
        inline Vec2(const float xy);
        inline Vec2(const float x, const float y);
        inline Vec2(const Vec2& _Vec2);
#if ENABLE_VEC3
        inline Vec2(const class Vec3& _Vec3);
#endif
#if ENABLE_VEC4
        inline Vec2(const class Vec4& _Vec4);
#endif

        //DESTRUCTOR
        inline ~Vec2(void);

        //UTILS
        inline float GetMagnitude();
        inline void Normalize();
        inline float DotProduct(const Vec2& _VecB);
        static float DotProduct(const Vec2& _VecA, const Vec2& _VecB);
        inline float* ToFloat2();

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Vec2 operator = (const Vec2& _Vec);
        inline Vec2 operator = (const float _Sca);

        inline Vec2 operator - (void)               const;
        inline bool operator == (const Vec2& _Vec)  const;
        inline bool operator != (const Vec2& _Vec)  const;

        //Vec2 TO Vec2 OPERATIONS
        inline Vec2 operator + (const Vec2& _Vec)   const;
        inline Vec2 operator - (const Vec2& _Vecv)  const;
        inline Vec2 operator * (const Vec2& _Vec)   const;
        inline Vec2 operator / (const Vec2& _Vec)   const;

        //Vec2 TO THIS OPERATIONS
        inline Vec2 operator += (const Vec2& _Vec);
        inline Vec2 operator -= (const Vec2& _Vec);
        inline Vec2 operator *= (const Vec2& _Vec);
        inline Vec2 operator /= (const Vec2& _Vec);

        //SCALER TO Vec2 OPERATIONS
        inline Vec2 operator + (const float _Sca) const;
        inline Vec2 operator - (const float _Sca) const;
        inline Vec2 operator * (const float _Sca) const;
        inline Vec2 operator / (const float _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline Vec2 operator += (const float _Sca);
        inline Vec2 operator -= (const float _Sca);
        inline Vec2 operator *= (const float _Sca);
        inline Vec2 operator /= (const float _Sca);

        #if PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif //ENABLE_VEC2
#if ENABLE_IVEC2
    class IVec2
    {
    public:
        //MEMBERS
        int x, y;

        //CONSTRUCTORS
        inline IVec2(void);
        inline IVec2(const int xy);
        inline IVec2(const int x, const int y);
        inline IVec2(const IVec2& _IVec2);

        //DESTRUCTOR
        inline ~IVec2(void);

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline IVec2 operator = (const IVec2& _IVec);
        inline IVec2 operator = (const int _Sca);

        inline IVec2 operator - (void)               const;
        inline bool operator == (const IVec2& _IVec)  const;
        inline bool operator != (const IVec2& _IVec)  const;

        //Vec2 TO Vec2 OPERATIONS
        inline IVec2 operator + (const IVec2& _IVec)   const;
        inline IVec2 operator - (const IVec2& _IVec)  const;
        inline IVec2 operator * (const IVec2& _IVec)   const;
        inline IVec2 operator / (const IVec2& _IVec)   const;

        //Vec2 TO THIS OPERATIONS
        inline IVec2 operator += (const IVec2& _IVec);
        inline IVec2 operator -= (const IVec2& _IVec);
        inline IVec2 operator *= (const IVec2& _IVec);
        inline IVec2 operator /= (const IVec2& _IVec);

        //SCALER TO Vec2 OPERATIONS
        inline IVec2 operator + (const int _Sca) const;
        inline IVec2 operator - (const int _Sca) const;
        inline IVec2 operator * (const int _Sca) const;
        inline IVec2 operator / (const int _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline IVec2 operator += (const int _Sca);
        inline IVec2 operator -= (const int _Sca);
        inline IVec2 operator *= (const int _Sca);
        inline IVec2 operator /= (const int _Sca);

#if PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif //ENABLE_IVEC2

#if ENABLE_VEC3
    class Vec3
    {
    public:
        //MEMBERS
        float x, y, z;

        //CONSTRUCTORS
        inline Vec3(void);
        inline Vec3(const float xyz);
        inline Vec3(const float x, const float y, const float z);
#if ENABLE_VEC2
        inline Vec3(const class Vec2& _Vec2);
#endif
        inline Vec3(const Vec3& _Vec3);
#if ENABLE_VEC4
        inline Vec3(const class Vec4& _Vec4);
#endif

        //DESTRUCTOR
        inline ~Vec3(void);

        //UTILS

        inline float GetMagnitude();
        inline void Normalize();
        inline float DotProduct(const Vec3& _VecB);
        static float DotProduct(const Vec3& _VecA, const Vec3& _VecB);
        inline float* ToFloat3();
        inline Vec3 CrossProduct(const Vec3& _VecA, const Vec3& _VecB);

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Vec3 operator = (const Vec3& _Vec);
        inline Vec3 operator = (const float _Sca);

        inline Vec3 operator - (void)              const;
        inline bool operator == (const Vec3& _Vec) const;
        inline bool operator != (const Vec3& _Vec) const;

        //Vec3 TO Vec3 OPERATIONS
        inline Vec3 operator + (const Vec3& _Vec) const;
        inline Vec3 operator - (const Vec3& _Vec) const;
        inline Vec3 operator * (const Vec3& _Vec) const;
        inline Vec3 operator / (const Vec3& _Vec) const;

        //Vec3 TO THIS OPERATIONS
        inline Vec3 operator += (const Vec3& _Vec);
        inline Vec3 operator -= (const Vec3& _Vec);
        inline Vec3 operator *= (const Vec3& _Vec);
        inline Vec3 operator /= (const Vec3& _Vec);

        //SCALER TO Vec3 OPERATIONS
        inline Vec3 operator + (float _Sca) const;
        inline Vec3 operator - (float _Sca) const;
        inline Vec3 operator * (float _Sca) const;
        inline Vec3 operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline Vec3 operator += (float _Sca);
        inline Vec3 operator -= (float _Sca);
        inline Vec3 operator *= (float _Sca);
        inline Vec3 operator /= (float _Sca);

        #if PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif //ENABLE_VEC3
#if ENABLE_IVEC3  
    class IVec3
    {
    public:
        //MEMBERS
        int x, y, z;

        //CONSTRUCTORS
        inline IVec3(void);
        inline IVec3(const int xyz);
        inline IVec3(const int x, const int y, const int z);
        inline IVec3(const IVec3& _IVec3);

        //DESTRUCTOR
        inline ~IVec3(void);

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline IVec3 operator = (const IVec3& _IVec);
        inline IVec3 operator = (const int _Sca);

        inline IVec3 operator - (void)               const;
        inline bool operator == (const IVec3& _IVec)  const;
        inline bool operator != (const IVec3& _IVec)  const;

        //Vec2 TO Vec2 OPERATIONS
        inline IVec3 operator + (const IVec3& _IVec)   const;
        inline IVec3 operator - (const IVec3& _IVec)  const;
        inline IVec3 operator * (const IVec3& _IVec)   const;
        inline IVec3 operator / (const IVec3& _IVec)   const;

        //Vec2 TO THIS OPERATIONS
        inline IVec3 operator += (const IVec3& _IVec);
        inline IVec3 operator -= (const IVec3& _IVec);
        inline IVec3 operator *= (const IVec3& _IVec);
        inline IVec3 operator /= (const IVec3& _IVec);

        //SCALER TO Vec2 OPERATIONS
        inline IVec3 operator + (const int _Sca) const;
        inline IVec3 operator - (const int _Sca) const;
        inline IVec3 operator * (const int _Sca) const;
        inline IVec3 operator / (const int _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline IVec3 operator += (const int _Sca);
        inline IVec3 operator -= (const int _Sca);
        inline IVec3 operator *= (const int _Sca);
        inline IVec3 operator /= (const int _Sca);

#if PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif //ENABLE_IVEC3

#if ENABLE_VEC4
    class Vec4
    {
    public:
        //MEMBERS
        float x, y, z, w;

        //CONSTRUCTORS
        inline Vec4(void);
        inline Vec4(const float xyzw);
        inline Vec4(const float x, const float y, const float z, const float w);
#if ENABLE_VEC2
        inline Vec4(const class Vec2& _Vec2);
#endif
#if ENABLE_VEC3
        inline Vec4(const class Vec3& _Vec3);
        inline Vec4(const class Vec3& _Vec3, float w);
#endif
        inline Vec4(const Vec4& _Vec4);

        //DESTRUCTOR
        inline ~Vec4(void);

        //UTILS
        inline float GetMagnitude();
        inline void Normalize();
        inline float DotProduct(const Vec4& _VecB);
        static float DotProduct(const Vec4& _VecA, const Vec4& _VecB);
        inline float* ToFloat4();
        inline Vec4 Homogenize();

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Vec4 operator = (const Vec4& _Vec);
        inline Vec4 operator = (const float _Sca);

        inline Vec4 operator - (void)               const;
        inline bool operator == (const Vec4& _Vec)  const;
        inline bool operator != (const Vec4& _Vec)  const;
        inline bool operator >= (int v) {
            return (x >= v || y >= v || z >= v || w >= v);
        }

        //Vec4 TO Vec4 OPERATIONS
        inline Vec4 operator + (const Vec4& _Vec) const;
        inline Vec4 operator - (const Vec4& _Vec) const;
        inline Vec4 operator * (const Vec4& _Vec) const;
        inline Vec4 operator / (const Vec4& _Vec) const;

        //Vec4 TO THIS OPERATIONS
        inline Vec4 operator += (const Vec4& _Vec);
        inline Vec4 operator -= (const Vec4& _Vec);
        inline Vec4 operator *= (const Vec4& _Vec);
        inline Vec4 operator /= (const Vec4& _Vec);

        //SCALER TO Vec4 OPERATIONS
        inline Vec4 operator + (const float _Sca) const;
        inline Vec4 operator - (const float _Sca) const;
        inline Vec4 operator * (const float _Sca) const;
        inline Vec4 operator / (const float _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline Vec4 operator += (const float _Sca);
        inline Vec4 operator -= (const float _Sca);
        inline Vec4 operator *= (const float _Sca);
        inline Vec4 operator /= (const float _Sca); 

        #if PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif //ENABLE_VEC4
#if ENABLE_IVEC4
    class IVec4
    {
    public:
        //MEMBERS
        int x, y, z, w;

        //CONSTRUCTORS
        inline IVec4(void);
        inline IVec4(const int xyzw);
        inline IVec4(const int x, const int y, const int z, const int w);
        inline IVec4(const IVec4& _IVec4);

        //DESTRUCTOR
        inline ~IVec4(void);

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline IVec4 operator = (const IVec4& _IVec);
        inline IVec4 operator = (const int _Sca);

        inline IVec4 operator - (void)               const;
        inline bool operator == (const IVec4& _IVec)  const;
        inline bool operator != (const IVec4& _IVec)  const;

        //Vec2 TO Vec2 OPERATIONS
        inline IVec4 operator + (const IVec4& _IVec)   const;
        inline IVec4 operator - (const IVec4& _IVec)  const;
        inline IVec4 operator * (const IVec4& _IVec)   const;
        inline IVec4 operator / (const IVec4& _IVec)   const;

        //Vec2 TO THIS OPERATIONS
        inline IVec4 operator += (const IVec4& _IVec);
        inline IVec4 operator -= (const IVec4& _IVec);
        inline IVec4 operator *= (const IVec4& _IVec);
        inline IVec4 operator /= (const IVec4& _IVec);

        //SCALER TO Vec2 OPERATIONS
        inline IVec4 operator + (const int _Sca) const;
        inline IVec4 operator - (const int _Sca) const;
        inline IVec4 operator * (const int _Sca) const;
        inline IVec4 operator / (const int _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline IVec4 operator += (const int _Sca);
        inline IVec4 operator -= (const int _Sca);
        inline IVec4 operator *= (const int _Sca);
        inline IVec4 operator /= (const int _Sca);

#if PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif //ENABLE_IVEC4


#if ENABLE_MAT3
    class Mat3
    {
    public:
        //MEMBERS
        float data[9];

        //CONSTRUCTORS
        inline Mat3(void);
        inline Mat3(float p_data[9]);
        inline Mat3(const Mat3& _Mat3);

        //DESTRUCTOR
        inline ~Mat3(void);

        //UTILS
        inline void Print(const char* desc);

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Mat3 operator=(Mat3 _Mat);

        //Mat3 TO Mat3 OPERATIONS
        inline Mat3 operator+(Mat3 _Mat) const;
        inline Mat3 operator-(Mat3 _Mat) const;
        inline Mat3 operator*(Mat3 _Mat) const;

        //Mat3 TO THIS OPERATIONS
        inline Mat3 operator+=(Mat3 _Mat);
        inline Mat3 operator-=(Mat3 _Mat);
        inline Mat3 operator*=(Mat3 _Mat);

        #if PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif // ENABLE_MAT3
#if ENABLE_MAT4
    class Mat4
    {
    public:
        //MEMBERS
        float data[4][4];

        //CONSTRUCTORS
        inline Mat4(void);
        inline Mat4(float* p_data, long int sizeOfData);

        //DESTRUCTOR
        inline ~Mat4(void);

        //UTILS
        inline Mat4 GetIdentity(Mat4 identity);
        inline float* GetData();

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Mat4 operator=(float p_newData[16]);
        inline Mat4 operator=(Mat4 _Mat);

        //Mat4 TO Mat4 OPERATIONS
        inline Mat4 operator+(Mat4 _Mat) const;
        inline Mat4 operator-(Mat4 _Mat) const;
        inline Mat4 operator*(Mat4 _Mat) const;
        
        //Mat4 TO THIS OPERATIONS
        inline Mat4 operator+=(Mat4 _Mat);
        inline Mat4 operator-=(Mat4 _Mat);
        inline Mat4 operator*=(Mat4 _Mat);

        #if PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif // ENABLE_MAT4
}

#include "Maths.inl"