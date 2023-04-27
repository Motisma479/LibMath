#pragma once
#include <cmath>

#define PRINT_FUNCTION

//-------USED_TO_ENABLE_CLASS-------
#define ENABLE_VEC2
#define ENABLE_IVEC2

#define ENABLE_VEC3
#define ENABLE_IVEC3

#define ENABLE_VEC4
#define ENABLE_IVEC4

#define ENABLE_MAT3

#define ENABLE_MAT4
//----------------------------------

namespace Maths
{
    constexpr float M_PI = 3.141592653589793238462643383279f;
    constexpr float DEG2RAD = M_PI / 180;
    constexpr float RAD2DEG = 180.f / M_PI;

// Vector Using float as Value
#ifdef ENABLE_VEC2
    class Vec2
    {
    public:
        //MEMBERS
        union
        {
            struct
            {
                float x, y;
            };
            float xy[2];
        };

        //CONSTRUCTORS
        inline Vec2(void);
        inline Vec2(float xy);
        inline Vec2(float x, float y);
#ifdef ENABLE_VEC3
        inline Vec2(const class Vec3& _Vec3);
#endif
#ifdef ENABLE_VEC4
        inline Vec2(const class Vec4& _Vec4);
#endif

        //DESTRUCTOR
        inline ~Vec2(void);

        //UTILS
        inline float GetMagnitude();
        inline void Normalize();
        inline Vec2 GetNormalized();
        inline float DotProduct(const Vec2& _VecB);
        static float DotProduct(const Vec2& _VecA, const Vec2& _VecB);

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Vec2 operator = (const Vec2& _Vec);
        inline Vec2 operator = (float _Sca);

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
        inline Vec2 operator + (float _Sca) const;
        inline Vec2 operator - (float _Sca) const;
        inline Vec2 operator * (float _Sca) const;
        inline Vec2 operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline Vec2 operator += (float _Sca);
        inline Vec2 operator -= (float _Sca);
        inline Vec2 operator *= (float _Sca);
        inline Vec2 operator /= (float _Sca);

#ifdef PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif //ENABLE_VEC2
#ifdef ENABLE_IVEC2
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

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif //ENABLE_IVEC2

#ifdef ENABLE_VEC3
    class Vec3
    {
    public:
        //MEMBERS
        union
        {
            struct
            {
                float x, y, z;
            };
            float xyz[3];
        };

        //CONSTRUCTORS
        inline Vec3(void);
        inline Vec3(float xyz);
        inline Vec3(float x, float y, float z);
#ifdef ENABLE_VEC2
        inline Vec3(const class Vec2& _Vec2);
        inline Vec3(const class Vec2& _Vec2, float z);
#endif
#ifdef ENABLE_VEC4
        inline Vec3(const class Vec4& _Vec4);
#endif

        //DESTRUCTOR
        inline ~Vec3(void);

        //UTILS

        inline Vec2 xy()	const;
        inline Vec2 xz()	const;
        inline Vec2 yz()	const;

        inline float GetMagnitude();
        inline void Normalize();
        inline Vec3 GetNormalized();
        inline float DotProduct(const Vec3& _VecB);
        static float DotProduct(const Vec3& _VecA, const Vec3& _VecB);
        inline Vec3 CrossProduct(const Vec3& _VecB);
        static Vec3 CrossProduct(const Vec3& _VecA, const Vec3& _VecB);

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Vec3 operator = (const Vec3& _Vec);
        inline Vec3 operator = (float _Sca);

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

        #ifdef PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif //ENABLE_VEC3
#ifdef ENABLE_IVEC3  
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

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif //ENABLE_IVEC3

#ifdef ENABLE_VEC4
    class Vec4
    {
    public:
        //MEMBERS
        union
        {
            struct
            {
                float x, y, z, w;
            };
            float xyzw[4];
        };

        //CONSTRUCTORS
        inline Vec4(void);
        inline Vec4(float xyzw);
        inline Vec4(float x, float y, float z, float w);
#ifdef ENABLE_VEC2
        inline Vec4(const class Vec2& _Vec2);
#endif
#ifdef ENABLE_VEC3
        inline Vec4(const class Vec3& _Vec3);
        inline Vec4(const class Vec3& _Vec3, float w);
#endif

        //DESTRUCTOR
        inline ~Vec4(void);

        //UTILS
        inline float GetMagnitude();
        inline void Normalize();
        inline Vec4 GetNormalized();
        inline float DotProduct(const Vec4& _VecB);
        static float DotProduct(const Vec4& _VecA, const Vec4& _VecB);
        inline Vec4 Homogenize();

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Vec4 operator = (const Vec4& _Vec);
        inline Vec4 operator = (float _Sca);

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
        inline Vec4 operator + (float _Sca) const;
        inline Vec4 operator - (float _Sca) const;
        inline Vec4 operator * (float _Sca) const;
        inline Vec4 operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS
        inline Vec4 operator += (float _Sca);
        inline Vec4 operator -= (float _Sca);
        inline Vec4 operator *= (float _Sca);
        inline Vec4 operator /= (float _Sca); 

        #ifdef PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif //ENABLE_VEC4
#ifdef ENABLE_IVEC4
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

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif //ENABLE_IVEC4


#ifdef ENABLE_MAT3
    class Mat3
    {
    public:
        //MEMBERS
        union
        {
            struct
            {
                float data[9];
            };
            Vec3 data3V[3];
            float data_3_3[3][3];
        };

        //CONSTRUCTORS
        inline Mat3(void);
        inline Mat3(float data[9]);

        //DESTRUCTOR
        inline ~Mat3(void);

        //UTILS

        //ASSINGMENT AND EQUALITY OPERATIONS
        inline Mat3 operator=(float _data[9]);
        inline Mat3 operator=(Mat3 _Mat);

        //Mat3 TO Mat3 OPERATIONS
        inline Mat3 operator+(Mat3 _Mat) const;
        inline Mat3 operator-(Mat3 _Mat) const;
        inline Mat3 operator*(Mat3 _Mat) const;

        //Mat3 TO THIS OPERATIONS
        inline Mat3 operator+=(Mat3 _Mat);
        inline Mat3 operator-=(Mat3 _Mat);
        inline Mat3 operator*=(Mat3 _Mat);

        #ifdef PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif // ENABLE_MAT3
#ifdef ENABLE_MAT4
    class Mat4
    {
    public:
        //MEMBERS
        union
        {
            struct
            {
                float data[16];
            };
            Vec4 data4V[4];
            float data_4_4[4][4];
        };

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

        #ifdef PRINT_FUNCTION
            void Print();
        #endif // PRINT_FUNCTION
    };
#endif // ENABLE_MAT4
}

#include "Maths.inl"