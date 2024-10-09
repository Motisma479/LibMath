/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 10/10/2024                      *
\***********************************************/
#pragma once


// Use if you make a dll with Visual Studio(msvc)
#ifdef MATHS_FOR_MSVC_DLL
    #ifdef DLL_EXPORTS
        #define MATHS_LIB_API __declspec(dllexport)
    #else
        #define MATHS_LIB_API __declspec(dllimport)
    #endif
#else
    #define MATHS_LIB_API
#endif


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

namespace Maths
{
    namespace Constants
    {
        constexpr float PI = 3.1415927f;
		constexpr float TAU = PI * 2.f;//TAU = 2PI

		constexpr float PI_2 = PI / 2.f;//PI/2
		constexpr float PI_3 = PI / 3.f;//PI/3
		constexpr float PI_4 = PI / 4.f;//PI/4
		constexpr float PI_6 = PI / 6.f;//PI/6
		constexpr float I_PI = 1.f / PI;//1/PI
		constexpr float I_TAU = 1.f / TAU;//1/2PI

		constexpr double PI_PRECISE = 3.141592653589793;

		constexpr float TOLERANCE = 3e-7f; //Use this rather than 0 comparison

		constexpr float DEG2RAD = PI / 180.f;
		constexpr double DEG2RAD_PRECISE = PI_PRECISE / 180.;

		constexpr float RAD2DEG = 180.f / PI;
		constexpr double RAD2DEG_PRECISE = 180. / PI_PRECISE;

    } 

    //-- Angle Conversion ----------------------------------------------

    inline float MATHS_LIB_API  ToRadians(float _angleDegrees);
    inline double MATHS_LIB_API ToRadians(double _angleDegrees);

    inline float MATHS_LIB_API ToDegrees(float _angleRadians);
    inline double MATHS_LIB_API ToDegrees(double _angleRadians);

    //------------------------------------------------------------------

#pragma region Vector

#ifndef DISABLE_VEC2
    class MATHS_LIB_API Vec2
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
        inline Vec2(float _xy);
        inline Vec2(float _x, float _y);
        inline Vec2(const class Vec3& _vec);
        inline Vec2(const class Vec4& _vec);

        //DESTRUCTOR :
        inline ~Vec2(void);

        //UTILS :
        inline float GetMagnitude()        const;
        inline float GetMagnitudeSquared() const;
        inline Vec2 GetNormalized()        const;
        inline Vec2 GetPerpendicular()     const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Vec2 operator = (const class Vec3& _vec);
		inline Vec2 operator = (const class Vec4& _vec);
        inline Vec2 operator = (float _sca);

        inline Vec2 operator - (void)              const;
        inline bool operator == (const Vec2& _vec) const;
        inline bool operator != (const Vec2& _vec) const;

        inline float operator [] (int _index) const;

        //Vec2 TO Vec2 OPERATIONS :
        inline Vec2 operator + (const Vec2& _vec) const;
        inline Vec2 operator - (const Vec2& _vec) const;

        //Vec2 TO THIS OPERATIONS :
        inline Vec2 operator += (const Vec2& _vec);
        inline Vec2 operator -= (const Vec2& _vec);

        //SCALER TO Vec2 OPERATIONS :
        inline Vec2 operator + (float _sca) const;
        inline Vec2 operator - (float _sca) const;
        inline Vec2 operator * (float _sca) const;
        inline Vec2 operator / (float _sca) const;

        //SCALER TO THIS OPERATIONS :
        inline Vec2 operator += (float _sca);
        inline Vec2 operator -= (float _sca);
        inline Vec2 operator *= (float _sca);
        inline Vec2 operator /= (float _sca);
    };
#endif

#ifndef DISABLE_VEC3
    class MATHS_LIB_API Vec3
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

        //STATIC MEMBERS :
        static const Vec3 UP;
		static const Vec3 DOWN;

		static const Vec3 LEFT;
		static const Vec3 RIGHT;

		static const Vec3 BACKWARD;
		static const Vec3 FORWARD;

        //CONSTRUCTORS :
        inline Vec3(void);
        inline Vec3(float _xyz);
        inline Vec3(float _x, float _y, float _z);
        inline Vec3(const class Vec2& _vec, float z = 0.f);
        inline Vec3(const class Vec4& _vec);

        //DESTRUCTOR :
        inline ~Vec3(void);

        //UTILS :
        inline Vec2 xy() const;
        inline Vec2 xz() const;
        inline Vec2 yz() const;

        inline float GetMagnitude()        const;
        inline float GetMagnitudeSquared() const;
        inline Vec3 GetNormalized()        const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Vec3 operator = (const class Vec2& _vec);
		inline Vec3 operator = (const class Vec4& _vec);
        inline Vec3 operator = (float _sca);

        inline Vec3 operator - (void)              const;
        inline bool operator == (const Vec3& _vec) const;
        inline bool operator != (const Vec3& _vec) const;

        inline float operator [] (int _index) const;

        //Vec3 TO Vec3 OPERATIONS :
        inline Vec3 operator + (const Vec3& _vec) const;
        inline Vec3 operator - (const Vec3& _vec) const;

        //Vec3 TO THIS OPERATIONS :
        inline Vec3 operator += (const Vec3& _vec);
        inline Vec3 operator -= (const Vec3& _vec);

        //SCALER TO Vec3 OPERATIONS :
        inline Vec3 operator + (float _sca) const;
        inline Vec3 operator - (float _sca) const;
        inline Vec3 operator * (float _sca) const;
        inline Vec3 operator / (float _sca) const;

        //SCALER TO THIS OPERATIONS :
        inline Vec3 operator += (float _sca);
        inline Vec3 operator -= (float _sca);
        inline Vec3 operator *= (float _sca);
        inline Vec3 operator /= (float _sca);
    };
#endif

#ifndef DISABLE_VEC4
    class MATHS_LIB_API Vec4
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
        inline Vec4(float _xyzw);
        inline Vec4(float _x, float _y, float _z, float _w);
        inline Vec4(const class Vec2& _vec, float _z = 0.f, float _w = 1.f);
		inline Vec4(const class Vec3& _vec, float _w = 1.f);

        //DESTRUCTOR :
        inline ~Vec4(void);

        //UTILS :
        inline Vec3 xyz() const;
        inline Vec3 xzw() const;
        inline Vec3 xyw() const;
        inline Vec3 yzw() const;

        inline float GetMagnitude()        const;
        inline float GetMagnitudeSquared() const;
        inline Vec4 GetNormalized()        const;
        inline Vec4 GetHomogenized()       const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Vec4 operator = (const class Vec2& _vec);
        inline Vec4 operator = (const class Vec3& _vec);
        inline Vec4 operator = (float _sca);

        inline Vec4 operator - (void)              const;
        inline bool operator == (const Vec4& _vec) const;
        inline bool operator != (const Vec4& _vec) const;

        inline float operator [] (int _index) const;

        //Vec4 TO Vec4 OPERATIONS
        inline Vec4 operator + (const Vec4& _vec) const;
        inline Vec4 operator - (const Vec4& _vec) const;

        //Vec4 TO THIS OPERATIONS
        inline Vec4 operator += (const Vec4& _vec);
        inline Vec4 operator -= (const Vec4& _vec);

        //SCALER TO Vec4 OPERATIONS
        inline Vec4 operator + (float _sca) const;
        inline Vec4 operator - (float _sca) const;
        inline Vec4 operator * (float _sca) const;
        inline Vec4 operator / (float _sca) const;

        //SCALER TO THIS OPERATIONS
        inline Vec4 operator += (float _sca);
        inline Vec4 operator -= (float _sca);
        inline Vec4 operator *= (float _sca);
        inline Vec4 operator /= (float _sca);
    };
#endif
    
    namespace Vectors
	{
        inline void MATHS_LIB_API Normalize(Vec2& _vec);
        inline void MATHS_LIB_API Normalize(Vec3& _vec);
        inline void MATHS_LIB_API Normalize(Vec4& _vec);

        inline float MATHS_LIB_API DotProduct(const Vec2& _vecA, const Vec2& _vecB);
        inline float MATHS_LIB_API DotProduct(const Vec3& _vecA, const Vec3& _vecB);
        inline float MATHS_LIB_API DotProduct(const Vec4& _vecA, const Vec4& _vecB);

        inline float MATHS_LIB_API DistanceBetween(const Vec2& _vecA, const Vec2& _vecB);
        inline float MATHS_LIB_API DistanceBetween(const Vec3& _vecA, const Vec3& _vecB);
        inline float MATHS_LIB_API DistanceBetween(const Vec4& _vecA, const Vec4& _vecB);

        inline float MATHS_LIB_API AngleBetween(const Vec2& _vecA, const Vec2& _vecB);
        inline float MATHS_LIB_API AngleBetween(const Vec3& _vecA, const Vec3& _vecB);
        inline float MATHS_LIB_API AngleBetween(const Vec4& _vecA, const Vec4& _vecB);

        //return the z value
        inline float MATHS_LIB_API CrossProduct(const Vec2& _vecA, const Vec2& _vecB);

        inline Vec3 MATHS_LIB_API CrossProduct(const Vec3& _vecA, const Vec3& _vecB);
        inline Vec3 MATHS_LIB_API Rotate(const Vec3& _vec, float _angle, const Vec3& _axis);
    }

#pragma endregion Vector

#pragma region Matrix

#ifndef DISABLE_MAT3
    class MATHS_LIB_API Mat3
    {
    public:
        //MEMBERS :
        union
        {
            float data[9];
            Vec3 data3V[3];
            float data_3_3[3][3];
        };

        //CONSTRUCTORS :
        inline Mat3(void);
        inline Mat3(float _data[9]);
        inline Mat3(float _identityValue);
        inline Mat3(float _0, float _1, float _2,
			        float _3, float _4, float _5,
			        float _6, float _7, float _8);
        inline Mat3(const class Mat4& _mat);

        //DESTRUCTOR :
        inline ~Mat3(void);

        //UTILS :
        inline static Mat3 Rotate2D(float _angleInRad);
        inline static Mat3 Translate2D(const Vec2& _translation);
        inline static Mat3 Scale2D(const Vec2& _scaling);
        inline static Mat3 Transform(const Vec2& _translation, float _angleInRad, const Vec2& _scaling);

        inline Mat3 GetTranspose()    const;
        inline Mat3 GetInverse()      const;
        inline float GetDeterminant() const;
        inline float GetTrace()       const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Mat3 operator = (float _data[9]);
        inline Mat3 operator = (const Mat4& _mat);

        inline Mat3 operator - (void)              const;
        inline bool operator == (const Mat3& _mat) const;
		inline bool operator != (const Mat3& _mat) const;

        inline Vec3 operator [] (int _index) const;

        //Mat3 TO Mat3 OPERATIONS :
        inline Mat3 operator + (const Mat3& _mat) const;
        inline Mat3 operator - (const Mat3& _mat) const;
        inline Mat3 operator * (const Mat3& _mat) const;

        //Mat3 TO THIS OPERATIONS :
        inline Mat3 operator += (const Mat3& _mat);
        inline Mat3 operator -= (const Mat3& _mat);
        inline Mat3 operator *= (const Mat3& _mat);

        //Sca TO Mat3 OPERATIONS :
		inline Mat3 operator * (float _sca) const;
		inline Mat3 operator / (float _sca) const;

		//Sca TO This OPERATIONS :
		inline Mat3 operator *= (float _sca);
		inline Mat3 operator /= (float _sca);

        //Mat3 TO Vec2 OPERATIONS :
		inline Vec2 operator * (const Vec2& _vec) const;

		//Mat3 TO Vec3 OPERATIONS :
		inline Vec3 operator * (const Vec3& _vec) const;
    };
#endif

#ifndef DISABLE_MAT4
    class MATHS_LIB_API Mat4
    {
    public:
        //MEMBERS :
        union
        {
            float data[16];
            Vec4 data4V[4];
            float data_4_4[4][4];
        };

        //CONSTRUCTORS :
        inline Mat4(void);
        inline Mat4(float _data[16]);
        inline Mat4(float _indentityValue);
		inline Mat4(float _0, float _1, float _2, float _3,
			        float _4, float _5, float _6, float _7,
			        float _8, float _9, float _10, float _11,
			        float _12, float _13, float _14, float _15);
        inline Mat4(const Mat3& _mat);

        //DESTRUCTOR :
        inline ~Mat4(void);

        //UTILS :
        inline static Mat4 Translate(const Vec3& _translation);
        inline static Mat4 Rotate(const Vec3& _anglesInRad);
        inline static Mat4 RotateX(float _angleInRad);
		inline static Mat4 RotateY(float _angleInRad);
		inline static Mat4 RotateZ(float _angleInRad);
        inline static Mat4 Scale(const Vec3& _scale);
        inline static Mat4 Transform(const Vec3& _translation, const Vec3& _anglesInRad, const Vec3& _scale);
        inline static Mat4 Transform(const Vec3& _translation, const class Quat& _anglesInRad, const Vec3& _scale);

        inline Mat4 GetTranspose()    const;
        inline Mat4 GetInverse()      const;
        inline float GetDeterminant() const;
        inline float GetTrace()       const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Mat4 operator = (float _data[16]);
        inline Mat4 operator = (const Mat3& _mat);

        inline Mat4 operator - (void) const;
		inline bool operator == (const Mat4& _mat) const;
		inline bool operator != (const Mat4& _mat) const;

        inline Vec4 operator [] (int _index) const;

        //Mat4 TO Mat4 OPERATIONS :
        inline Mat4 operator + (const Mat4& _mat) const;
        inline Mat4 operator - (const Mat4& _mat) const;
        inline Mat4 operator * (const Mat4& _mat) const;

        //Mat4 TO THIS OPERATIONS :
        inline Mat4 operator += (const Mat4& _mat);
        inline Mat4 operator -= (const Mat4& _mat);
        inline Mat4 operator *= (const Mat4& _mat);

        //Sca TO Mat4 OPERATIONS :
		inline Mat4 operator * (float _sca) const;
		inline Mat4 operator / (float _sca) const;

		//Sca TO This OPERATIONS :
		inline Mat4 operator *= (float _sca);
		inline Mat4 operator /= (float _sca);

		//Mat3 TO Vec3 OPERATIONS :
		inline Vec3 operator * (const Vec3& _vec) const;

		//Mat3 TO Vec4 OPERATIONS :
		inline Vec4 operator * (const Vec4& _vec) const;
    };
#endif

// #ifdef ENABLE_MATYX
//     template<unsigned int row, unsigned int col>
//     class MatXY
//     {
//     public:
//         union
//         {
//             struct
//             {
//                 float data[row * col];
//             };
//             float __data[col][row];
//         };
//
//         //CONSTRUCTORS :
//
//         inline MatXY(void)
//         {
//             for (unsigned int i = 0; i < row * col; i++)
//                 data[i] = 0;
//         }
//         // intit a matrix of y by x 
//         inline MatXY(float _data[row * col])
//         {
//             for (unsigned int i = 0; i < row * col; i++)
//                 data[i] = _data[i];
//         }
//
//         //DESTRUCTOR :
//
//         inline ~MatXY(void) {}
//
// #ifdef PRINT_FUNCTION
//         inline void Print()
//         {
//             std::cout << this << " Value :" << std::endl;
//             std::cout << "--------------------" << std::endl;
//
//             for (unsigned int y = 0; y < row; y++)
//             {
//                 std::cout << '[';
//                 for (unsigned int x = 0; x < col; x++)
//                 {
//                     std::cout << ' ' << __data[x][y] << ' ';
//                 }
//                 std::cout << ']' << std::endl;
//             }
//
//             std::cout << "Order:" << std::endl;
//             std::cout << '[';
//             for (unsigned int i = 0; i < row * col; i++)
//             {
//
//                 std::cout << ' ' << data[i] << ' ';
//             }
//             std::cout << ']' << std::endl;
//             std::cout << "--------------------" << std::endl;
//         }
// #endif // PRINT_FUNCTION
//     };
// #endif

    namespace matrixes
	{
        inline Mat3 MATHS_LIB_API Transpose(Mat3& _mat);
        inline Mat4 MATHS_LIB_API Transpose(Mat4& _mat);

        inline Mat3 MATHS_LIB_API Inverse(Mat3& _mat);
        inline Mat4 MATHS_LIB_API Inverse(Mat4& _mat);

        inline Mat4 MATHS_LIB_API Frustum(float _left, float _right, float _bottom, float _top, float _nearVal, float _farVal);
	    inline Mat4 MATHS_LIB_API Ortho(float _left, float _right, float _bottom, float _top, float _nearVal, float _farVal);
	    inline Mat4 MATHS_LIB_API LookAt(float _eyeX, float _eyeY, float _eyeZ, float _centerX, float _centerY, float _centerZ, float _upX, float _upY, float _upZ);
	    inline Mat4 MATHS_LIB_API LookAt(Vec3 _eyeZ, Vec3 _centerZ, Vec3 _upZ);
	    inline Mat4 MATHS_LIB_API LookAt(Vec3 _forward, Vec3 _localUp);
	    inline Mat4 MATHS_LIB_API LookAtNormalized(Vec3 _forward, Vec3 _localUp);
	    inline Mat4 MATHS_LIB_API LookAtNormalized(Vec3 _eye, Vec3 _center, Vec3 _up);
	    inline Mat4 MATHS_LIB_API Perspective(float _fovY, float _aspect, float _near, float _far);
    }

#pragma endregion Matrix

//     // Complex number ------------------------------------------------------------------------------------------
// #ifndef  DISABLE_COMP
//     class Comp
//     {
//         //MEMBERS :
//
//         union
//         {
//             struct
//             {
//                 float x, iy;
//             };
//             float x_iy[2];
//         };
//
//         //CONSTRUCTORS :
//
//         inline Comp(void);
//         inline Comp(float x, float iy);
//
//         //DESTRUCTOR :
//
//         inline ~Comp(void);
//
//         //UTILS :
//
//         inline void Conjugate();
//         inline Comp GetConjugate() const;
//
//         //ASSINGMENT AND EQUALITY OPERATIONS :
//
//         inline Comp operator = (const Comp& _Comp);
//
//         inline Comp operator - (void)               const;
//         inline bool operator == (const Comp& _Comp) const;
//         inline bool operator != (const Comp& _Comp) const;
//
//         //Comp TO Comp OPERATIONS :
//
//         inline Comp operator + (const Comp& _Comp) const;
//         inline Comp operator - (const Comp& _Comp) const;
//         inline Comp operator * (const Comp& _Comp) const;
//         inline Comp operator / (const Comp& _Comp) const;
//
//         //Comp TO THIS OPERATIONS :
//
//         inline Comp operator += (const Comp& _Comp);
//         inline Comp operator -= (const Comp& _Comp);
//         inline Comp operator *= (const Comp& _Comp);
//         inline Comp operator /= (const Comp& _Comp);
//
//         //SCALER TO Comp OPERATIONS :
//
//         inline Comp operator * (float _Sca) const;
//         inline Comp operator / (float _Sca) const;
//
//         //SCALER TO THIS OPERATIONS :
//
//         inline Comp operator *= (float _Sca);
//         inline Comp operator /= (float _Sca);
//
// #ifdef PRINT_FUNCTION
//         void Print() const;
// #endif // PRINT_FUNCTION
//     };
// #endif

#pragma region Quaternion

#ifndef DISABLE_QUAT
    class MATHS_LIB_API Quat
    {
    public:
        //MEMBERS :
        union
        {
            struct
			{
				float real;
				Vec3 imaginary;
			};
            struct
            {
                float w, x, y, z;
            };
            float wxyz[4];
            Vec4 vec;
        };

        //CONSTRUCTORS :
        inline Quat(void);
        inline Quat(const Vec4& _vec);
        inline Quat(float _w, float _x, float _y, float _z);
        inline Quat(float _w, const Vec3& _imaginary);
        inline Quat(const Vec3& _vector);

        //DESTRUCTOR :
        inline ~Quat(void);

        //UTILS :
        inline static Quat Identity();

        inline float GetMagnitudeSquared() const;
		inline float GetMagnitude() const;
        inline Quat GetNormalized() const;
		inline Quat GetConjugate() const;

        //CARE: can cause approximation errors if too many successive operation, use GetInversePrecise, if needed
		inline Quat GetInverse() const;

		//More precise, but a bit slower(4%), prefer GetInverse if you don't have to invert over and over the same quaternion
		inline Quat GetInversePrecise() const;

        inline static Quat Nlerp(const Quat& _start, const Quat& _end, float _ratio);
		inline static Quat Slerp(const Quat& _q1, const Quat& _q2, float _t);

        //CONVERSION
		inline Vec3 RotateVector(const Vec3& _vec) const;
		inline Mat3 ToRotationMatrix();

        //Credits to Timboc on https://forum.unity.com/threads/is-there-a-conversion-method-from-quaternion-to-euler.624007/
		inline Vec3 ToEulerAngles() const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Quat operator = (const Quat& _Quat);
        
        inline Quat operator - (void)               const;
        inline bool operator == (const Quat& _Quat) const; //TODO: Test is precision check is needed
        inline bool operator != (const Quat& _Quat) const; //TODO: Test is precision check is needed


        //Quat TO Quat OPERATIONS :
        inline Quat operator + (const Quat& _Quat) const;
        inline Quat operator - (const Quat& _Quat) const;
        inline Quat operator * (const Quat& _Quat) const;
        //inline Quat operator / (const Quat& _Quat) const; //TODO: will be added if needed later or if requested

        //Quat TO THIS OPERATIONS :
        inline Quat operator += (const Quat& _Quat);
        inline Quat operator -= (const Quat& _Quat);
        inline Quat operator *= (const Quat& _Quat);
        //inline Quat operator /= (const Quat& _Quat); //TODO: will be added if needed later or if requested

        //SCALER TO Quat OPERATIONS :
        inline Quat operator * (float _Sca) const;
        inline Quat operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS :
        inline Quat operator *= (float _Sca);
        inline Quat operator /= (float _Sca);
    };

    namespace Quaternions
	{
		inline float DotProduct(const Quat& _q1, const Quat& _q2);
		// in radians
		inline Quat MATHS_LIB_API FromAngleAxis(float _angle, const Vec3& _axis);
		inline Quat MATHS_LIB_API LookAt(const Vec3 _from, const Vec3 _to);
		inline Quat MATHS_LIB_API FromEulerAngles(const Vec3& _xyz);
		inline Quat MATHS_LIB_API FromMatrix(const Mat3& _matrix);
		inline Quat MATHS_LIB_API FromMatrix(const Mat4& _matrix);
	}

#endif

#pragma endregion Quaternion

}

#include "Maths.inl"