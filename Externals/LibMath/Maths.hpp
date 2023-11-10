/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 18/09/2023                      *
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

//#define DISABLE_COMP

//#define DISABLE_QUAT

//---USED_TO_ENABLE_CLASS_DISABLED_BY_DEFAULT---

#define ENABLE_MATYX

//----------------------------------------------

#if defined(ENABLE_MATYX) && defined(PRINT_FUNCTION)
#include <iostream>
#endif


namespace Maths
{
    
    //multiply your angle in degrees by this value to convert it to radians.
    template <class T>
    inline float ToRadians(T angleDegrees);
    //multiply your angle in radians by this value to convert it to degrees.
    template <class T>
    inline float ToDegrees(T angleRadians);

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
        inline float GetMagnitudeSquared()                                   const;
        inline void Normalize();
        inline Vec2 GetNormalized()                                          const;
        inline Vec2 GetPerpendicular()                                       const;
        inline float DotProduct(const Vec2& _VecB)                           const;
        inline static float DotProduct(const Vec2& _VecA, const Vec2& _VecB);
        inline float GetDistance(const Vec2& _VecB)                          const;
        inline static float GetDistance(const Vec2& _VecA, const Vec2& _VecB);
        inline float GetAngleBetween(const Vec2& _VecB)                      const;
        inline static float GetAngleBetween(const Vec2& _VecA, const Vec2& _VecB);


        //ASSIGNMENT AND EQUALITY OPERATIONS :

        inline Vec2 operator = (const Vec2& _Vec);
        inline Vec2 operator = (float _Sca);

        inline Vec2 operator - (void)              const;
        inline bool operator == (const Vec2& _Vec) const;
        inline bool operator != (const Vec2& _Vec) const;

        //Vec2 TO Vec2 OPERATIONS :

        inline Vec2 operator + (const Vec2& _Vec)  const;
        inline Vec2 operator - (const Vec2& _Vec)  const;
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
        inline float GetMagnitudeSquared()                                   const;
        inline void Normalize();
        inline Vec3 GetNormalized()                                          const;
        inline float DotProduct(const Vec3& _VecB)                           const;
        inline static float DotProduct(const Vec3& _VecA, const Vec3& _VecB);
        inline Vec3 CrossProduct(const Vec3& _VecB)                          const;
        static Vec3 CrossProduct(const Vec3& _VecA, const Vec3& _VecB);
        inline float GetDistance(const Vec3& _VecB)                          const;
        inline static float GetDistance(const Vec3& _VecA, const Vec3& _VecB);
        inline float GetAngleBetween(const Vec3& _VecB)                      const;
        inline static float GetAngleBetween(const Vec3& _VecA, const Vec3& _VecB);

        //ASSIGNMENT AND EQUALITY OPERATIONS :

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
        inline float GetMagnitudeSquared()                                   const;
        inline void Normalize();
        inline Vec4 GetNormalized()                                          const;
        inline float DotProduct(const Vec4& _VecB)                           const;
        inline static float DotProduct(const Vec4& _VecA, const Vec4& _VecB);
        inline void Homogenize();
        inline Vec4 GetHomogenized()                                         const;

        //ASSIGNMENT AND EQUALITY OPERATIONS :

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
        void Print() const;
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

        inline float GetMagnitude()     const;
        inline int GetMagnitudeSquared() const;

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
        void Print() const;
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

        inline float GetMagnitude()     const;
        inline int GetMagnitudeSquared() const;

        //ASSIGNMENT AND EQUALITY OPERATIONS :

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
        void Print() const;
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

        inline float GetMagnitude()     const;
        inline int GetMagnitudeSquared() const;

        //ASSIGNMENT AND EQUALITY OPERATIONS :

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
        void Print() const;
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

        inline void Transpose();
        inline static Mat3 GetTranspose(const Mat3& _Mat);
        inline float Determinant()                                                                                 const;
        inline void Inverse();
        inline static Mat3 GetInverse(const Mat3& _Mat);
        inline float Trace()                                                                                       const;

        inline static Mat3 CreateIdentityMatrix();
        inline static Mat3 CreateRotationMatrix(float rotation);
#ifndef DISABLE_VEC2
        inline static Mat3 CreateTranslationMatrix(const Vec2& translation);
        inline static Mat3 CreateScaleMatrix(const Vec2& scale);
        inline static Mat3 CreateTransformMatrix(const Vec2& translation, float rotation, const Vec2& scale);
#else
        inline static Mat3 CreateTranslationMatrix(float[2] translation);
        inline static Mat3 CreateScaleMatrix(float[2] scale);
        inline static Mat3 CreateTransformMatrix(float[2] translation, float rotation, float[2] scale);
#endif

        inline Mat3 HadamardProduct(const Mat3& _Mat)                                                              const;
        inline Mat3 HadamardProductToThis(const Mat3& _Mat);

        //ASSIGNMENT AND EQUALITY OPERATIONS :

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
        void Print() const;
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

        inline void Transpose();
        inline static Mat4 GetTranspose(const Mat4& _Mat);
        inline float Determinant()                                                                                 const;
        inline void Inverse();
        inline static Mat4 GetInverse(const Mat4& _Mat);
        inline float Trace()                                                                                       const;

        inline static Mat4 CreateIdentityMatrix();
        inline static Mat4 CreateXRotationMatrix(float x);
        inline static Mat4 CreateYRotationMatrix(float y);
        inline static Mat4 CreateZRotationMatrix(float z);
#ifndef DISABLE_VEC3
        inline static Mat4 CreateTranslationMatrix(const Vec3& translation);
        inline static Mat4 CreateRotationMatrix(const Vec3& rotation);
        inline static Mat4 CreateScaleMatrix(const Vec3& scale);
        inline static Mat4 CreateTransformMatrix(const Vec3& translation, const Vec3& rotation, const Vec3& scale);
#else
        inline static Mat4 CreateTranslationMatrix(float[3] translation);
        inline static Mat4 CreateRotationMatrix(float[3] rotation);
        inline static Mat4 CreateScaleMatrix(float[3] scale);
        inline static Mat4 CreateTransformMatrix(float[3] translation, float[3] rotation, float[3] scale);
#endif


        //ASSIGNMENT AND EQUALITY OPERATIONS :

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
        void Print() const;
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

    // Complex number ------------------------------------------------------------------------------------------
#ifndef  DISABLE_COMP
    class Comp
    {
        //MEMBERS :

        union
        {
            struct
            {
                float x, iy;
            };
            float x_iy[2];
        };

        //CONSTRUCTORS :

        inline Comp(void);
        inline Comp(float x, float iy);

        //DESTRUCTOR :

        inline ~Comp(void);

        //UTILS :

        inline void Conjugate();
        inline Comp GetConjugate() const;

        //ASSIGNMENT AND EQUALITY OPERATIONS :

        inline Comp operator = (const Comp& _Comp);

        inline Comp operator - (void)               const;
        inline bool operator == (const Comp& _Comp) const;
        inline bool operator != (const Comp& _Comp) const;

        //Comp TO Comp OPERATIONS :

        inline Comp operator + (const Comp& _Comp) const;
        inline Comp operator - (const Comp& _Comp) const;
        inline Comp operator * (const Comp& _Comp) const;
        inline Comp operator / (const Comp& _Comp) const;

        //Comp TO THIS OPERATIONS :

        inline Comp operator += (const Comp& _Comp);
        inline Comp operator -= (const Comp& _Comp);
        inline Comp operator *= (const Comp& _Comp);
        inline Comp operator /= (const Comp& _Comp);

        //SCALER TO Comp OPERATIONS :

        inline Comp operator * (float _Sca) const;
        inline Comp operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS :

        inline Comp operator *= (float _Sca);
        inline Comp operator /= (float _Sca);

#ifdef PRINT_FUNCTION
        void Print() const;
#endif // PRINT_FUNCTION
    };
#endif

    // Quaternion ----------------------------------------------------------------------------------------------
#ifndef DISABLE_QUAT
    class Quat
    {
    public:
        //MEMBERS :

        union
        {
            struct
            {
                float x, y, z, w; // R : w; I : x, y, z
            };
            float xyzw[4];
        };

        //CONSTRUCTORS :

        inline Quat(void);
        inline Quat(float x, float y, float z, float w);
        
        inline Quat(const Vec3& axis, float angle);

        //DESTRUCTOR :

        inline ~Quat(void);

        //UTILS :

        // inline void Normalize();

        // inline Quat AxisAngle(const Vec3& axis, float angle);

        // inline static Quat CreateFromEuler(const Vec3& _VecRotation);
        // inline static Quat CreateFromRadians(const Vec3& _VecRotation);
        // inline static Quat CreateFromMatrix(const Mat4& _MatRotation);

        // inline Mat4 ToMatrix() const;

        //ASSIGNMENT AND EQUALITY OPERATIONS :
        inline Quat operator = (const Quat& _Quat);

        inline Quat operator - (void)               const;
        inline bool operator == (const Quat& _Quat) const;
        inline bool operator != (const Quat& _Quat) const;


        //Quat TO Quat OPERATIONS :
        inline Quat operator + (const Quat& _Quat) const;
        inline Quat operator - (const Quat& _Quat) const;
        inline Quat operator * (const Quat& _Quat) const;
        inline Quat operator / (const Quat& _Quat) const;

        //Quat TO THIS OPERATIONS :
        inline Quat operator += (const Quat& _Quat);
        inline Quat operator -= (const Quat& _Quat);
        inline Quat operator *= (const Quat& _Quat);
        inline Quat operator /= (const Quat& _Quat);


#ifdef PRINT_FUNCTION
        void Print() const;
#endif // PRINT_FUNCTION
    };
#endif

}

#include "Maths.inl"