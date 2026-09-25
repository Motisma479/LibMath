/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 01/09/2026                      *
\***********************************************/
#pragma once
#include <limits>

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

//---USED_TO_ENABLE_CLASS_AND_FEATURE_DISABLED_BY_DEFAULT---

//#define ENABLE_MATYX   need to be implemented
//#define ENABLE_SWIZZLE

//----------------------------------------------------------

#ifdef ENABLE_SWIZZLE
#define SWIZZLE_MIXER_2_DECLARATION(a, b)\
inline Maths::Vec2 a##b();\
inline Maths::Vec2 b##a();\
\
inline Maths::Vec3 a##b##b();\
inline Maths::Vec3 a##b##a();\
inline Maths::Vec3 b##b##a();\
inline Maths::Vec3 b##a##a();\
inline Maths::Vec3 b##a##b();\
\
inline Maths::Vec4 a##a##a##b();\
inline Maths::Vec4 a##a##b##b();\
inline Maths::Vec4 a##b##b##b();\
inline Maths::Vec4 a##b##a##a();\
inline Maths::Vec4 a##b##a##b();\
inline Maths::Vec4 a##b##b##a();\
inline Maths::Vec4 a##a##b##a();\
inline Maths::Vec4 b##b##b##a();\
inline Maths::Vec4 b##b##a##a();\
inline Maths::Vec4 b##a##a##a();\
inline Maths::Vec4 b##a##b##b();\
inline Maths::Vec4 b##a##b##a();\
inline Maths::Vec4 b##a##a##b();\
inline Maths::Vec4 b##b##a##b();

#define SWIZZLE_MIXER_3_DECLARATION(a, b, c)\
inline Maths::Vec3 a##b##c();\
inline Maths::Vec3 b##a##c();\
inline Maths::Vec3 c##a##b();\
inline Maths::Vec3 a##c##b();\
inline Maths::Vec3 b##c##a();\
inline Maths::Vec3 c##b##a();\
\
inline Maths::Vec4 a##b##c##a();\
inline Maths::Vec4 a##b##c##b();\
inline Maths::Vec4 a##b##c##c();\
inline Maths::Vec4 b##a##c##a();\
inline Maths::Vec4 b##a##c##b();\
inline Maths::Vec4 b##a##c##c();\
inline Maths::Vec4 c##a##b##a();\
inline Maths::Vec4 c##a##b##b();\
inline Maths::Vec4 c##a##b##c();\
inline Maths::Vec4 a##c##b##a();\
inline Maths::Vec4 a##c##b##b();\
inline Maths::Vec4 a##c##b##c();\
inline Maths::Vec4 b##c##a##a();\
inline Maths::Vec4 b##c##a##b();\
inline Maths::Vec4 b##c##a##c();\
inline Maths::Vec4 c##b##a##a();\
inline Maths::Vec4 c##b##a##b();\
inline Maths::Vec4 c##b##a##c();\
inline Maths::Vec4 a##a##b##c();\
inline Maths::Vec4 a##a##c##b();\
inline Maths::Vec4 a##b##a##c();\
inline Maths::Vec4 a##b##b##c();\
inline Maths::Vec4 a##c##a##b();\
inline Maths::Vec4 a##c##c##b();\
inline Maths::Vec4 b##a##a##c();\
inline Maths::Vec4 b##a##b##c();\
inline Maths::Vec4 b##b##a##c();\
inline Maths::Vec4 b##b##c##a();\
inline Maths::Vec4 b##c##b##a();\
inline Maths::Vec4 b##c##c##a();\
inline Maths::Vec4 c##a##a##b();\
inline Maths::Vec4 c##a##c##b();\
inline Maths::Vec4 c##b##b##a();\
inline Maths::Vec4 c##b##c##a();\
inline Maths::Vec4 c##c##a##b();\
inline Maths::Vec4 c##c##b##a();

#define SWIZZLE_MIXER_4_DECLARATION(a, b, c, d)\
inline Maths::Vec4 a##b##c##d();\
inline Maths::Vec4 b##a##c##d();\
inline Maths::Vec4 c##a##b##d();\
inline Maths::Vec4 a##c##b##d();\
inline Maths::Vec4 b##c##a##d();\
inline Maths::Vec4 c##b##a##d();\
inline Maths::Vec4 c##b##d##a();\
inline Maths::Vec4 b##c##d##a();\
inline Maths::Vec4 d##c##b##a();\
inline Maths::Vec4 c##d##b##a();\
inline Maths::Vec4 b##d##c##a();\
inline Maths::Vec4 d##b##c##a();\
inline Maths::Vec4 d##a##c##b();\
inline Maths::Vec4 c##d##a##b();\
inline Maths::Vec4 d##c##a##b();\
inline Maths::Vec4 a##c##d##b();\
inline Maths::Vec4 c##a##d##b();\
inline Maths::Vec4 b##a##d##c();\
inline Maths::Vec4 a##b##d##c();\
inline Maths::Vec4 d##b##a##c();\
inline Maths::Vec4 b##d##a##c();\
inline Maths::Vec4 a##d##b##c();\
inline Maths::Vec4 d##a##b##c();\

#define SWIZZLE_DUPLICATE_DECLARATION(a)\
inline Maths::Vec2 a##a();\
inline Maths::Vec3 a##a##a();\
inline Maths::Vec4 a##a##a##a();

//--SWIZZLE_2----------------------------
#define SWIZZLE_2_DECLARATION(a, b) \
SWIZZLE_DUPLICATE_DECLARATION(a)\
SWIZZLE_DUPLICATE_DECLARATION(b)\
\
SWIZZLE_MIXER_2_DECLARATION(a,b)

//--SWIZZLE_3----------------------------
#define SWIZZLE_3_DECLARATION(a, b, c)\
SWIZZLE_2_DECLARATION(a,b)\
SWIZZLE_DUPLICATE_DECLARATION(c)\
\
SWIZZLE_MIXER_2_DECLARATION(a,c)\
SWIZZLE_MIXER_2_DECLARATION(b,c)\
\
SWIZZLE_MIXER_3_DECLARATION(a,b,c)

//--SWIZZLE_4----------------------------
#define SWIZZLE_4_DECLARATION(a, b, c, d) \
SWIZZLE_3_DECLARATION(a,b,c)\
SWIZZLE_DUPLICATE_DECLARATION(d)\
\
SWIZZLE_MIXER_2_DECLARATION(a,d)\
SWIZZLE_MIXER_2_DECLARATION(b,d)\
SWIZZLE_MIXER_2_DECLARATION(c,d)\
\
SWIZZLE_MIXER_3_DECLARATION(a,b,d)\
SWIZZLE_MIXER_3_DECLARATION(a,c,d)\
SWIZZLE_MIXER_3_DECLARATION(b,c,d)\
\
SWIZZLE_MIXER_4_DECLARATION(a,b,c,d)
#endif

namespace Maths
{
    namespace Constants
    {
        constexpr double PI_PRECISE = 3.14159265358979323846;

        constexpr float PI = 3.14159265358979323846f;
		constexpr float TAU = PI * 2.f;//TAU = 2PI
        
		constexpr float PI_2 = PI / 2.f;//PI/2
		constexpr float PI_3 = PI / 3.f;//PI/3
		constexpr float PI_4 = PI / 4.f;//PI/4
		constexpr float PI_6 = PI / 6.f;//PI/6
		constexpr float I_PI = 1.f / PI;//1/PI
		constexpr float I_TAU = 1.f / TAU;//1/2PI
        
		constexpr float TOLERANCE = 3e-7f; //Use this rather than 0 comparison
        
		constexpr double DEG2RAD_PRECISE = 0.01745329251994329577;
		constexpr float DEG2RAD = 0.01745329251994329577f;
        
		constexpr double RAD2DEG_PRECISE = 57.29577951308232087680;
        constexpr float RAD2DEG = 57.29577951308232087680f;

        constexpr float INF = std::numeric_limits<float>::infinity();
        constexpr double INF_PRECISE = std::numeric_limits<double>::infinity();
    } 

    //-- Angle Conversion ----------------------------------------------

    inline float MATHS_LIB_API  ToRadians(float _angleDegrees);
    inline double MATHS_LIB_API ToRadians(double _angleDegrees);

    inline float MATHS_LIB_API ToDegrees(float _angleRadians);
    inline double MATHS_LIB_API ToDegrees(double _angleRadians);

    //------------------------------------------------------------------

#pragma region Vector
    class MATHS_LIB_API Vec2;
    class MATHS_LIB_API Vec3;
    class MATHS_LIB_API Vec4;

    

    class MATHS_LIB_API Vec2
    {
    public:
        //MEMBERS :
        /**
         * @brief Storage for the vector's components.
         *
         * The named components (x, y) and the array form (xy) occupy the same
         * memory, so modifying one is reflected in the other.
         */
        union
        {
            /**
             * @brief Named access to the components.
             */
            struct
            {
                float x; /**< X component. */
                float y; /**< Y component. */
            };

            /**
             * @brief Array access: xy[0] = x, xy[1] = y.
             * @note No bounds check are performed; check @ref operator[] for bound checked acess.
             */
            float xy_raw[2];
        };

#ifdef ENABLE_SWIZZLE
        SWIZZLE_2_DECLARATION(x,y)
#endif

        //CONSTRUCTORS :
        /**
         * @brief Default constructor.
         * 
         * Initializes x and y to 0
         */
        inline Vec2(void);
        /**
         * @brief Constructs a vector with equal components.
         * @param _xy Value assigned to both x and y.
         */
        inline Vec2(float _xy);
        /**
         * @brief Constructs a vector from individual components.
         * @param _x Value assigned to x.
         * @param _y Value assigned to y.
         */
        inline Vec2(float _x, float _y);
        /**
         * @brief Constructs a vector from a @ref Vec3, discarding the z component.
         * @param _vec Source Vec3 whose x and y are copied.
         * @note The z component of @p _vec is ignored.
         */
        inline Vec2(const class Vec3& _vec);
        /**
         * @brief Constructs a vector from a @ref Vec4, discarding the z and w components.
         * @param _vec Source Vec4 whose x and y are copied.
         * @note The z and w components of @p _vec are ignored.
         */
        inline Vec2(const class Vec4& _vec);

        //DESTRUCTOR :
        inline ~Vec2(void);

        //UTILS :
        /**
         * @brief Computes the magnitude (length) of the vector.
         * @return The Euclidean length of the vector.
         * @note Involves a square root; prefer @ref GetMagnitudeSquared for comparisons.
         */
        inline float GetMagnitude()        const;
        /**
         * @brief Computes the squared magnitude of the vector.
         * @return The squared length (x*x + y*y).
         * @note Cheaper than @ref GetMagnitude since it avoids the square root.
         */
        inline float GetMagnitudeSquared() const;
        /**
         * @brief Returns a normalized copy of this vector (unit length).
         * @return A new @ref Vec2 with the same direction and magnitude 1.
         * @note If the magnitude of this vector is zero it will return itself instead.
         */
        inline Vec2 GetNormalized()        const;
        /**
         * @brief Returns a vector perpendicular to this one.
         * @return A new @ref Vec2 rotated 90 degrees from this vector.
         */
        inline Vec2 GetPerpendicular()     const;
        /**
         * @brief Checks whether the vector is close enough to zero.
         * @return true if both components are within a small epsilon of 0, false otherwise.
         */
        inline bool IsNearZero()           const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        /**
         * @brief Assigns from a @ref Vec3, discarding the z component.
         * @param _vec Source Vec3 whose x and y are copied.
         * @return Reference to this vector after assignment.
         * @note The z component of @p _vec is ignored.
         */
        inline Vec2& operator = (const class Vec3& _vec);
        /**
         * @brief Assigns from a @ref Vec4, discarding the z and w components.
         * @param _vec Source Vec4 whose x and y are copied.
         * @return Reference to this vector after assignment.
         * @note The z and w components of @p _vec are ignored.
         */
		inline Vec2& operator = (const class Vec4& _vec);
        /**
         * @brief Assigns the same value to both x and y.
         * @param _sca Value assigned to both components.
         * @return Reference to this vector after assignment.
         */
        inline Vec2& operator = (float _sca);

        /**
         * @brief Returns the negated vector.
         * @return A new Vec2 with both components negated.
         */
        inline Vec2 operator - (void)              const;
        /**
         * @brief Checks equality between this vector and another.
         * @param _vec Vector to compare against.
         * @return true if both components are equal, false otherwise.
         */
        inline bool operator == (const Vec2& _vec) const;
        /**
         * @brief Checks inequality between this vector and another.
         * @param _vec Vector to compare against.
         * @return true if any component differs, false otherwise.
         */
        inline bool operator != (const Vec2& _vec) const;

        /**
         * @brief Accesses a component by index.
         * @param _index Index of the component (0 = x, 1 = y).
         * @return The value of the requested component.
         * @note Bounds check are performed; passing an index outside [0, 1] triggers and assert.
         */
        inline float operator [] (int _index) const;

        //Vec2 TO Vec2 OPERATIONS :
        /**
         * @brief Adds two vectors component-wise.
         * @param _vec Vector to add.
         * @return A new Vec2 equal to this + @p _vec.
         */
        inline Vec2 operator + (const Vec2& _vec) const;
        /**
         * @brief Subtracts a vector component-wise.
         * @param _vec Vector to subtract.
         * @return A new Vec2 equal to this - @p _vec.
         */
        inline Vec2 operator - (const Vec2& _vec) const;

        //Vec2 TO THIS OPERATIONS :
        /**
         * @brief Adds a vector to this one in place.
         * @param _vec Vector to add.
         * @return Reference to this vector after addition.
         */
        inline Vec2& operator += (const Vec2& _vec);
        /**
         * @brief Subtracts a vector from this one in place.
         * @param _vec Vector to subtract.
         * @return Reference to this vector after subtraction.
         */
        inline Vec2& operator -= (const Vec2& _vec);

        //SCALER TO Vec2 OPERATIONS :
        /**
         * @brief Adds a scalar to both components.
         * @param _sca Scalar value to add.
         * @return A new Vec2 with @p _sca added to x and y.
         */
        inline Vec2 operator + (float _sca) const;
        /**
         * @brief Subtracts a scalar from both components.
         * @param _sca Scalar value to subtract.
         * @return A new Vec2 with @p _sca subtracted from x and y.
         */
        inline Vec2 operator - (float _sca) const;
        /**
         * @brief Multiplies both components by a scalar.
         * @param _sca Scalar value to multiply by.
         * @return A new Vec2 scaled by @p _sca.
         */
        inline Vec2 operator * (float _sca) const;
        /**
         * @brief Divides both components by a scalar.
         * @param _sca Scalar value to divide by.
         * @return A new Vec2 divided by @p _sca.
         * @note No check is performed for division by zero.
         */
        inline Vec2 operator / (float _sca) const;

        //SCALER TO THIS OPERATIONS :
        /**
         * @brief Adds a scalar to both components in place.
         * @param _sca Scalar value to add.
         * @return Reference to this vector after addition.
         */
        inline Vec2& operator += (float _sca);
        /**
         * @brief Subtracts a scalar from both components in place.
         * @param _sca Scalar value to subtract.
         * @return Reference to this vector after subtraction.
         */
        inline Vec2& operator -= (float _sca);
        /**
         * @brief Multiplies both components by a scalar in place.
         * @param _sca Scalar value to multiply by.
         * @return Reference to this vector after multiplication.
         */
        inline Vec2& operator *= (float _sca);
        /**
         * @brief Divides both components by a scalar in place.
         * @param _sca Scalar value to divide by.
         * @return Reference to this vector after division.
         * @note No check is performed for division by zero.
         */
        inline Vec2& operator /= (float _sca);
    };
    namespace Vectors
    {
        /**
         * @brief Normalizes a vector in place.
         *
         * Modifies the input vector so that it has a magnitude of 1 while
         * preserving its direction.
         *
         * @param _vec Vector to normalize.
         * @return Reference to the normalized vector.
         *
         * @note If the magnitude of the vector is zero, the vector is left unchanged.
         */
        inline Vec2& MATHS_LIB_API Normalize(Vec2& _vec);
        /**
         * @brief Returns a normalized copy of a vector.
         *
         * Creates a new vector with a magnitude of 1 while preserving the
         * direction of the input vector.
         *
         * @param _vec Vector to normalize.
         * @return A normalized copy of @p _vec.
         *
         * @note If the magnitude of the vector is zero, the input vector is returned unchanged.
         * @note The returned value can be constructed efficiently using C++17 guaranteed
         *       return value optimization (RVO).
         */
        inline Vec2 MATHS_LIB_API Normalize(const Vec2& _vec);

        /**
         * @brief Computes the dot product of two vectors.
         *
         * The dot product is calculated as:
         * @f[
         * A \cdot B = A_x B_x + A_y B_y
         * @f]
         *
         * @param _vecA First vector.
         * @param _vecB Second vector.
         * @return The dot product of @p _vecA and @p _vecB.
         *
         * @note The result can be used to determine the relationship between
         *       the directions of the two vectors.
         */
        inline float MATHS_LIB_API DotProduct(const Vec2& _vecA, const Vec2& _vecB);
        inline float MATHS_LIB_API DistanceBetween(const Vec2& _vecA, const Vec2& _vecB);
        inline float MATHS_LIB_API AngleBetween(const Vec2& _vecA, const Vec2& _vecB);
        //return the z value
        inline float MATHS_LIB_API CrossProduct(const Vec2& _vecA, const Vec2& _vecB);
    }






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
            float xyz_raw[3];
        };

#ifdef ENABLE_SWIZZLE
        SWIZZLE_3_DECLARATION(x, y, z)
#endif

        //STATIC MEMBERS :
        static const Vec3 UP;
		static const Vec3 DOWN;

		static const Vec3 RIGHT;
		static const Vec3 LEFT;

		static const Vec3 FORWARD;
		static const Vec3 BACKWARD;

        //CONSTRUCTORS :
        inline Vec3(void);
        inline Vec3(float _xyz);
        inline Vec3(float _x, float _y, float _z);
        inline Vec3(const class Vec2& _vec, float z = 0.f);
        inline Vec3(const class Vec4& _vec);

        //DESTRUCTOR :
        inline ~Vec3(void);

        //UTILS :
        inline float GetMagnitude()        const;
        inline float GetMagnitudeSquared() const;
        inline Vec3 GetNormalized()        const;
        inline bool IsNearZero()           const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Vec3& operator = (const class Vec2& _vec);
		inline Vec3& operator = (const class Vec4& _vec);
        inline Vec3& operator = (float _sca);

        inline Vec3 operator - (void)              const;
        inline bool operator == (const Vec3& _vec) const;
        inline bool operator != (const Vec3& _vec) const;

        inline float operator [] (int _index) const;

        //Vec3 TO Vec3 OPERATIONS :
        inline Vec3 operator + (const Vec3& _vec) const;
        inline Vec3 operator - (const Vec3& _vec) const;

        //Vec3 TO THIS OPERATIONS :
        inline Vec3& operator += (const Vec3& _vec);
        inline Vec3& operator -= (const Vec3& _vec);

        //SCALER TO Vec3 OPERATIONS :
        inline Vec3 operator + (float _sca) const;
        inline Vec3 operator - (float _sca) const;
        inline Vec3 operator * (float _sca) const;
        inline Vec3 operator / (float _sca) const;

        //SCALER TO THIS OPERATIONS :
        inline Vec3& operator += (float _sca);
        inline Vec3& operator -= (float _sca);
        inline Vec3& operator *= (float _sca);
        inline Vec3& operator /= (float _sca);
    };
    namespace Vectors
    {
        //return the input vector normalised
        inline Vec3& MATHS_LIB_API Normalize(Vec3& _vec);
        //Can be used with C++17 guaranteed RVO
        inline Vec3 MATHS_LIB_API Normalize(const Vec3& _vec);

        inline float MATHS_LIB_API DotProduct(const Vec3& _vecA, const Vec3& _vecB);
        inline float MATHS_LIB_API DistanceBetween(const Vec3& _vecA, const Vec3& _vecB);
        inline float MATHS_LIB_API AngleBetween(const Vec3& _vecA, const Vec3& _vecB);
        inline Vec3 MATHS_LIB_API CrossProduct(const Vec3& _vecA, const Vec3& _vecB);
        inline Vec3 MATHS_LIB_API Rotate(const Vec3& _vec, float _angle, const Vec3& _axis);
    }






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
            float xyzw_raw[4];
        };

#ifdef ENABLE_SWIZZLE
        SWIZZLE_4_DECLARATION(x,y,z,w)
#endif

        //CONSTRUCTORS :
        inline Vec4(void);
        inline Vec4(float _xyzw);
        inline Vec4(float _x, float _y, float _z, float _w);
        inline Vec4(const class Vec2& _vec, float _z = 0.f, float _w = 1.f);
		inline Vec4(const class Vec3& _vec, float _w = 1.f);

        //DESTRUCTOR :
        inline ~Vec4(void);

        //UTILS :
        inline float GetMagnitude()        const;
        inline float GetMagnitudeSquared() const;
        //GetNormalized is right for non Homogeneous position/direction
        inline Vec4 GetNormalized()        const;
        inline Vec4 GetHomogenized()       const;
        inline bool IsNearZero()           const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Vec4& operator = (const class Vec2& _vec);
        inline Vec4& operator = (const class Vec3& _vec);
        inline Vec4& operator = (float _sca);

        inline Vec4 operator - (void)              const;
        inline bool operator == (const Vec4& _vec) const;
        inline bool operator != (const Vec4& _vec) const;

        inline float operator [] (int _index) const;

        //Vec4 TO Vec4 OPERATIONS
        inline Vec4 operator + (const Vec4& _vec) const;
        inline Vec4 operator - (const Vec4& _vec) const;

        //Vec4 TO THIS OPERATIONS
        inline Vec4& operator += (const Vec4& _vec);
        inline Vec4& operator -= (const Vec4& _vec);

        //SCALER TO Vec4 OPERATIONS
        inline Vec4 operator + (float _sca) const;
        inline Vec4 operator - (float _sca) const;
        inline Vec4 operator * (float _sca) const;
        inline Vec4 operator / (float _sca) const;

        //SCALER TO THIS OPERATIONS
        inline Vec4& operator += (float _sca);
        inline Vec4& operator -= (float _sca);
        inline Vec4& operator *= (float _sca);
        inline Vec4& operator /= (float _sca);
    };
    namespace Vectors
    {
        //return the input vector normalised
        inline Vec4& MATHS_LIB_API Normalize(Vec4& _vec);
        //Can be used with C++17 guaranteed RVO
        inline Vec4 MATHS_LIB_API Normalize(const Vec4& _vec);

        inline float MATHS_LIB_API DotProduct(const Vec4& _vecA, const Vec4& _vecB);
        inline float MATHS_LIB_API DistanceBetween(const Vec4& _vecA, const Vec4& _vecB);
        inline float MATHS_LIB_API AngleBetween(const Vec4& _vecA, const Vec4& _vecB);
    }
    
#pragma endregion Vector






#pragma region Matrix

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
        inline Mat3& operator = (float _data[9]);
        inline Mat3& operator = (const Mat4& _mat);

        inline Mat3 operator - (void)              const;
        inline bool operator == (const Mat3& _mat) const;
		inline bool operator != (const Mat3& _mat) const;

        inline Vec3 operator [] (int _index) const;

        //Mat3 TO Mat3 OPERATIONS :
        inline Mat3 operator + (const Mat3& _mat) const;
        inline Mat3 operator - (const Mat3& _mat) const;
        inline Mat3 operator * (const Mat3& _mat) const;

        //Mat3 TO THIS OPERATIONS :
        inline Mat3& operator += (const Mat3& _mat);
        inline Mat3& operator -= (const Mat3& _mat);
        inline Mat3& operator *= (const Mat3& _mat);

        //Sca TO Mat3 OPERATIONS :
		inline Mat3 operator * (float _sca) const;
		inline Mat3 operator / (float _sca) const;

		//Sca TO This OPERATIONS :
		inline Mat3& operator *= (float _sca);
		inline Mat3& operator /= (float _sca);

        //Mat3 TO Vec2 OPERATIONS :
		inline Vec2 operator * (const Vec2& _vec) const;

		//Mat3 TO Vec3 OPERATIONS :
		inline Vec3 operator * (const Vec3& _vec) const;
    };
    namespace matrixes
    {
        inline Mat3& MATHS_LIB_API Transpose(Mat3& _mat);
        inline Mat3& MATHS_LIB_API Inverse(Mat3& _mat);
    }






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

        inline static Mat4 Frustum(float _left, float _right, float _bottom, float _top, float _nearVal, float _farVal);
        inline static Mat4 Ortho(float _left, float _right, float _bottom, float _top, float _nearVal, float _farVal);
        inline static Mat4 LookAt(Vec3 _eyeZ, Vec3 _centerZ, Vec3 _upZ);
        inline static Mat4 LookAt(Vec3 _forward, Vec3 _localUp);
        inline static Mat4 LookAtNormalized(Vec3 _forward, Vec3 _localUp);
        inline static Mat4 LookAtNormalized(Vec3 _eye, Vec3 _center, Vec3 _up);
        inline static Mat4 Perspective(float _fovY, float _aspect, float _near, float _far);

        inline Mat4 GetTranspose()    const;
        inline Mat4 GetInverse()      const;
        inline float GetDeterminant() const;
        inline float GetTrace()       const;

        //ASSINGMENT AND EQUALITY OPERATIONS :
        inline Mat4& operator = (float _data[16]);
        inline Mat4& operator = (const Mat3& _mat);

        inline Mat4 operator - (void) const;
		inline bool operator == (const Mat4& _mat) const;
		inline bool operator != (const Mat4& _mat) const;

        inline Vec4 operator [] (int _index) const;

        //Mat4 TO Mat4 OPERATIONS :
        inline Mat4 operator + (const Mat4& _mat) const;
        inline Mat4 operator - (const Mat4& _mat) const;
        inline Mat4 operator * (const Mat4& _mat) const;

        //Mat4 TO THIS OPERATIONS :
        inline Mat4& operator += (const Mat4& _mat);
        inline Mat4& operator -= (const Mat4& _mat);
        inline Mat4& operator *= (const Mat4& _mat);

        //Sca TO Mat4 OPERATIONS :
		inline Mat4 operator * (float _sca) const;
		inline Mat4 operator / (float _sca) const;

		//Sca TO This OPERATIONS :
		inline Mat4& operator *= (float _sca);
		inline Mat4& operator /= (float _sca);

		//Mat3 TO Vec3 OPERATIONS :
		inline Vec3 operator * (const Vec3& _vec) const;

		//Mat3 TO Vec4 OPERATIONS :
		inline Vec4 operator * (const Vec4& _vec) const;
    };
   
    namespace matrixes
    {
        inline Mat4& MATHS_LIB_API Transpose(Mat4& _mat);
        inline Mat4& MATHS_LIB_API Inverse(Mat4& _mat);
    }

#pragma endregion Matrix






#pragma region Quaternion

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
        inline static Quat LookAt(const Vec3& _from, const Vec3& _to);
        //in radians
        inline static Quat FromAngleAxis(float _angle, const Vec3& _axis);
        inline static Quat FromEulerAngles(const Vec3& _xyz);
        inline static Quat FromMatrix(const Mat3& _matrix);
        inline static Quat FromMatrix(const Mat4& _matrix);

        inline float GetMagnitudeSquared() const;
		inline float GetMagnitude() const;
        inline Quat GetNormalized() const;
		inline Quat GetConjugate() const;
		inline Quat GetInverse() const;

        //TODO move outside function
        inline static Quat Nlerp(const Quat& _start, const Quat& _end, float _ratio);
		inline static Quat Slerp(const Quat& _q1, const Quat& _q2, float _t);

        //CONVERSION
		inline Vec3 RotateVector(const Vec3& _vec) const;
		inline Mat3 ToRotationMatrix() const;
		inline Vec3 ToEulerAngles() const;

        // ASSINGMENT AND EQUALITY OPERATIONS :
        inline Quat operator - (void)               const;
        inline bool operator == (const Quat& _Quat) const;
        inline bool operator != (const Quat& _Quat) const;

        //return x->y->z->w
        inline float operator[](int _index) const;
		inline float& operator[](int _index);

        //Quat TO Quat OPERATIONS :
        inline Quat operator + (const Quat& _Quat) const;
        inline Quat operator - (const Quat& _Quat) const;
        inline Quat operator * (const Quat& _Quat) const;
        //inline Quat operator / (const Quat& _Quat) const; //TODO: will be added if needed later or if requested

        //Quat TO THIS OPERATIONS :
        inline Quat& operator += (const Quat& _Quat);
        inline Quat& operator -= (const Quat& _Quat);
        inline Quat& operator *= (const Quat& _Quat);
        //inline Quat operator /= (const Quat& _Quat); //TODO: will be added if needed later or if requested

        //SCALER TO Quat OPERATIONS :
        inline Quat operator * (float _Sca) const;
        inline Quat operator / (float _Sca) const;

        //SCALER TO THIS OPERATIONS :
        inline Quat& operator *= (float _Sca);
        inline Quat& operator /= (float _Sca);
    };

    namespace Quaternions
	{
		inline float DotProduct(const Quat& _q1, const Quat& _q2);		
	}

#pragma endregion Quaternion

}

#include "Maths.inl"