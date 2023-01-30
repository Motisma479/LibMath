#include "Maths.hpp"

#include <math.h>
#if ENABLE_VEC2
/************************\
 *-------VECTOR_2-------*
\************************/
#pragma region Vec2
//CONSTRUCTORS
inline Maths::Vec2::Vec2(void)								: x(0)		, y(0)			{}
inline Maths::Vec2::Vec2(const float& xy)					: x(xy)		, y(xy)			{}
inline Maths::Vec2::Vec2(const float& x, const float& y)	: x(x)		, y(y)			{}
inline Maths::Vec2::Vec2(const Vec2& _Vec2)					: x(_Vec2.x), y(_Vec2.y)	{}
inline Maths::Vec2::Vec2(const Vec3& _Vec3)					: x(_Vec3.x), y(_Vec3.y)	{}
inline Maths::Vec2::Vec2(const Vec4& _Vec4)					: x(_Vec4.x), y(_Vec4.y)	{}

//DESTRUCTOR
inline Maths::Vec2::~Vec2(void) {}

//UTILS
inline float Maths::Vec2::GetMagnitude()
{
	return (float)sqrt((x * x) + (y * y));
}
inline void Maths::Vec2::Normalize()
{
	operator/=(GetMagnitude());
	//x /= GetMagnitude();
	//y /= GetMagnitude();
}
inline float Maths::Vec2::DotProduct(const Vec2& _VecB)
{
	return (float)(x * _VecB.x + y * _VecB.y);
}
inline float Maths::Vec2::DotProduct(const Vec2& _VecA, const Vec2& _VecB)
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y);
}
inline float* Maths::Vec2::ToFloat2()
{
	return &x;
}

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::Vec2 Maths::Vec2::operator = (const Vec2& _Vec)
{
	x = _Vec.x;
	y = _Vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator = (const float& _Sca)
{
	x = _Sca;
	y = _Sca;
	return *this;
}

inline Maths::Vec2 Maths::Vec2::operator - (void)		const
{
	return (Vec2)(-x, -y);
}
inline bool Maths::Vec2::operator == (const Vec2& _Vec)	const
{
	return (x == _Vec.x) && (y == _Vec.y);
}
inline bool Maths::Vec2::operator != (const Vec2& _Vec)	const
{
	return (x != _Vec.x) || (y != _Vec.y);
}

//Vec2 TO Vec2 OPERATIONS
inline Maths::Vec2 Maths::Vec2::operator + (const Vec2& _Vec) const
{
	return Vec2(x + _Vec.x, y + _Vec.y);
}
inline Maths::Vec2 Maths::Vec2::operator - (const Vec2& _Vec) const
{
	return Vec2(x - _Vec.x, y - _Vec.y);
}
inline Maths::Vec2 Maths::Vec2::operator * (const Vec2& _Vec) const
{
	return Vec2(x * _Vec.x, y * _Vec.y);
}
inline Maths::Vec2 Maths::Vec2::operator / (const Vec2& _Vec) const
{
	return Vec2(x / _Vec.x, y / _Vec.y);
}

//Vec2 TO THIS OPERATIONS
inline Maths::Vec2 Maths::Vec2::operator += (const Vec2& _Vec)
{
	x += _Vec.x;
	y += _Vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator -= (const Vec2& _Vec)
{
	x -= _Vec.x;
	y -= _Vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator *= (const Vec2& _Vec)
{
	x *= _Vec.x;
	y *= _Vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator /= (const Vec2& _Vec)
{
	x /= _Vec.x;
	y /= _Vec.y;
	return *this;
}

//SCALER TO Vec2 OPERATIONS
inline Maths::Vec2 Maths::Vec2::operator + (const float& _Sca) const
{
	return Vec2(x + _Sca, y + _Sca);
}
inline Maths::Vec2 Maths::Vec2::operator - (const float& _Sca) const
{
	return Vec2(x - _Sca, y - _Sca);
}
inline Maths::Vec2 Maths::Vec2::operator * (const float& _Sca) const
{
	return Vec2(x * _Sca, y * _Sca);
}
inline Maths::Vec2 Maths::Vec2::operator / (const float& _Sca) const
{
	return Vec2(x / _Sca, y / _Sca);
}

//SCALER TO THIS OPERATIONS
inline Maths::Vec2 Maths::Vec2::operator += (const float& _Sca)
{
	x += _Sca;
	y += _Sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator -= (const float& _Sca)
{
	x -= _Sca;
	y -= _Sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator *= (const float& _Sca)
{
	x *= _Sca;
	y *= _Sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator /= (const float& _Sca)
{
	x /= _Sca;
	y /= _Sca;
	return *this;
}
#pragma endregion Vec2
#endif // ENABLE_VEC2


#if ENABLE_IVEC2
/************************\
 *------IVECTOR_2-------*
\************************/
#pragma region IVec2
//CONSTRUCTORS
inline Maths::IVec2::IVec2(void)						: x(0)			, y(0)			{}
inline Maths::IVec2::IVec2(const int xy)				: x(xy)			, y(xy)			{}
inline Maths::IVec2::IVec2(const int x, const int y)	: x(x)			, y(y)			{}
inline Maths::IVec2::IVec2(const IVec2& _IVec2)			: x(_IVec2.x)	, y(_IVec2.y)	{}

//DESTRUCTOR
inline Maths::IVec2::~IVec2(void) {}

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::IVec2 Maths::IVec2::operator = (const IVec2& _IVec)
{
	x = _IVec.x;
	y = _IVec.y;
	return *this;
}
inline Maths::IVec2 Maths::IVec2::operator = (const int _Sca)
{
	x = _Sca;
	y = _Sca;
	return *this;
}

inline Maths::IVec2 Maths::Vec2::operator - (void)			const
{
	return IVec2(-x, -y);
}
inline bool Maths::IVec2::operator == (const IVec2& _IVec)	const
{
	return (x == _IVec.x) && (y == _IVec.y);
}
inline bool Maths::IVec2::operator != (const IVec2& _IVec)	const
{
	return (x != _IVec.x) || (y != _IVec.y);
}

//Vec2 TO Vec2 OPERATIONS
inline Maths::IVec2 Maths::IVec2::operator + (const IVec2& _IVec) const
{
	return IVec2(x + _IVec.x, y + _IVec.y);
}
inline Maths::IVec2 Maths::IVec2::operator - (const IVec2& _IVec) const
{
	return IVec2(x - _IVec.x, y - _IVec.y);
}
inline Maths::IVec2 Maths::IVec2::operator * (const IVec2& _IVec) const
{
	return IVec2(x * _IVec.x, y * _IVec.y);
}
inline Maths::IVec2 Maths::IVec2::operator / (const IVec2& _IVec) const
{
	return IVec2(x / _IVec.x, y / _IVec.y);
}

//Vec2 TO THIS OPERATIONS
inline Maths::IVec2 Maths::IVec2::operator += (const IVec2& _IVec)
{
	x += _IVec.x;
	y += _IVec.y;
	return *this;
}
inline Maths::IVec2 Maths::IVec2::operator -= (const IVec2& _IVec)
{
	x -= _IVec.x;
	y -= _IVec.y;
	return *this;
}
inline Maths::IVec2 Maths::IVec2::operator *= (const IVec2& _IVec)
{
	x *= _IVec.x;
	y *= _IVec.y;
	return *this;
}
inline Maths::IVec2 Maths::IVec2::operator /= (const IVec2& _IVec)
{
	x /= _IVec.x;
	y /= _IVec.y;
	return *this;
}

//SCALER TO Vec2 OPERATIONS
inline Maths::IVec2 Maths::IVec2::operator + (const int _Sca) const
{
	return IVec2(x + _Sca, y + _Sca);
}
inline Maths::IVec2 Maths::IVec2::operator - (const int _Sca) const
{
	return IVec2(x - _Sca, y - _Sca);
}
inline Maths::IVec2 Maths::IVec2::operator * (const int _Sca) const
{
	return IVec2(x * _Sca, y * _Sca);
}
inline Maths::IVec2 Maths::IVec2::operator / (const int _Sca) const
{
	return IVec2(x / _Sca, y / _Sca);
}

//SCALER TO THIS OPERATIONS
inline Maths::IVec2 Maths::IVec2::operator += (const int _Sca)
{
	x += _Sca;
	y += _Sca;
	return *this;
}
inline Maths::IVec2 Maths::IVec2::operator -= (const int _Sca)
{
	x -= _Sca;
	y -= _Sca;
	return *this;
}
inline Maths::IVec2 Maths::IVec2::operator *= (const int _Sca)
{
	x *= _Sca;
	y *= _Sca;
	return *this;
}
inline Maths::IVec2 Maths::IVec2::operator /= (const int _Sca)
{
	x /= _Sca;
	y /= _Sca;
	return *this;
}
#pragma endregion IVec2
#endif // ENABLE_IVEC2


#if ENABLE_VEC3
/************************\
 *-------VECTOR_3-------*
\************************/
#pragma region Vec3
//CONSTRUCTORS
inline Maths::Vec3::Vec3(void)												: x(0)		, y(0)		, z(0)			{}
inline Maths::Vec3::Vec3(const float& xyz)									: x(xyz)	, y(xyz)	, z(xyz)		{}
inline Maths::Vec3::Vec3(const float& x, const float& y, const float& z)	: x(x)		, y(y)		, z(z)			{}
inline Maths::Vec3::Vec3(const Vec2& _Vec2)									: x(_Vec2.x), y(_Vec2.y), z(0)			{}
inline Maths::Vec3::Vec3(const Vec3& _Vec3)									: x(_Vec3.x), y(_Vec3.y), z(_Vec3.z)	{}
inline Maths::Vec3::Vec3(const Vec4& _Vec4)									: x(_Vec4.x), y(_Vec4.y), z(_Vec4.z)	{}

//DESTRUCTOR
inline Maths::Vec3::~Vec3(void) {}

//UTILS
inline float Maths::Vec3::GetMagnitude()
{
	return (float)sqrt((x * x) + (y * y) + (z * z));
}
inline void Maths::Vec3::Normalize()
{
	operator/=(GetMagnitude());
	//x /= GetMagnitude();
	//y /= GetMagnitude();
	//z /= GetMagnitude();
}
inline float Maths::Vec3::DotProduct(const Vec3& _VecB)
{
	return (float)(x * _VecB.x + y * _VecB.y + z * _VecB.z);
}
inline float Maths::Vec3::DotProduct(const Vec3& _VecA, const Vec3& _VecB)
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y + _VecA.z * _VecB.z);
}
inline float* Maths::Vec3::ToFloat3()
{
	return &x;
}
inline Maths::Vec3 Maths::Vec3::crossProduct(const Vec3& _VecA, const Vec3& _VecB)
{
	return { _VecA.y * _VecB.z - _VecA.z * _VecB.y, _VecA.z * _VecB.x - _VecA.x * _VecB.z, _VecA.x * _VecB.y - _VecA.y * _VecB.x };
}

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::Vec3 Maths::Vec3::operator = (const Vec3& _Vec)
{
	x = _Vec.x;
	y = _Vec.y;
	z = _Vec.z;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator = (const float& _Sca)
{
	x = _Sca;
	y = _Sca;
	z = _Sca;
	return *this;
}

inline Maths::Vec3 Maths::Vec3::operator - (void)		const
{
	return (Vec3)(-x, -y, -z);
}
inline bool Maths::Vec3::operator == (const Vec3& _Vec)	const
{
	return (x == _Vec.x) && (y == _Vec.y) && (z == _Vec.z);
}
inline bool Maths::Vec3::operator != (const Vec3& _Vec)	const
{
	return (x != _Vec.x) || (y != _Vec.y) || (z != _Vec.z);
}

//Vec3 TO Vec3 OPERATIONS
inline Maths::Vec3 Maths::Vec3::operator + (const Vec3& _Vec) const
{
	return Vec3(x + _Vec.x, y + _Vec.y, z + _Vec.z);
}
inline Maths::Vec3 Maths::Vec3::operator - (const Vec3& _Vec) const
{
	return Vec3(x - _Vec.x, y - _Vec.y, z - _Vec.z);
}
inline Maths::Vec3 Maths::Vec3::operator * (const Vec3& _Vec) const
{
	return Vec3(x * _Vec.x, y * _Vec.y, z * _Vec.z);
}
inline Maths::Vec3 Maths::Vec3::operator / (const Vec3& _Vec) const
{
	return Vec3(x / _Vec.x, y / _Vec.y, z / _Vec.z);
}

//Vec3 TO THIS OPERATIONS
inline Maths::Vec3 Maths::Vec3::operator += (const Vec3& _Vec)
{
	x += _Vec.x;
	y += _Vec.y;
	z += _Vec.z;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator -= (const Vec3& _Vec)
{
	x -= _Vec.x;
	y -= _Vec.y;
	z -= _Vec.z;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator *= (const Vec3& _Vec)
{
	x *= _Vec.x;
	y *= _Vec.y;
	z *= _Vec.z;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator /= (const Vec3& _Vec)
{
	x /= _Vec.x;
	y /= _Vec.y;
	z /= _Vec.z;
	return *this;
}

//SCALER TO Vec3 OPERATIONS
inline Maths::Vec3 Maths::Vec3::operator + (float _Sca) const
{
	return Vec3(x + _Sca, y + _Sca, z + _Sca);
}
inline Maths::Vec3 Maths::Vec3::operator - (float _Sca) const
{
	return Vec3(x - _Sca, y - _Sca, z - _Sca);
}
inline Maths::Vec3 Maths::Vec3::operator * (float _Sca) const
{
	return Vec3(x * _Sca, y * _Sca, z * _Sca);
}
inline Maths::Vec3 Maths::Vec3::operator / (float _Sca) const
{
	return Vec3(x / _Sca, y / _Sca, z / _Sca);
}

//SCALER TO THIS OPERATIONS
inline Maths::Vec3 Maths::Vec3::operator += (float _Sca)
{
	x += _Sca;
	y += _Sca;
	z += _Sca;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator -= (float _Sca)
{
	x -= _Sca;
	y -= _Sca;
	z -= _Sca;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator *= (float _Sca)
{
	x *= _Sca;
	y *= _Sca;
	z *= _Sca;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator /= (float _Sca)
{
	x /= _Sca;
	y /= _Sca;
	z /= _Sca;
	return *this;
}

#pragma endregion Vec3
#endif //ENABLE_VEC3


#if ENABLE_IVEC3
/************************\
 *------IVECTOR_3-------*
\************************/
#pragma region IVec3
//CONSTRUCTORS
inline Maths::IVec3::IVec3(void)									: x(0)			, y(0)			, z(0)			{}
inline Maths::IVec3::IVec3(const int xyz)							: x(xyz)		, y(xyz)		, z(xyz)		{}
inline Maths::IVec3::IVec3(const int x, const int y, const int z)	: x(x)			, y(y)			, z(z)			{}
inline Maths::IVec3::IVec3(const IVec3& _IVec3)						: x(_IVec3.x)	, y(_IVec3.y)	, z(_IVec3.z)	{}

//DESTRUCTOR
inline Maths::IVec3::~IVec3(void) {}

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::IVec3 Maths::IVec3::operator = (const IVec3& _IVec)
{
	x = _IVec.x;
	y = _IVec.y;
	z = _IVec.z;
	return *this;
}
inline Maths::IVec3 Maths::IVec3::operator = (const int _Sca)
{
	x = _Sca;
	y = _Sca;
	z = _Sca;
	return *this;
}

inline Maths::IVec3 Maths::Vec3::operator - (void)			const
{
	return IVec2(-x, -y, -z);
}
inline bool Maths::IVec3::operator == (const IVec3& _IVec)	const
{
	return (x == _IVec.x) && (y == _IVec.y) && (z == _IVec.z);
}
inline bool Maths::IVec3::operator != (const IVec3& _IVec)	const
{
	return (x != _IVec.x) || (y != _IVec.y) || (z != _IVec.z);
}

//Vec2 TO Vec2 OPERATIONS
inline Maths::IVec3 Maths::IVec3::operator + (const IVec3& _IVec) const
{
	return IVec2(x + _IVec.x, y + _IVec.y, z + _IVec.z);
}
inline Maths::IVec3 Maths::IVec3::operator - (const IVec3& _IVec) const
{
	return IVec2(x - _IVec.x, y - _IVec.y, z - _IVec.z);
}
inline Maths::IVec3 Maths::IVec3::operator * (const IVec3& _IVec) const
{
	return IVec2(x * _IVec.x, y * _IVec.y, z * _IVec.z);
}
inline Maths::IVec3 Maths::IVec3::operator / (const IVec3& _IVec) const
{
	return IVec2(x / _IVec.x, y / _IVec.y, z / _IVec.z);
}

//Vec2 TO THIS OPERATIONS
inline Maths::IVec3 Maths::IVec3::operator += (const IVec3& _IVec)
{
	x += _IVec.x;
	y += _IVec.y;
	z += _IVec.z;
	return *this;
}
inline Maths::IVec3 Maths::IVec3::operator -= (const IVec3& _IVec)
{
	x -= _IVec.x;
	y -= _IVec.y;
	z -= _IVec.z;
	return *this;
}
inline Maths::IVec3 Maths::IVec3::operator *= (const IVec3& _IVec)
{
	x *= _IVec.x;
	y *= _IVec.y;
	z *= _IVec.z;
	return *this;
}
inline Maths::IVec3 Maths::IVec3::operator /= (const IVec3& _IVec)
{
	x /= _IVec.x;
	y /= _IVec.y;
	z /= _IVec.z;
	return *this;
}

//SCALER TO Vec2 OPERATIONS
inline Maths::IVec3 Maths::IVec3::operator + (const int _Sca) const
{
	return IVec2(x + _Sca, y + _Sca, z + _Sca);
}
inline Maths::IVec3 Maths::IVec3::operator - (const int _Sca) const
{
	return IVec2(x - _Sca, y - _Sca, z - _Sca);
}
inline Maths::IVec3 Maths::IVec3::operator * (const int _Sca) const
{
	return IVec2(x * _Sca, y * _Sca, z * _Sca);
}
inline Maths::IVec3 Maths::IVec3::operator / (const int _Sca) const
{
	return IVec2(x / _Sca, y / _Sca, z / _Sca);
}

//SCALER TO THIS OPERATIONS
inline Maths::IVec3 Maths::IVec3::operator += (const int _Sca)
{
	x += _Sca;
	y += _Sca;
	z += _Sca;
	return *this;
}
inline Maths::IVec3 Maths::IVec3::operator -= (const int _Sca)
{
	x -= _Sca;
	y -= _Sca;
	z -= _Sca;
	return *this;
}
inline Maths::IVec3 Maths::IVec3::operator *= (const int _Sca)
{
	x *= _Sca;
	y *= _Sca;
	z *= _Sca;
	return *this;
}
inline Maths::IVec3 Maths::IVec3::operator /= (const int _Sca)
{
	x /= _Sca;
	y /= _Sca;
	z /= _Sca;
	return *this;
}
#pragma endregion IVec3
#endif // ENABLE_IVEC3


#if ENABLE_VEC4
/************************\
 *-------VECTOR_4-------*
\************************/
#pragma region Vec4
//CONSTRUCTORS
inline Maths::Vec4::Vec4(void)																: x(0)		, y(0)		, z(0)		, w(0)			{}
inline Maths::Vec4::Vec4(const float& xyzw)													: x(xyzw)	, y(xyzw)	, z(xyzw)	, w(xyzw)		{}
inline Maths::Vec4::Vec4(const float& x, const float& y, const float& z, const float& w)	: x(x)		, y(y)		, z(z)		, w(w)			{}
inline Maths::Vec4::Vec4(const Vec2& _Vec2)													: x(_Vec2.x), y(_Vec2.y), z(0)		, w(0)			{}
inline Maths::Vec4::Vec4(const Vec3& _Vec3)													: x(_Vec3.x), y(_Vec3.y), z(_Vec3.z), w(0)			{}
inline Maths::Vec4::Vec4(const Vec3& _Vec3, float w)										: x(_Vec3.x), y(_Vec3.y), z(_Vec3.z), w(w)			{}
inline Maths::Vec4::Vec4(const Vec4& _Vec4)													: x(_Vec4.x), y(_Vec4.y), z(_Vec4.z), w(_Vec4.w)	{}

//DESTRUCTOR
inline Maths::Vec4::~Vec4(void) { }

//UTILS

inline float Maths::Vec4::GetMagnitude()
{
	return (float)sqrt((x * x) + (y * y) + (z * z) + (w * w));
}
inline void Maths::Vec4::Normalize()
{
	//x /= GetMagnitude();
	//y /= GetMagnitude();
	//z /= GetMagnitude();
	//w /= GetMagnitude();
	operator/=(GetMagnitude());
}
inline float Maths::Vec4::DotProduct(const Vec4& _VecB)
{
	return (float)(x * _VecB.x + y * _VecB.y + z * _VecB.z + w * _VecB.w);
}
inline float Maths::Vec4::DotProduct(const Vec4& _VecA, const Vec4& _VecB)
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y + _VecA.z * _VecB.z + _VecA.w * _VecB.w);
}
inline float* Maths::Vec4::ToFloat4()
{
	return &x;
}
inline Maths::Vec4 Maths::Vec4::Homogenize()
{
	if (w == 0)
		return { x, y, z, w };
	return { x / w, y / w, z / w, 1 };
}

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::Vec4 Maths::Vec4::operator = (const Vec4& _Vec)
{
	x = _Vec.x;
	y = _Vec.y;
	z = _Vec.z;
	w = _Vec.w;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator = (const float& _Sca)
{
	x = _Sca;
	y = _Sca;
	z = _Sca;
	w = _Sca;
	return *this;
}

inline Maths::Vec4 Maths::Vec4::operator - (void)		const
{
	return (Vec4)(-x, -y, -z, -w);
}
inline bool Maths::Vec4::operator == (const Vec4& _Vec)	const
{
	return (x == _Vec.x) && (y == _Vec.y) && (z == _Vec.z) && (w == _Vec.w);
}
inline bool Maths::Vec4::operator != (const Vec4& _Vec)	const
{
	return (x != _Vec.x) || (y != _Vec.y) || (z != _Vec.z) || (w != _Vec.w);
}

//Vec4 TO Vec4 OPERATIONS
inline Maths::Vec4 Maths::Vec4::operator + (const Vec4& _Vec) const
{
	return Vec4(x + _Vec.x, y + _Vec.y, z + _Vec.z, w + _Vec.w);
}
inline Maths::Vec4 Maths::Vec4::operator - (const Vec4& _Vec) const
{
	return Vec4(x - _Vec.x, y - _Vec.y, z - _Vec.z, w - _Vec.w);
}
inline Maths::Vec4 Maths::Vec4::operator * (const Vec4& _Vec) const
{
	return Vec4(x * _Vec.x, y * _Vec.y, z * _Vec.z, w * _Vec.w);
}
inline Maths::Vec4 Maths::Vec4::operator / (const Vec4& _Vec) const
{
	return Vec4(x / _Vec.x, y / _Vec.y, z / _Vec.z, w / _Vec.w);
}

//Vec4 TO THIS OPERATIONS
inline Maths::Vec4 Maths::Vec4::operator += (const Vec4& _Vec)
{
	x += _Vec.x;
	y += _Vec.y;
	z += _Vec.z;
	w += _Vec.w;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator -= (const Vec4& _Vec)
{
	x -= _Vec.x;
	y -= _Vec.y;
	z -= _Vec.z;
	w -= _Vec.w;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator *= (const Vec4& _Vec)
{
	x *= _Vec.x;
	y *= _Vec.y;
	z *= _Vec.z;
	w *= _Vec.w;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator /= (const Vec4& _Vec)
{
	x /= _Vec.x;
	y /= _Vec.y;
	z /= _Vec.z;
	w /= _Vec.w;
	return *this;
}

//SCALER TO Vec4 OPERATIONS
inline Maths::Vec4 Maths::Vec4::operator + (const float& _Sca) const
{
	return Vec4(x + _Sca, y + _Sca, z + _Sca, w + _Sca);
}
inline Maths::Vec4 Maths::Vec4::operator - (const float& _Sca) const
{
	return Vec4(x - _Sca, y - _Sca, z - _Sca, w - _Sca);
}
inline Maths::Vec4 Maths::Vec4::operator * (const float& _Sca) const
{
	return Vec4(x * _Sca, y * _Sca, z * _Sca, w * _Sca);
}
inline Maths::Vec4 Maths::Vec4::operator / (const float& _Sca) const
{
	return Vec4(x / _Sca, y / _Sca, z / _Sca, w / _Sca);
}

//SCALER TO THIS OPERATIONS
inline Maths::Vec4 Maths::Vec4::operator += (const float& _Sca)
{
	x += _Sca;
	y += _Sca;
	z += _Sca;
	w += _Sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator -= (const float& _Sca)
{
	x -= _Sca;
	y -= _Sca;
	z -= _Sca;
	w -= _Sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator *= (const float& _Sca)
{
	x *= _Sca;
	y *= _Sca;
	z *= _Sca;
	w *= _Sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator /= (const float& _Sca)
{
	x /= _Sca;
	y /= _Sca;
	z /= _Sca;
	w /= _Sca;
	return *this;
}
#pragma endregion Vec4
#endif //ENABLE_VEC4


#if ENABLE_IVEC4
/************************\
 *------IVECTOR_4-------*
\************************/
#pragma region IVec4
//CONSTRUCTORS
inline Maths::IVec4::IVec4(void)												: x(0)			, y(0)			, z(0)			, w(0)			{}
inline Maths::IVec4::IVec4(const int xyzw)										: x(xyzw)		, y(xyzw)		, z(xyzw)		, w(xyzw)		{}
inline Maths::IVec4::IVec4(const int x, const int y, const int z, const int w)	: x(x)			, y(y)			, z(z)			, w(w)			{}
inline Maths::IVec4::IVec4(const IVec4& _IVec4)									: x(_IVec4.x)	, y(_IVec4.y)	, z(_IVec4.z)	, w(_IVec4.w)	{}

//DESTRUCTOR
inline Maths::IVec4::~IVec4(void) {}

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::IVec4 Maths::IVec4::operator = (const IVec4& _IVec)
{
	x = _IVec.x;
	y = _IVec.y;
	z = _IVec.z;
	w = _IVec.w;
	return *this;
}
inline Maths::IVec4 Maths::IVec4::operator = (const int _Sca)
{
	x = _Sca;
	y = _Sca;
	z = _Sca;
	w = _Sca;
	return *this;
}

inline Maths::IVec4 Maths::Vec4::operator - (void)			const
{
	return IVec2(-x, -y, -z, -w);
}
inline bool Maths::IVec4::operator == (const IVec4& _IVec)	const
{
	return (x == _IVec.x) && (y == _IVec.y) && (z == _IVec.z) && (w == _IVec.w);
}
inline bool Maths::IVec4::operator != (const IVec4& _IVec)	const
{
	return (x != _IVec.x) || (y != _IVec.y) || (z != _IVec.z) || (w != _IVec.w);
}

//Vec2 TO Vec2 OPERATIONS
inline Maths::IVec4 Maths::IVec4::operator + (const IVec4& _IVec) const
{
	return IVec2(x + _IVec.x, y + _IVec.y, z + _IVec.z, w + _IVec.w);
}
inline Maths::IVec4 Maths::IVec4::operator - (const IVec4& _IVec) const
{
	return IVec2(x - _IVec.x, y - _IVec.y, z - _IVec.z, w - _IVec.w);
}
inline Maths::IVec4 Maths::IVec4::operator * (const IVec4& _IVec) const
{
	return IVec2(x * _IVec.x, y * _IVec.y, z * _IVec.z, w * _IVec.w);
}
inline Maths::IVec4 Maths::IVec4::operator / (const IVec4& _IVec) const
{
	return IVec2(x / _IVec.x, y / _IVec.y, z / _IVec.z, w / _IVec.w);
}

//Vec2 TO THIS OPERATIONS
inline Maths::IVec4 Maths::IVec4::operator += (const IVec4& _IVec)
{
	x += _IVec.x;
	y += _IVec.y;
	z += _IVec.z;
	w += _IVec.w;
	return *this;
}
inline Maths::IVec4 Maths::IVec4::operator -= (const IVec4& _IVec)
{
	x -= _IVec.x;
	y -= _IVec.y;
	z -= _IVec.z;
	w -= _IVec.w;
	return *this;
}
inline Maths::IVec4 Maths::IVec4::operator *= (const IVec4& _IVec)
{
	x *= _IVec.x;
	y *= _IVec.y;
	z *= _IVec.z;
	w *= _IVec.w;
	return *this;
}
inline Maths::IVec4 Maths::IVec4::operator /= (const IVec4& _IVec)
{
	x /= _IVec.x;
	y /= _IVec.y;
	z /= _IVec.z;
	w /= _IVec.w;
	return *this;
}

//SCALER TO Vec2 OPERATIONS
inline Maths::IVec4 Maths::IVec4::operator + (const int _Sca) const
{
	return IVec2(x + _Sca, y + _Sca, z + _Sca, w + _Sca);
}
inline Maths::IVec4 Maths::IVec4::operator - (const int _Sca) const
{
	return IVec2(x - _Sca, y - _Sca, z - _Sca, w - _Sca);
}
inline Maths::IVec4 Maths::IVec4::operator * (const int _Sca) const
{
	return IVec2(x * _Sca, y * _Sca, z * _Sca, w * _Sca);
}
inline Maths::IVec4 Maths::IVec4::operator / (const int _Sca) const
{
	return IVec2(x / _Sca, y / _Sca, z / _Sca, w / _Sca);
}

//SCALER TO THIS OPERATIONS
inline Maths::IVec4 Maths::IVec4::operator += (const int _Sca)
{
	x += _Sca;
	y += _Sca;
	z += _Sca;
	w += _Sca;
	return *this;
}
inline Maths::IVec4 Maths::IVec4::operator -= (const int _Sca)
{
	x -= _Sca;
	y -= _Sca;
	z -= _Sca;
	w -= _Sca;
	return *this;
}
inline Maths::IVec4 Maths::IVec4::operator *= (const int _Sca)
{
	x *= _Sca;
	y *= _Sca;
	z *= _Sca;
	w *= _Sca;
	return *this;
}
inline Maths::IVec4 Maths::IVec4::operator /= (const int _Sca)
{
	x /= _Sca;
	y /= _Sca;
	z /= _Sca;
	w /= _Sca;
	return *this;
}
#pragma endregion IVec4
#endif // ENABLE_IVEC4


#if ENABLE_MAT3
/************************\
 *-------MATRIX_3-------*
\************************/
#pragma region Mat3
//CONSTRUCTORS
inline Maths::Mat3::Mat3(void)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			data[x][y] = 0;
		}
	}
}
inline Maths::Mat3::Mat3(float* p_data, long int sizeOfData)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (x + y * 3 < sizeOfData)  data[x][y] = p_data[x + y * 3];
			else data[x][y] = 0;
		}
	}
}

//DESTRUCTOR
inline Maths::Mat3::~Mat3(void) {}

//UTILS

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::Mat3 Maths::Mat3::operator=(Mat3 _Mat)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			data[x][y] = _Mat.data[x][y];
		}
	}
	return *this;
}

//Mat3 TO Mat3 OPERATIONS
inline Maths::Mat3 Maths::Mat3::operator+(Mat3 _Mat) const
{
	Mat3 temp;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			temp.data[x][y] = data[x][y] + _Mat.data[x][y];
		}
	}
	return temp;
}
inline Maths::Mat3 Maths::Mat3::operator-(Mat3 _Mat) const
{
	Mat3 temp;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			temp.data[x][y] = data[x][y] - _Mat.data[x][y];
		}
	}
	return temp;
}
inline Maths::Mat3 Maths::Mat3::operator*(Mat3 _Mat) const
{
	Mat3 temp;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			temp.data[x][y] = data[0][y] * _Mat.data[x][0] + data[1][y] * _Mat.data[x][1] + data[2][y] * _Mat.data[x][2];
		}
	}
	return temp;
}

//Mat3 TO THIS OPERATIONS
inline Maths::Mat3 Maths::Mat3::operator+=(Mat3 _Mat)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			data[x][y] += _Mat.data[x][y];
		}
	}
	return *this;
}
inline Maths::Mat3 Maths::Mat3::operator-=(Mat3 _Mat)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			data[x][y] -= _Mat.data[x][y];
		}
	}
	return *this;
}
inline Maths::Mat3 Maths::Mat3::operator*=(Mat3 _Mat)
{
	Mat3 temp;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			temp.data[x][y] = data[0][y] * _Mat.data[x][0] + data[1][y] * _Mat.data[x][1] + data[2][y] * _Mat.data[x][2];
		}
	}
	*this = temp;
	return *this;
}
#pragma endregion Mat3
#endif // ENABLE_MAT3


#if ENABLE_MAT4
/************************\
 *-------MATRIX_4-------*
\************************/
#pragma region Mat4
//CONSTRUCTORS
inline Maths::Mat4::Mat4(void)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			data[x][y] = 0;
		}
	}
}
inline Maths::Mat4::Mat4(float* p_data, long int sizeOfData)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (x + y * 4 < sizeOfData)  data[x][y] = p_data[x + y * 4];
			else data[x][y] = 0;
		}
	}
}

//DESTRUCTOR
inline Maths::Mat4::~Mat4(void) {}

//UTILS
inline float* Maths::Mat4::GetData()
{
	return *data;
}

//ASSINGMENT AND EQUALITY OPERATIONS
inline Maths::Mat4 Maths::Mat4::operator=(float p_newData[16]) 
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (x + y * 4 < 16)  data[x][y] = p_newData[x + y * 4];
			else data[x][y] = 0;
		}
	}
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator=(Mat4 _Mat)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			data[x][y] = _Mat.data[x][y];
		}
	}
	return *this;
}

//Mat4 TO Mat4 OPERATIONS
inline Maths::Mat4 Maths::Mat4::operator+(Mat4 _Mat) const
{
	Mat4 temp;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			temp.data[x][y] = data[x][y] + _Mat.data[x][y];
		}
	}
	return temp;
}
inline Maths::Mat4 Maths::Mat4::operator-(Mat4 _Mat) const
{
	Mat4 temp;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			temp.data[x][y] = data[x][y] - _Mat.data[x][y];
		}
	}
	return temp;
}
inline Maths::Mat4 Maths::Mat4::operator*(Mat4 _Mat) const
{
	Mat4 temp;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			temp.data[x][y] = data[0][y] * _Mat.data[x][0] + data[1][y] * _Mat.data[x][1] + data[2][y] * _Mat.data[x][2] + data[3][y] * _Mat.data[x][3];
		}
	}
	return temp;
}

//Mat4 TO THIS OPERATIONS
inline Maths::Mat4 Maths::Mat4::operator+=(Mat4 _Mat)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			data[x][y] += _Mat.data[x][y];
		}
	}
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator-=(Mat4 _Mat)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			data[x][y] -= _Mat.data[x][y];
		}
	}
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator*=(Mat4 _Mat)
{
	Mat4 temp;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			temp.data[x][y] = data[0][y] * _Mat.data[x][0] + data[1][y] * _Mat.data[x][1] + data[2][y] * _Mat.data[x][2] + data[3][y] * _Mat.data[x][3];
		}
	}
	*this = temp;
	return *this;
}

#pragma endregion Mat4
#endif // ENABLE_MAT4