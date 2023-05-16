/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 16/05/2023                      *
\***********************************************/
#pragma once

//--------USED_TO_ENABLE_PRINT_FUNCTIONS--------

#define PRINT_FUNCTION

//------------USED_TO_DISABLE_CLASS-------------

//#define DISABLE_VEC2
//#define DISABLE_VEC3
//#define DISABLE_VEC4

//#define DISABLE_IVEC2
//#define DISABLE_IVEC3
//#define DISABLE_IVEC4

//#define DISABLE_MAT3
//#define DISABLE_MAT4

//---USED_TO_ENABLE_CLASS_DISABLED_BY_DEFAULT---

//#define ENABLE_MATYX

//----------------------------------------------

#if defined(ENABLE_MATYX) && defined(PRINT_FUNCTION)
#include <iostream>
#endif


namespace Maths
{
    constexpr float M_PI = 3.14159265358979323846f;
    //multiply your angle in degrees by this value to convert it to radians.
    constexpr float DEG2RAD = M_PI / 180;
    //multiply your angle in radians by this value to convert it to degrees.
    constexpr float RAD2DEG = 180.f / M_PI;

    // Vector Using float as Value -----------------------------------------------------------------------------
#ifndef DISABLE_VEC2
    class Vec2
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                float x, y;
            };
            float xy[2];
        };

        //CONSTRUCTORS :

        inline Vec2(void);
        inline Vec2(float xy);
        inline Vec2(float x, float y);
#ifndef DISABLE_VEC3
        inline Vec2(const class Vec3& _Vec3);
#endif
#ifndef DISABLE_VEC4
        inline Vec2(const class Vec4& _Vec4);
#endif

        //DESTRUCTOR :

        inline ~Vec2(void);

        //UTILS :

        inline float GetMagnitude()                                          const;
        inline void Normalize();
        inline Vec2 GetNormalized()                                          const;
        inline float DotProduct(const Vec2& _VecB)                           const;
        inline static float DotProduct(const Vec2& _VecA, const Vec2& _VecB);
        inline float GetLength()                                             const;
        inline float LenghtSquared()                                         const;

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline Vec2 operator = (const Vec2& _Vec);
        inline Vec2 operator = (float _Sca);

        inline Vec2 operator - (void)              const;
        inline bool operator == (const Vec2& _Vec) const;
        inline bool operator != (const Vec2& _Vec) const;

        //Vec2 TO Vec2 OPERATIONS :

        inline Vec2 operator + (const Vec2& _Vec)  const;
        inline Vec2 operator - (const Vec2& _Vecv) const;
        inline Vec2 operator * (const Vec2& _Vec)  const;
        inline Vec2 operator / (const Vec2& _Vec)  const;

        //Vec2 TO THIS OPERATIONS :

        inline Vec2 operator += (const Vec2& _Vec);
        inline Vec2 operator -= (const Vec2& _Vec);
        inline Vec2 operator *= (const Vec2& _Vec);
        inline Vec2 operator /= (const Vec2& _Vec);

        //SCALER TO Vec2 OPERATIONS :

        inline Vec2 operator + (float _Sca) const;
        inline Vec2 operator - (float _Sca) const;
        inline Vec2 operator * (float _Sca) const;
        inline Vec2 operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS :

        inline Vec2 operator += (float _Sca);
        inline Vec2 operator -= (float _Sca);
        inline Vec2 operator *= (float _Sca);
        inline Vec2 operator /= (float _Sca);

#ifdef PRINT_FUNCTION
        void Print() const;
#endif // PRINT_FUNCTION
    };
#endif

#ifndef DISABLE_VEC3
    class Vec3
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                float x, y, z;
            };
            float xyz[3];
        };

        //CONSTRUCTORS :

        inline Vec3(void);
        inline Vec3(float xyz);
        inline Vec3(float x, float y, float z);
#ifndef DISABLE_VEC2
        inline Vec3(const class Vec2& _Vec2);
        inline Vec3(const class Vec2& _Vec2, float z);
#endif
#ifndef DISABLE_VEC4
        inline Vec3(const class Vec4& _Vec4);
#endif

        //DESTRUCTOR :

        inline ~Vec3(void);

        //UTILS :

        inline Vec2 xy() const;
        inline Vec2 xz() const;
        inline Vec2 yz() const;

        inline float GetMagnitude()                                          const;
        inline void Normalize();
        inline Vec3 GetNormalized()                                          const;
        inline float DotProduct(const Vec3& _VecB)                           const;
        inline static float DotProduct(const Vec3& _VecA, const Vec3& _VecB);
        inline Vec3 CrossProduct(const Vec3& _VecB)                          const;
        static Vec3 CrossProduct(const Vec3& _VecA, const Vec3& _VecB);
        inline float GetLength()                                             const;
        inline float LenghtSquared()                                         const;

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline Vec3 operator = (const Vec3& _Vec);
        inline Vec3 operator = (float _Sca);

        inline Vec3 operator - (void)              const;
        inline bool operator == (const Vec3& _Vec) const;
        inline bool operator != (const Vec3& _Vec) const;

        //Vec3 TO Vec3 OPERATIONS :

        inline Vec3 operator + (const Vec3& _Vec) const;
        inline Vec3 operator - (const Vec3& _Vec) const;
        inline Vec3 operator * (const Vec3& _Vec) const;
        inline Vec3 operator / (const Vec3& _Vec) const;

        //Vec3 TO THIS OPERATIONS :

        inline Vec3 operator += (const Vec3& _Vec);
        inline Vec3 operator -= (const Vec3& _Vec);
        inline Vec3 operator *= (const Vec3& _Vec);
        inline Vec3 operator /= (const Vec3& _Vec);

        //SCALER TO Vec3 OPERATIONS :

        inline Vec3 operator + (float _Sca) const;
        inline Vec3 operator - (float _Sca) const;
        inline Vec3 operator * (float _Sca) const;
        inline Vec3 operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS :

        inline Vec3 operator += (float _Sca);
        inline Vec3 operator -= (float _Sca);
        inline Vec3 operator *= (float _Sca);
        inline Vec3 operator /= (float _Sca);

#ifdef PRINT_FUNCTION
        void Print() const;
#endif // PRINT_FUNCTION
    };
#endif

#ifndef DISABLE_VEC4
    class Vec4
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                float x, y, z, w;
            };
            float xyzw[4];
        };

        //CONSTRUCTORS :

        inline Vec4(void);
        inline Vec4(float xyzw);
        inline Vec4(float x, float y, float z, float w);
#ifndef DISABLE_VEC2
        inline Vec4(const class Vec2& _Vec2);
#endif
#ifndef DISABLE_VEC3
        inline Vec4(const class Vec3& _Vec3);
        inline Vec4(const class Vec3& _Vec3, float w);
#endif

        //DESTRUCTOR :

        inline ~Vec4(void);

        //UTILS :

        inline Vec3 xyz() const;
        inline Vec3 xzw() const;
        inline Vec3 xyw() const;
        inline Vec3 yzw() const;


        inline float GetMagnitude()                                          const;
        inline void Normalize();
        inline Vec4 GetNormalized()                                          const;
        inline float DotProduct(const Vec4& _VecB)                           const;
        inline static float DotProduct(const Vec4& _VecA, const Vec4& _VecB);
        inline void Homogenize();
        inline Vec4 GetHomogenized()                                         const;
        inline float GetLength()                                             const;
        inline float LenghtSquared()                                         const;

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline Vec4 operator = (const Vec4& _Vec);
        inline Vec4 operator = (float _Sca);

        inline Vec4 operator - (void)              const;
        inline bool operator == (const Vec4& _Vec) const;
        inline bool operator != (const Vec4& _Vec) const;

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
#endif

    // Vector Using int as Value -------------------------------------------------------------------------------
#ifndef DISABLE_IVEC2
    class IVec2
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                int x, y;
            };
            int xy[2];
        };

        //CONSTRUCTORS :

        inline IVec2(void);
        inline IVec2(int xy);
        inline IVec2(int x, int y);
#ifndef DISABLE_VEC2
        inline IVec2(const class Vec2& _Vec2);
#endif
        //DESTRUCTOR :

        inline ~IVec2(void);

        //UTILS :

        inline float GetLength()     const;
        inline int LenghtSquared() const;

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline IVec2 operator = (const IVec2& _IVec);
        inline IVec2 operator = (int _Sca);

        inline IVec2 operator - (void)               const;
        inline bool operator == (const IVec2& _IVec) const;
        inline bool operator != (const IVec2& _IVec) const;

        //Vec2 TO Vec2 OPERATIONS :

        inline IVec2 operator + (const IVec2& _IVec) const;
        inline IVec2 operator - (const IVec2& _IVec) const;
        inline IVec2 operator * (const IVec2& _IVec) const;
        inline IVec2 operator / (const IVec2& _IVec) const;

        //Vec2 TO THIS OPERATIONS :

        inline IVec2 operator += (const IVec2& _IVec);
        inline IVec2 operator -= (const IVec2& _IVec);
        inline IVec2 operator *= (const IVec2& _IVec);
        inline IVec2 operator /= (const IVec2& _IVec);

        //SCALER TO Vec2 OPERATIONS :

        inline IVec2 operator + (int _Sca) const;
        inline IVec2 operator - (int _Sca) const;
        inline IVec2 operator * (int _Sca) const;
        inline IVec2 operator / (int _Sca) const;

        //SCALER TO THIS OPERATIONS :

        inline IVec2 operator += (int _Sca);
        inline IVec2 operator -= (int _Sca);
        inline IVec2 operator *= (int _Sca);
        inline IVec2 operator /= (int _Sca);

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif

#ifndef DISABLE_IVEC3  
    class IVec3
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                int x, y, z;
            };
            int xyz[3];
        };

        //CONSTRUCTORS :

        inline IVec3(void);
        inline IVec3(int xyz);
        inline IVec3(int x, int y, int z);
#ifndef DISABLE_VEC3
        inline IVec3(const class Vec3& _Vec3);
#endif

        //DESTRUCTOR :

        inline ~IVec3(void);

        //UTILS :

        inline float GetLength()     const;
        inline int LenghtSquared() const;

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline IVec3 operator = (const IVec3& _IVec);
        inline IVec3 operator = (const int _Sca);

        inline IVec3 operator - (void)               const;
        inline bool operator == (const IVec3& _IVec) const;
        inline bool operator != (const IVec3& _IVec) const;

        //Vec2 TO Vec2 OPERATIONS :

        inline IVec3 operator + (const IVec3& _IVec) const;
        inline IVec3 operator - (const IVec3& _IVec) const;
        inline IVec3 operator * (const IVec3& _IVec) const;
        inline IVec3 operator / (const IVec3& _IVec) const;

        //Vec2 TO THIS OPERATIONS :

        inline IVec3 operator += (const IVec3& _IVec);
        inline IVec3 operator -= (const IVec3& _IVec);
        inline IVec3 operator *= (const IVec3& _IVec);
        inline IVec3 operator /= (const IVec3& _IVec);

        //SCALER TO Vec2 OPERATIONS :

        inline IVec3 operator + (int _Sca) const;
        inline IVec3 operator - (int _Sca) const;
        inline IVec3 operator * (int _Sca) const;
        inline IVec3 operator / (int _Sca) const;

        //SCALER TO THIS OPERATIONS :

        inline IVec3 operator += (int _Sca);
        inline IVec3 operator -= (int _Sca);
        inline IVec3 operator *= (int _Sca);
        inline IVec3 operator /= (int _Sca);

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif

#ifndef DISABLE_IVEC4
    class IVec4
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                int x, y, z, w;
            };
            int xyzw[4];
        };

        //CONSTRUCTORS :

        inline IVec4(void);
        inline IVec4(int xyzw);
        inline IVec4(int x, int y, int z, int w);
#ifndef DISABLE_VEC4
        inline IVec4(const class Vec4& _Vec4);
#endif

        //DESTRUCTOR :

        inline ~IVec4(void);

        //UTILS :

        inline float GetLength()     const;
        inline int LenghtSquared() const;

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline IVec4 operator = (const IVec4& _IVec);
        inline IVec4 operator = (int _Sca);

        inline IVec4 operator - (void)               const;
        inline bool operator == (const IVec4& _IVec) const;
        inline bool operator != (const IVec4& _IVec) const;

        //Vec2 TO Vec2 OPERATIONS :

        inline IVec4 operator + (const IVec4& _IVec) const;
        inline IVec4 operator - (const IVec4& _IVec) const;
        inline IVec4 operator * (const IVec4& _IVec) const;
        inline IVec4 operator / (const IVec4& _IVec) const;

        //Vec2 TO THIS OPERATIONS :

        inline IVec4 operator += (const IVec4& _IVec);
        inline IVec4 operator -= (const IVec4& _IVec);
        inline IVec4 operator *= (const IVec4& _IVec);
        inline IVec4 operator /= (const IVec4& _IVec);

        //SCALER TO Vec2 OPERATIONS :

        inline IVec4 operator + (int _Sca) const;
        inline IVec4 operator - (int _Sca) const;
        inline IVec4 operator * (int _Sca) const;
        inline IVec4 operator / (int _Sca) const;

        //SCALER TO THIS OPERATIONS :

        inline IVec4 operator += (int _Sca);
        inline IVec4 operator -= (int _Sca);
        inline IVec4 operator *= (int _Sca);
        inline IVec4 operator /= (int _Sca);

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif

    // Matrix --------------------------------------------------------------------------------------------------
#ifndef DISABLE_MAT3
    class Mat3
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                float data[9];
            };
#ifndef DISABLE_VEC3
            Vec3 data3V[3];
#endif
            float data_3_3[3][3];
        };

        //CONSTRUCTORS :

        inline Mat3(void);
        inline Mat3(float data[9]);

        //DESTRUCTOR :

        inline ~Mat3(void);

        //UTILS :

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline Mat3 operator=(float _data[9]);
        inline Mat3 operator=(const Mat3& _Mat);

        //Mat3 TO Mat3 OPERATIONS :

        inline Mat3 operator+(const Mat3& _Mat) const;
        inline Mat3 operator-(const Mat3& _Mat) const;
        inline Mat3 operator*(const Mat3& _Mat) const;

        //Mat3 TO THIS OPERATIONS :

        inline Mat3 operator+=(const Mat3& _Mat);
        inline Mat3 operator-=(const Mat3& _Mat);
        inline Mat3 operator*=(const Mat3& _Mat);

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif

#ifndef DISABLE_MAT4
    class Mat4
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                float data[16];
            };
#ifndef DISABLE_VEC4
            Vec4 data4V[4];
#endif
            float data_4_4[4][4];
        };

        //CONSTRUCTORS :

        inline Mat4(void);
        inline Mat4(float _data[16]);

        //DESTRUCTOR :

        inline ~Mat4(void);

        //UTILS :

        //inline Mat4 GetIdentity(const Mat4& identity);

        //ASSINGMENT AND EQUALITY OPERATIONS :

        inline Mat4 operator=(float _data[16]);
        inline Mat4 operator=(const Mat4& _Mat);

        //Mat4 TO Mat4 OPERATIONS :

        inline Mat4 operator+(const Mat4& _Mat) const;
        inline Mat4 operator-(const Mat4& _Mat) const;
        inline Mat4 operator*(const Mat4& _Mat) const;

        //Mat4 TO THIS OPERATIONS :

        inline Mat4 operator+=(const Mat4& _Mat);
        inline Mat4 operator-=(const Mat4& _Mat);
        inline Mat4 operator*=(const Mat4& _Mat);

#ifdef PRINT_FUNCTION
        void Print();
#endif // PRINT_FUNCTION
    };
#endif

#ifdef ENABLE_MATYX
    template<unsigned int row, unsigned int col>
    class MatXY
    {
    public:
        union
        {
            struct
            {
                float data[row * col];
            };
            float __data[col][row];
        };

        //CONSTRUCTORS :

        inline MatXY(void)
        {
            for (unsigned int i = 0; i < row * col; i++)
                data[i] = 0;
        }
        // intit a matrix of y by x 
        inline MatXY(float _data[row * col])
        {
            for (unsigned int i = 0; i < row * col; i++)
                data[i] = _data[i];
        }

        //DESTRUCTOR :

        inline ~MatXY(void) {}

#ifdef PRINT_FUNCTION
        inline void Print()
        {
            std::cout << this << " Value :" << std::endl;
            std::cout << "--------------------" << std::endl;

            for (unsigned int y = 0; y < row; y++)
            {
                std::cout << '[';
                for (unsigned int x = 0; x < col; x++)
                {
                    std::cout << ' ' << __data[x][y] << ' ';
                }
                std::cout << ']' << std::endl;
            }

            std::cout << "Order:" << std::endl;
            std::cout << '[';
            for (unsigned int i = 0; i < row * col; i++)
            {

                std::cout << ' ' << data[i] << ' ';
            }
            std::cout << ']' << std::endl;
            std::cout << "--------------------" << std::endl;
        }
#endif // PRINT_FUNCTION
    };
#endif


}

#include "Maths.inl"