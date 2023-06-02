/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 02/06/2023                      *
\***********************************************/
#include "Maths.hpp"

#include <cmath>

// Vector Using float as Value -----------------------------------------------------------------------------

#ifndef DISABLE_VEC2
/************************\
 *-------VECTOR_2-------*
\************************/
#pragma region Vec2
//CONSTRUCTORS :

inline Maths::Vec2::Vec2(void) : x(0), y(0) {}
inline Maths::Vec2::Vec2(float xy) : x(xy), y(xy) {}
inline Maths::Vec2::Vec2(float x, float y) : x(x), y(y) {}
#ifndef DISABLE_VEC3
inline Maths::Vec2::Vec2(const Vec3& _Vec3) : x(_Vec3.x), y(_Vec3.y) {}
#endif
#ifndef DISABLE_VEC4
inline Maths::Vec2::Vec2(const Vec4& _Vec4) : x(_Vec4.x), y(_Vec4.y) {}
#endif

//DESTRUCTOR :

inline Maths::Vec2::~Vec2(void) {}

//UTILS :

inline float Maths::Vec2::GetMagnitude()                                   const
{
	return sqrtf(GetMagnitudeSquared());
}
inline float Maths::Vec2::GetMagnitudeSquared()                            const
{
	return (x * x + y * y);
}
inline void Maths::Vec2::Normalize()
{
	float i = GetMagnitude();
	if (i != 0)
	{
		operator/=(i);
	}
}
inline Maths::Vec2 Maths::Vec2::GetNormalized()                            const
{
	float i = GetMagnitude();
	if (i != 0)
	{
		return operator/(i);
	}
	return *this;
}
inline Maths::Vec2 Maths::Vec2::GetPerpendicular()                         const
{
	return(-y, x);
}
inline float Maths::Vec2::DotProduct(const Vec2& _VecB)                    const
{
	return (float)(x * _VecB.x + y * _VecB.y);
}
inline float Maths::Vec2::DotProduct(const Vec2& _VecA, const Vec2& _VecB)
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y);
}
inline float Maths::Vec2::GetDistance(const Vec2& _VecB)                   const
{
	return Vec2(_VecB.x - x, _VecB.y - y).GetMagnitude();
}
inline float Maths::Vec2::GetDistance(const Vec2& _VecA, const Vec2& _VecB)
{
	return Vec2(_VecB.x - _VecA.x, _VecB.y - _VecA.y).GetMagnitude();
}
inline float Maths::Vec2::GetAngleBetween(const Vec2& _VecB)               const
{
	return (std::acosf(DotProduct(_VecB) / (GetMagnitude() * _VecB.GetMagnitude()))) * RAD2DEG;
}
inline float Maths::Vec2::GetAngleBetween(const Vec2& _VecA, const Vec2& _VecB)
{
	return (std::acosf(DotProduct(_VecA, _VecB) / (_VecA.GetMagnitude() * _VecB.GetMagnitude()))) * RAD2DEG;
}

//ASSINGMENT AND EQUALITY OPERATIONS :

inline Maths::Vec2 Maths::Vec2::operator = (const Vec2& _Vec)
{
	x = _Vec.x;
	y = _Vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator = (float _Sca)
{
	x = _Sca;
	y = _Sca;
	return *this;
}

inline Maths::Vec2 Maths::Vec2::operator - (void)       const
{
	return (Vec2)(-x, -y);
}
inline bool Maths::Vec2::operator == (const Vec2& _Vec) const
{
	return (x == _Vec.x) && (y == _Vec.y);
}
inline bool Maths::Vec2::operator != (const Vec2& _Vec) const
{
	return (x != _Vec.x) || (y != _Vec.y);
}

//Vec2 TO Vec2 OPERATIONS :

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

//Vec2 TO THIS OPERATIONS :

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

//SCALER TO Vec2 OPERATIONS :

inline Maths::Vec2 Maths::Vec2::operator + (float _Sca) const
{
	return Vec2(x + _Sca, y + _Sca);
}
inline Maths::Vec2 Maths::Vec2::operator - (float _Sca) const
{
	return Vec2(x - _Sca, y - _Sca);
}
inline Maths::Vec2 Maths::Vec2::operator * (float _Sca) const
{
	return Vec2(x * _Sca, y * _Sca);
}
inline Maths::Vec2 Maths::Vec2::operator / (float _Sca) const
{
	return Vec2(x / _Sca, y / _Sca);
}

//SCALER TO THIS OPERATIONS :

inline Maths::Vec2 Maths::Vec2::operator += (float _Sca)
{
	x += _Sca;
	y += _Sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator -= (float _Sca)
{
	x -= _Sca;
	y -= _Sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator *= (float _Sca)
{
	x *= _Sca;
	y *= _Sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator /= (float _Sca)
{
	x /= _Sca;
	y /= _Sca;
	return *this;
}
#pragma endregion Vec2
#endif

#ifndef DISABLE_VEC3
/************************\
 *-------VECTOR_3-------*
\************************/
#pragma region Vec3
//CONSTRUCTORS :

inline Maths::Vec3::Vec3(void) : x(0), y(0), z(0) {}
inline Maths::Vec3::Vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}
inline Maths::Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
#ifndef DISABLE_VEC2
inline Maths::Vec3::Vec3(const Vec2& _Vec2) : x(_Vec2.x), y(_Vec2.y), z(0) {}
inline Maths::Vec3::Vec3(const Vec2& _Vec2, float z) : x(_Vec2.x), y(_Vec2.y), z(z) {}
#endif
#ifndef DISABLE_VEC4
inline Maths::Vec3::Vec3(const Vec4& _Vec4) : x(_Vec4.x), y(_Vec4.y), z(_Vec4.z) {}
#endif

//DESTRUCTOR :

inline Maths::Vec3::~Vec3(void) {}

//UTILS :

inline Maths::Vec2 Maths::Vec3::xy() const
{
	return { x, y };
}
inline Maths::Vec2 Maths::Vec3::xz() const
{
	return { x, z };
}
inline Maths::Vec2 Maths::Vec3::yz() const
{
	return { y, z };
}

inline float Maths::Vec3::GetMagnitude()                                           const
{
	return sqrtf(GetMagnitudeSquared());
}
inline float Maths::Vec3::GetMagnitudeSquared()                                    const
{
	return (x * x + y * y + z * z);
}
inline void Maths::Vec3::Normalize()
{
	float i = GetMagnitude();
	if (i != 0)
	{
		operator/=(i);
	}
}
inline Maths::Vec3 Maths::Vec3::GetNormalized()                                    const
{
	float i = GetMagnitude();
	if (i != 0)
	{
		return operator/(i);
	}
	return *this;
}
inline float Maths::Vec3::DotProduct(const Vec3& _VecB)                            const
{
	return (float)(x * _VecB.x + y * _VecB.y + z * _VecB.z);
}
inline float Maths::Vec3::DotProduct(const Vec3& _VecA, const Vec3& _VecB)
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y + _VecA.z * _VecB.z);
}
inline Maths::Vec3 Maths::Vec3::CrossProduct(const Vec3& _VecB)                    const
{
	return { y * _VecB.z - z * _VecB.y, z * _VecB.x - x * _VecB.z, x * _VecB.y - y * _VecB.x };
}
inline Maths::Vec3 Maths::Vec3::CrossProduct(const Vec3& _VecA, const Vec3& _VecB)
{
	return { _VecA.y * _VecB.z - _VecA.z * _VecB.y, _VecA.z * _VecB.x - _VecA.x * _VecB.z, _VecA.x * _VecB.y - _VecA.y * _VecB.x };
}
inline float Maths::Vec3::GetDistance(const Vec3& _VecB)                           const
{
	return Vec3(_VecB.x - x, _VecB.y - y, _VecB.z - z).GetMagnitude();
}
inline float Maths::Vec3::GetDistance(const Vec3& _VecA, const Vec3& _VecB)
{
	return Vec3(_VecB.x - _VecA.x, _VecB.y - _VecA.y, _VecB.z - _VecA.z).GetMagnitude();
}
inline float Maths::Vec3::GetAngleBetween(const Vec3& _VecB)                       const
{
	return (std::acosf(DotProduct(_VecB) / (GetMagnitude() * _VecB.GetMagnitude()))) * RAD2DEG;
}
inline float Maths::Vec3::GetAngleBetween(const Vec3& _VecA, const Vec3& _VecB)
{
	return (std::acosf(DotProduct(_VecA, _VecB) / (_VecA.GetMagnitude() * _VecB.GetMagnitude()))) * RAD2DEG;
}

//ASSINGMENT AND EQUALITY OPERATIONS :

inline Maths::Vec3 Maths::Vec3::operator = (const Vec3& _Vec)
{
	x = _Vec.x;
	y = _Vec.y;
	z = _Vec.z;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator = (float _Sca)
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

//Vec3 TO Vec3 OPERATIONS :

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

//Vec3 TO THIS OPERATIONS :

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

//SCALER TO Vec3 OPERATIONS :

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

//SCALER TO THIS OPERATIONS :

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
#endif

#ifndef DISABLE_VEC4
/************************\
 *-------VECTOR_4-------*
\************************/
#pragma region Vec4
//CONSTRUCTORS :

inline Maths::Vec4::Vec4(void) : x(0), y(0), z(0), w(0) {}
inline Maths::Vec4::Vec4(const float xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
inline Maths::Vec4::Vec4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}
#ifndef DISABLE_VEC2
inline Maths::Vec4::Vec4(const Vec2& _Vec2) : x(_Vec2.x), y(_Vec2.y), z(0), w(0) {}
#endif
#ifndef DISABLE_VEC3
inline Maths::Vec4::Vec4(const Vec3& _Vec3) : x(_Vec3.x), y(_Vec3.y), z(_Vec3.z), w(0) {}
inline Maths::Vec4::Vec4(const Vec3& _Vec3, float w) : x(_Vec3.x), y(_Vec3.y), z(_Vec3.z), w(w) {}
#endif

//DESTRUCTOR :

inline Maths::Vec4::~Vec4(void) { }

//UTILS :

inline Maths::Vec3 Maths::Vec4::xyz()	const
{
	return Vec3(x, y, z);
}
inline Maths::Vec3 Maths::Vec4::xzw()	const
{
	return Vec3(x, z, w);
}
inline Maths::Vec3 Maths::Vec4::xyw()	const
{
	return Vec3(x, y, w);
}
inline Maths::Vec3 Maths::Vec4::yzw()	const
{
	return Vec3(y, z, w);
}

inline float Maths::Vec4::GetMagnitude()                                   const
{
	return sqrtf(GetMagnitudeSquared());
}
inline float Maths::Vec4::GetMagnitudeSquared()                            const
{
	return (x * x + y * y + z * z + w * w);
}
inline void Maths::Vec4::Normalize()
{
	float i = GetMagnitude();
	if (i != 0)
	{
		operator/=(i);
	}
}
inline Maths::Vec4 Maths::Vec4::GetNormalized()                            const
{
	float i = GetMagnitude();
	if (i != 0)
	{
		return operator/(i);
	}
	return *this;
}
inline float Maths::Vec4::DotProduct(const Vec4& _VecB)                    const
{
	return (float)(x * _VecB.x + y * _VecB.y + z * _VecB.z + w * _VecB.w);
}
inline float Maths::Vec4::DotProduct(const Vec4& _VecA, const Vec4& _VecB)
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y + _VecA.z * _VecB.z + _VecA.w * _VecB.w);
}
inline void Maths::Vec4::Homogenize()
{
	if (w == 0)
		return;
	operator/=(w);
}
inline Maths::Vec4 Maths::Vec4::GetHomogenized()                           const
{
	if (w == 0)
		return { x, y, z, w };
	return { x / w, y / w, z / w, 1 };
}


//ASSINGMENT AND EQUALITY OPERATIONS :

inline Maths::Vec4 Maths::Vec4::operator = (const Vec4& _Vec)
{
	x = _Vec.x;
	y = _Vec.y;
	z = _Vec.z;
	w = _Vec.w;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator = (float _Sca)
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

//Vec4 TO Vec4 OPERATIONS :

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

//Vec4 TO THIS OPERATIONS :

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

//SCALER TO Vec4 OPERATIONS :

inline Maths::Vec4 Maths::Vec4::operator + (float _Sca) const
{
	return Vec4(x + _Sca, y + _Sca, z + _Sca, w + _Sca);
}
inline Maths::Vec4 Maths::Vec4::operator - (float _Sca) const
{
	return Vec4(x - _Sca, y - _Sca, z - _Sca, w - _Sca);
}
inline Maths::Vec4 Maths::Vec4::operator * (float _Sca) const
{
	return Vec4(x * _Sca, y * _Sca, z * _Sca, w * _Sca);
}
inline Maths::Vec4 Maths::Vec4::operator / (float _Sca) const
{
	return Vec4(x / _Sca, y / _Sca, z / _Sca, w / _Sca);
}

//SCALER TO THIS OPERATIONS :

inline Maths::Vec4 Maths::Vec4::operator += (float _Sca)
{
	x += _Sca;
	y += _Sca;
	z += _Sca;
	w += _Sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator -= (float _Sca)
{
	x -= _Sca;
	y -= _Sca;
	z -= _Sca;
	w -= _Sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator *= (float _Sca)
{
	x *= _Sca;
	y *= _Sca;
	z *= _Sca;
	w *= _Sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator /= (float _Sca)
{
	x /= _Sca;
	y /= _Sca;
	z /= _Sca;
	w /= _Sca;
	return *this;
}
#pragma endregion Vec4
#endif

// Vector Using int as Value -------------------------------------------------------------------------------

#ifndef DISABLE_IVEC2
/************************\
 *------IVECTOR_2-------*
\************************/
#pragma region IVec2
//CONSTRUCTORS :

inline Maths::IVec2::IVec2(void) : x(0), y(0) {}
inline Maths::IVec2::IVec2(const int xy) : x(xy), y(xy) {}
inline Maths::IVec2::IVec2(const int x, const int y) : x(x), y(y) {}
#ifndef DISABLE_VEC2
inline Maths::IVec2::IVec2(const class Vec2& _Vec2) : x(static_cast<int>(_Vec2.x)), y(static_cast<int>(_Vec2.y)) {}
#endif

//DESTRUCTOR :

inline Maths::IVec2::~IVec2(void) {}

//UTILS :

inline float Maths::IVec2::GetMagnitude()      const
{
	return sqrtf(static_cast<float>(GetMagnitudeSquared()));
}
inline int Maths::IVec2::GetMagnitudeSquared() const
{
	return (x * x + y * y);
}

//ASSINGMENT AND EQUALITY OPERATIONS :

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

inline Maths::IVec2 Maths::IVec2::operator - (void)			const
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

//IVec2 TO IVec2 OPERATIONS :

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

//IVec2 TO THIS OPERATIONS :

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

//SCALER TO IVec2 OPERATIONS :

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

//SCALER TO THIS OPERATIONS :

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
#endif

#ifndef DISABLE_IVEC3
/************************\
 *------IVECTOR_3-------*
\************************/
#pragma region IVec3
//CONSTRUCTORS :

inline Maths::IVec3::IVec3(void) : x(0), y(0), z(0) {}
inline Maths::IVec3::IVec3(const int xyz) : x(xyz), y(xyz), z(xyz) {}
inline Maths::IVec3::IVec3(const int x, const int y, const int z) : x(x), y(y), z(z) {}
#ifndef DISABLE_VEC3
inline Maths::IVec3::IVec3(const class Vec3& _Vec3) : x(static_cast<int>(_Vec3.x)), y(static_cast<int>(_Vec3.y)), z(static_cast<int>(_Vec3.z)) {}
#endif

//DESTRUCTOR :

inline Maths::IVec3::~IVec3(void) {}

//UTILS :

inline float Maths::IVec3::GetMagnitude()      const
{
	return sqrtf(static_cast<float>(GetMagnitudeSquared()));
}
inline int Maths::IVec3::GetMagnitudeSquared() const
{
	return (x * x + y * y + z * z);
}

//ASSINGMENT AND EQUALITY OPERATIONS :

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

inline Maths::IVec3 Maths::IVec3::operator - (void)			const
{
	return IVec3(-x, -y, -z);
}
inline bool Maths::IVec3::operator == (const IVec3& _IVec)	const
{
	return (x == _IVec.x) && (y == _IVec.y) && (z == _IVec.z);
}
inline bool Maths::IVec3::operator != (const IVec3& _IVec)	const
{
	return (x != _IVec.x) || (y != _IVec.y) || (z != _IVec.z);
}

//IVec3 TO IVec3 OPERATIONS :

inline Maths::IVec3 Maths::IVec3::operator + (const IVec3& _IVec) const
{
	return IVec3(x + _IVec.x, y + _IVec.y, z + _IVec.z);
}
inline Maths::IVec3 Maths::IVec3::operator - (const IVec3& _IVec) const
{
	return IVec3(x - _IVec.x, y - _IVec.y, z - _IVec.z);
}
inline Maths::IVec3 Maths::IVec3::operator * (const IVec3& _IVec) const
{
	return IVec3(x * _IVec.x, y * _IVec.y, z * _IVec.z);
}
inline Maths::IVec3 Maths::IVec3::operator / (const IVec3& _IVec) const
{
	return IVec3(x / _IVec.x, y / _IVec.y, z / _IVec.z);
}

//IVec3 TO THIS OPERATIONS :

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

//SCALER TO IVec3 OPERATIONS :

inline Maths::IVec3 Maths::IVec3::operator + (const int _Sca) const
{
	return IVec3(x + _Sca, y + _Sca, z + _Sca);
}
inline Maths::IVec3 Maths::IVec3::operator - (const int _Sca) const
{
	return IVec3(x - _Sca, y - _Sca, z - _Sca);
}
inline Maths::IVec3 Maths::IVec3::operator * (const int _Sca) const
{
	return IVec3(x * _Sca, y * _Sca, z * _Sca);
}
inline Maths::IVec3 Maths::IVec3::operator / (const int _Sca) const
{
	return IVec3(x / _Sca, y / _Sca, z / _Sca);
}

//SCALER TO THIS OPERATIONS :

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
#endif

#ifndef DISABLE_IVEC4
/************************\
 *------IVECTOR_4-------*
\************************/
#pragma region IVec4
//CONSTRUCTORS :

inline Maths::IVec4::IVec4(void) : x(0), y(0), z(0), w(0) {}
inline Maths::IVec4::IVec4(const int xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
inline Maths::IVec4::IVec4(const int x, const int y, const int z, const int w) : x(x), y(y), z(z), w(w) {}
#ifndef DISABLE_VEC4
inline Maths::IVec4::IVec4(const class Vec4& _Vec4) : x(static_cast<int>(_Vec4.x)), y(static_cast<int>(_Vec4.y)), z(static_cast<int>(_Vec4.z)), w(static_cast<int>(_Vec4.w)) {}
#endif

//DESTRUCTOR :

inline Maths::IVec4::~IVec4(void) {}

//UTILS :

inline float Maths::IVec4::GetMagnitude()      const
{
	return sqrtf(static_cast<float>(GetMagnitudeSquared()));
}
inline int Maths::IVec4::GetMagnitudeSquared() const
{
	return (x * x + y * y + z * z + w * w);
}

//ASSINGMENT AND EQUALITY OPERATIONS :

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

inline Maths::IVec4 Maths::IVec4::operator - (void)			const
{
	return IVec4(-x, -y, -z, -w);
}
inline bool Maths::IVec4::operator == (const IVec4& _IVec)	const
{
	return (x == _IVec.x) && (y == _IVec.y) && (z == _IVec.z) && (w == _IVec.w);
}
inline bool Maths::IVec4::operator != (const IVec4& _IVec)	const
{
	return (x != _IVec.x) || (y != _IVec.y) || (z != _IVec.z) || (w != _IVec.w);
}

//IVec4 TO Vec2 OPERATIONS :

inline Maths::IVec4 Maths::IVec4::operator + (const IVec4& _IVec) const
{
	return IVec4(x + _IVec.x, y + _IVec.y, z + _IVec.z, w + _IVec.w);
}
inline Maths::IVec4 Maths::IVec4::operator - (const IVec4& _IVec) const
{
	return IVec4(x - _IVec.x, y - _IVec.y, z - _IVec.z, w - _IVec.w);
}
inline Maths::IVec4 Maths::IVec4::operator * (const IVec4& _IVec) const
{
	return IVec4(x * _IVec.x, y * _IVec.y, z * _IVec.z, w * _IVec.w);
}
inline Maths::IVec4 Maths::IVec4::operator / (const IVec4& _IVec) const
{
	return IVec4(x / _IVec.x, y / _IVec.y, z / _IVec.z, w / _IVec.w);
}

//IVec4 TO THIS OPERATIONS :

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

//SCALER TO IVec4 OPERATIONS :

inline Maths::IVec4 Maths::IVec4::operator + (const int _Sca) const
{
	return IVec4(x + _Sca, y + _Sca, z + _Sca, w + _Sca);
}
inline Maths::IVec4 Maths::IVec4::operator - (const int _Sca) const
{
	return IVec4(x - _Sca, y - _Sca, z - _Sca, w - _Sca);
}
inline Maths::IVec4 Maths::IVec4::operator * (const int _Sca) const
{
	return IVec4(x * _Sca, y * _Sca, z * _Sca, w * _Sca);
}
inline Maths::IVec4 Maths::IVec4::operator / (const int _Sca) const
{
	return IVec4(x / _Sca, y / _Sca, z / _Sca, w / _Sca);
}

//SCALER TO THIS OPERATIONS :

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
#endif

// Matrix --------------------------------------------------------------------------------------------------

#ifndef DISABLE_MAT3
/************************\
 *-------MATRIX_3-------*
\************************/
#pragma region Mat3
//CONSTRUCTORS :

inline Maths::Mat3::Mat3(void)
{
	for (int i = 0; i < 9; i++)
	{
		data[i] = 0;
	}
}
inline Maths::Mat3::Mat3(float _data[9])
{
	for (int i = 0; i < 9; i++)
	{
		data[i] = _data[i];
	}
}

//DESTRUCTOR :

inline Maths::Mat3::~Mat3(void) {}

//UTILS :

inline void Maths::Mat3::Transpose()
{
	Mat3 temp;

	temp.data_3_3[0][0] = data_3_3[0][0];
	temp.data_3_3[1][0] = data_3_3[0][1];
	temp.data_3_3[2][0] = data_3_3[0][2];
	temp.data_3_3[0][1] = data_3_3[1][0];
	temp.data_3_3[1][1] = data_3_3[1][1];
	temp.data_3_3[2][1] = data_3_3[1][2];
	temp.data_3_3[0][2] = data_3_3[2][0];
	temp.data_3_3[1][2] = data_3_3[2][1];
	temp.data_3_3[2][2] = data_3_3[2][2];
	
	*this = temp;
}
inline static Maths::Mat3 Maths::Mat3::GetTranspose(const Mat3& _Mat)                                                          const
{
	Mat3 temp;

	temp.data_3_3[0][0] = _Mat.data_3_3[0][0];
	temp.data_3_3[1][0] = _Mat.data_3_3[0][1];
	temp.data_3_3[2][0] = _Mat.data_3_3[0][2];
	temp.data_3_3[0][1] = _Mat.data_3_3[1][0];
	temp.data_3_3[1][1] = _Mat.data_3_3[1][1];
	temp.data_3_3[2][1] = _Mat.data_3_3[1][2];
	temp.data_3_3[0][2] = _Mat.data_3_3[2][0];
	temp.data_3_3[1][2] = _Mat.data_3_3[2][1];
	temp.data_3_3[2][2] = _Mat.data_3_3[2][2];

	return temp;
}
inline float Maths::Mat3::Determinant()                                                                                        const
{
	return data_3_3[0][0] * (data_3_3[1][1] * data_3_3[2][2] - data_3_3[2][1] * data_3_3[1][2])
		 - data_3_3[0][1] * (data_3_3[1][0] * data_3_3[2][2] - data_3_3[2][0] * data_3_3[1][2])
		 + data_3_3[0][2] * (data_3_3[1][0] * data_3_3[2][1] - data_3_3[2][0] * data_3_3[1][1]);
}
inline void Maths::Mat3::Inverse()
{
	float det = Determinant();
	if (det != 0.f)
	{
		det = 1.f / det;

		Mat3 temp;
		temp.data_3_3[0][0] = (data_3_3[1][1] * data_3_3[2][2] - data_3_3[2][1] * data_3_3[1][2]) * det;
		temp.data_3_3[0][1] = (data_3_3[0][2] * data_3_3[2][1] - data_3_3[0][1] * data_3_3[2][2]) * det;
		temp.data_3_3[0][2] = (data_3_3[0][1] * data_3_3[1][2] - data_3_3[0][2] * data_3_3[1][1]) * det;
		temp.data_3_3[1][0] = (data_3_3[1][2] * data_3_3[2][0] - data_3_3[1][0] * data_3_3[2][2]) * det;
		temp.data_3_3[1][1] = (data_3_3[0][0] * data_3_3[2][2] - data_3_3[0][2] * data_3_3[2][0]) * det;
		temp.data_3_3[1][2] = (data_3_3[1][0] * data_3_3[0][2] - data_3_3[0][0] * data_3_3[1][2]) * det;
		temp.data_3_3[2][0] = (data_3_3[1][0] * data_3_3[2][1] - data_3_3[2][0] * data_3_3[1][1]) * det;
		temp.data_3_3[2][1] = (data_3_3[2][0] * data_3_3[0][1] - data_3_3[0][0] * data_3_3[2][1]) * det;
		temp.data_3_3[2][2] = (data_3_3[0][0] * data_3_3[1][1] - data_3_3[1][0] * data_3_3[0][1]) * det;
		*this = temp;
	}
}
inline static Maths::Mat3 Maths::Mat3::GetInverse(const Mat3& _Mat)                                                            const
{
	float det = _Mat.Determinant();
	if (det != 0.f)
	{
		det = 1.f / det;

		Mat3 temp;
		temp.data_3_3[0][0] = (data_3_3[1][1] * data_3_3[2][2] - data_3_3[2][1] * data_3_3[1][2]) * det;
		temp.data_3_3[0][1] = (data_3_3[0][2] * data_3_3[2][1] - data_3_3[0][1] * data_3_3[2][2]) * det;
		temp.data_3_3[0][2] = (data_3_3[0][1] * data_3_3[1][2] - data_3_3[0][2] * data_3_3[1][1]) * det;
		temp.data_3_3[1][0] = (data_3_3[1][2] * data_3_3[2][0] - data_3_3[1][0] * data_3_3[2][2]) * det;
		temp.data_3_3[1][1] = (data_3_3[0][0] * data_3_3[2][2] - data_3_3[0][2] * data_3_3[2][0]) * det;
		temp.data_3_3[1][2] = (data_3_3[1][0] * data_3_3[0][2] - data_3_3[0][0] * data_3_3[1][2]) * det;
		temp.data_3_3[2][0] = (data_3_3[1][0] * data_3_3[2][1] - data_3_3[2][0] * data_3_3[1][1]) * det;
		temp.data_3_3[2][1] = (data_3_3[2][0] * data_3_3[0][1] - data_3_3[0][0] * data_3_3[2][1]) * det;
		temp.data_3_3[2][2] = (data_3_3[0][0] * data_3_3[1][1] - data_3_3[1][0] * data_3_3[0][1]) * det;
		return temp;
	}
	return _Mat;
}
inline float Maths::Mat3::Trace()                                                                                              const
{
	return data_3_3[0][0] + data_3_3[1][1] + data_3_3[2][2];
}

inline static Maths::Mat3 Maths::Mat3::CreateIdentityMatrix()                                                                  const
{
	Mat3 temp;

	temp.data_3_3[0][0] = 1.f;
	temp.data_3_3[1][1] = 1.f;
	temp.data_3_3[2][2] = 1.f;

	return temp;
}
inline static Maths::Mat3 Maths::Mat3::CreateRotationMatrix(float rotation)                                                    const
{
	float cosRot = cosf(rotation);
	float sinRot = sinf(rotation);

	Mat3 temp;

	temp.data_3_3[0][0] = cosRot;
	temp.data_3_3[0][1] = -sinRot;
	temp.data_3_3[1][0] = sinRot;
	temp.data_3_3[1][1] = cosRot;
	temp.data_3_3[2][2] = cosRot;

	return temp;
}
#ifndef DISABLE_VEC2
inline static Maths::Mat3 Maths::Mat3::CreateTranslationMatrix(const Vec2& translation)                                        const
{
	Mat3 temp;

	temp.data_3_3[0][0] = 1.f;
	temp.data_3_3[1][1] = 1.f;
	temp.data_3_3[2][2] = 1.f;

	temp.data_3_3[0][2] = translation.x;
	temp.data_3_3[1][2] = translation.y;

	return temp;
}
inline static Maths::Mat3 Maths::Mat3::CreateScaleMatrix(const Vec2& scale)                                                    const
{
	Mat3 temp;

	temp.data_3_3[0][0] = scale.x;
	temp.data_3_3[1][1] = scale.y;
	temp.data_3_3[2][2] = 1.f;

	return temp;
}
inline static Maths::Mat3 Maths::Mat3::CreateTransformMatrix(const Vec2& translation, float rotation, const Vec2& scale)       const
{
	return CreateTranslationMatrix(translation) * CreateScaleMatrix(scale) * CreateRotationMatrix(rotation);
}
#else
inline static Maths::Mat3 Maths::Mat3::CreateTranslationMatrix(float[2] translation)                                           const
{
	Mat3 temp;

	temp.data_3_3[0][0] = 1.f;
	temp.data_3_3[1][1] = 1.f;
	temp.data_3_3[2][2] = 1.f;

	temp.data_3_3[0][2] = translation[0];
	temp.data_3_3[1][2] = translation[1];

	return temp;
}
inline static Maths::Mat3 Maths::Mat3::CreateScaleMatrix(float[2] scale)                                                      const
{
	Mat3 temp;

	temp.data_3_3[0][0] = scale[0];
	temp.data_3_3[1][1] = scale[1];
	temp.data_3_3[2][2] = 1.f;

	return temp;
}
inline static Maths::Mat3 Maths::Mat3::CreateTransformMatrix(float[2] translation, float rotation, float[2] scale)            const
{
	return CreateTranslationMatrix(translation) * CreateScaleMatrix(scale) * CreateRotationMatrix(rotation);
}
#endif

inline Maths::Mat3 Maths::Mat3::HadamardProduct(const Mat3& _Mat)                                                              const
{
	Mat3 temp;

	for (int i = 0; i < 9 i++)
		temp.data[i] = data[i] * _Mat.data[i];

	return temp;
}
inline Maths::Mat3 Maths::Mat3::HadamardProductToThis(const Mat3& _Mat)
{
	for (int i = 0; i < 9 i++)
		data[i] *= _Mat.data[i];
	
	return *this;
}

//ASSINGMENT AND EQUALITY OPERATIONS :

inline Maths::Mat3 Maths::Mat3::operator=(float _data[9])
{
	for (int i = 0; i < 9; i++)
	{
		data[i] = _data[i];
	}
	return *this;
}

inline Maths::Mat3 Maths::Mat3::operator=(const Mat3& _Mat)
{
	for (int i = 0; i < 9; i++)
	{
		data[i] = _Mat.data[i];
	}
	return *this;
}

//Mat3 TO Mat3 OPERATIONS :

inline Maths::Mat3 Maths::Mat3::operator+(const Mat3& _Mat) const
{
	Mat3 temp;
	for (int i = 0; i < 9; i++)
	{
		temp.data[i] = data[i] + _Mat.data[i];
	}
	return temp;
}
inline Maths::Mat3 Maths::Mat3::operator-(const Mat3& _Mat) const
{
	Mat3 temp;
	for (int i = 0; i < 9; i++)
	{
		temp.data[i] = data[i] - _Mat.data[i];
	}
	return temp;
}
inline Maths::Mat3 Maths::Mat3::operator*(const Mat3& _Mat) const
{
	Mat3 temp;

	temp.data[0] = data[0] * _Mat.data[0] + data[3] * _Mat.data[1] + data[6] * _Mat.data[2];
	temp.data[1] = data[1] * _Mat.data[0] + data[4] * _Mat.data[1] + data[7] * _Mat.data[2];
	temp.data[2] = data[2] * _Mat.data[0] + data[5] * _Mat.data[1] + data[8] * _Mat.data[2];

	temp.data[3] = data[0] * _Mat.data[3] + data[3] * _Mat.data[4] + data[6] * _Mat.data[5];
	temp.data[4] = data[1] * _Mat.data[3] + data[4] * _Mat.data[4] + data[7] * _Mat.data[5];
	temp.data[5] = data[2] * _Mat.data[3] + data[5] * _Mat.data[4] + data[8] * _Mat.data[5];

	temp.data[6] = data[0] * _Mat.data[6] + data[3] * _Mat.data[7] + data[6] * _Mat.data[8];
	temp.data[7] = data[1] * _Mat.data[6] + data[4] * _Mat.data[7] + data[7] * _Mat.data[8];
	temp.data[8] = data[2] * _Mat.data[6] + data[5] * _Mat.data[7] + data[8] * _Mat.data[8];

	return temp;
}

//Mat3 TO THIS OPERATIONS :

inline Maths::Mat3 Maths::Mat3::operator+=(const Mat3& _Mat)
{
	for (int i = 0; i < 9; i++)
	{
		data[i] += _Mat.data[i];
	}
	return *this;
}
inline Maths::Mat3 Maths::Mat3::operator-=(const Mat3& _Mat)
{
	for (int i = 0; i < 9; i++)
	{
		data[i] -= _Mat.data[i];
	}
	return *this;
}
inline Maths::Mat3 Maths::Mat3::operator*=(const Mat3& _Mat)
{
	Mat3 temp;

	temp.data[0] = data[0] * _Mat.data[0] + data[3] * _Mat.data[1] + data[6] * _Mat.data[2];
	temp.data[1] = data[1] * _Mat.data[0] + data[4] * _Mat.data[1] + data[7] * _Mat.data[2];
	temp.data[2] = data[2] * _Mat.data[0] + data[5] * _Mat.data[1] + data[8] * _Mat.data[2];

	temp.data[3] = data[0] * _Mat.data[3] + data[3] * _Mat.data[4] + data[6] * _Mat.data[5];
	temp.data[4] = data[1] * _Mat.data[3] + data[4] * _Mat.data[4] + data[7] * _Mat.data[5];
	temp.data[5] = data[2] * _Mat.data[3] + data[5] * _Mat.data[4] + data[8] * _Mat.data[5];

	temp.data[6] = data[0] * _Mat.data[6] + data[3] * _Mat.data[7] + data[6] * _Mat.data[8];
	temp.data[7] = data[1] * _Mat.data[6] + data[4] * _Mat.data[7] + data[7] * _Mat.data[8];
	temp.data[8] = data[2] * _Mat.data[6] + data[5] * _Mat.data[7] + data[8] * _Mat.data[8];

	*this = temp;
	return *this;
}
#pragma endregion Mat3
#endif

#ifndef DISABLE_MAT4
/************************\
 *-------MATRIX_4-------*
\************************/
#pragma region Mat4
//CONSTRUCTORS :

inline Maths::Mat4::Mat4(void)
{
	for (int i = 0; i < 16; i++)
	{
		data[i] = 0;
	}
}
inline Maths::Mat4::Mat4(float _data[16])
{
	for (int i = 0; i < 16; i++)
	{
		data[i] = _data[i];
	}
}

//DESTRUCTOR :

inline Maths::Mat4::~Mat4(void) {}

//UTILS :

inline void Maths::Mat4::Transpose()
{
	Mat4 temp;

	temp.data_4_4[0][0] = data_4_4[0][0];
	temp.data_4_4[1][0] = data_4_4[0][1];
	temp.data_4_4[2][0] = data_4_4[0][2];
	temp.data_4_4[3][0] = data_4_4[0][3];
	temp.data_4_4[0][1] = data_4_4[1][0];
	temp.data_4_4[1][1] = data_4_4[1][1];
	temp.data_4_4[2][1] = data_4_4[1][2];
	temp.data_4_4[3][1] = data_4_4[1][3];
	temp.data_4_4[0][2] = data_4_4[2][0];
	temp.data_4_4[1][2] = data_4_4[2][1];
	temp.data_4_4[2][2] = data_4_4[2][2];
	temp.data_4_4[3][2] = data_4_4[2][3];
	temp.data_4_4[0][3] = data_4_4[3][0];
	temp.data_4_4[1][3] = data_4_4[3][1];
	temp.data_4_4[2][3] = data_4_4[3][2];
	temp.data_4_4[3][3] = data_4_4[3][3];

	*this = temp;
}
inline static Maths::Mat4 Maths::Mat4::GetTranspose(const Mat4& _Mat) const
{
	Mat4 temp;

	temp.data_4_4[0][0] = _Mat.data_4_4[0][0];
	temp.data_4_4[1][0] = _Mat.data_4_4[0][1];
	temp.data_4_4[2][0] = _Mat.data_4_4[0][2];
	temp.data_4_4[3][0] = _Mat.data_4_4[0][3];
	temp.data_4_4[0][1] = _Mat.data_4_4[1][0];
	temp.data_4_4[1][1] = _Mat.data_4_4[1][1];
	temp.data_4_4[2][1] = _Mat.data_4_4[1][2];
	temp.data_4_4[3][1] = _Mat.data_4_4[1][3];
	temp.data_4_4[0][2] = _Mat.data_4_4[2][0];
	temp.data_4_4[1][2] = _Mat.data_4_4[2][1];
	temp.data_4_4[2][2] = _Mat.data_4_4[2][2];
	temp.data_4_4[3][2] = _Mat.data_4_4[2][3];
	temp.data_4_4[0][3] = _Mat.data_4_4[3][0];
	temp.data_4_4[1][3] = _Mat.data_4_4[3][1];
	temp.data_4_4[2][3] = _Mat.data_4_4[3][2];
	temp.data_4_4[3][3] = _Mat.data_4_4[3][3];

	return temp;
}
inline float Maths::Mat4::Determinant()                               const
{
	return data_4_4[0][0] * (data_4_4[1][1] * (data_4_4[2][2] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][2])
		                   - data_4_4[1][2] * (data_4_4[2][1] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][1])
		                   + data_4_4[1][3] * (data_4_4[2][1] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][1]))
		 - data_4_4[0][1] * (data_4_4[1][0] * (data_4_4[2][2] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][2])
			               - data_4_4[1][2] * (data_4_4[2][0] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][0])
			               + data_4_4[1][3] * (data_4_4[2][0] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][0]))
		 + data_4_4[0][2] * (data_4_4[1][0] * (data_4_4[2][1] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][1])
			               - data_4_4[1][1] * (data_4_4[2][0] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][0])
			               + data_4_4[1][3] * (data_4_4[2][0] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][0]))
		 - data_4_4[0][3] * (data_4_4[1][0] * (data_4_4[2][1] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][1])
		                   - data_4_4[1][1] * (data_4_4[2][0] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][0])
                           + data_4_4[1][2] * (data_4_4[2][0] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][0]));

}
inline void Maths::Mat4::Inverse()
{
	float det = Determinant();
	if (det != 0.f)
	{
		det = 1.f / det;

		Mat4 temp;

		temp.data_4_4[0][0] = (data_4_4[1][1] * (data_4_4[2][2] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][2])
                             - data_4_4[1][2] * (data_4_4[2][1] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][1])
                             + data_4_4[1][3] * (data_4_4[2][1] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][1])) * det;

		temp.data_4_4[0][1] = (data_4_4[0][1] * (data_4_4[2][3] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][3])
                             - data_4_4[0][2] * (data_4_4[2][3] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][3])
                             + data_4_4[0][3] * (data_4_4[2][2] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][2])) * det;

		temp.data_4_4[0][2] = (data_4_4[0][1] * (data_4_4[1][3] * data_4_4[3][2] - data_4_4[1][2] * data_4_4[3][3])
                             - data_4_4[0][2] * (data_4_4[1][3] * data_4_4[3][1] - data_4_4[1][1] * data_4_4[3][3])
                             + data_4_4[0][3] * (data_4_4[1][2] * data_4_4[3][1] - data_4_4[1][1] * data_4_4[3][2])) * det;

		temp.data_4_4[0][3] = (data_4_4[0][1] * (data_4_4[1][2] * data_4_4[2][3] - data_4_4[1][3] * data_4_4[2][2])
                             - data_4_4[0][2] * (data_4_4[1][1] * data_4_4[2][3] - data_4_4[1][3] * data_4_4[2][1])
                             + data_4_4[0][3] * (data_4_4[1][1] * data_4_4[2][2] - data_4_4[1][2] * data_4_4[2][1])) * det;

		temp.data_4_4[1][0] = (data_4_4[1][0] * (data_4_4[2][3] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][3])
                             - data_4_4[1][2] * (data_4_4[2][3] * data_4_4[3][0] - data_4_4[2][0] * data_4_4[3][3])
                             + data_4_4[1][3] * (data_4_4[2][2] * data_4_4[3][0] - data_4_4[2][0] * data_4_4[3][2])) * det;

		temp.data_4_4[1][1] = (data_4_4[0][0] * (data_4_4[2][2] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][2])
                             - data_4_4[0][2] * (data_4_4[2][2] * data_4_4[3][0] - data_4_4[2][0] * data_4_4[3][2])
                             + data_4_4[0][3] * (data_4_4[2][0] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][0])) * det;
		
		temp.data_4_4[1][2] = (data_4_4[0][0] * (data_4_4[1][3] * data_4_4[3][2] - data_4_4[1][2] * data_4_4[3][3])
                             - data_4_4[0][2] * (data_4_4[1][3] * data_4_4[3][0] - data_4_4[1][0] * data_4_4[3][3])
                             + data_4_4[0][3] * (data_4_4[1][2] * data_4_4[3][0] - data_4_4[1][0] * data_4_4[3][2])) * det;
		
		temp.data_4_4[1][3] = (data_4_4[0][0] * (data_4_4[1][2] * data_4_4[2][3] - data_4_4[1][3] * data_4_4[2][2])
                             - data_4_4[0][2] * (data_4_4[1][2] * data_4_4[2][0] - data_4_4[1][0] * data_4_4[2][2])
                             + data_4_4[0][3] * (data_4_4[1][0] * data_4_4[2][2] - data_4_4[1][2] * data_4_4[2][0])) * det;

		temp.data_4_4[2][0] = (data_4_4[1][0] * (data_4_4[2][1] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][1])
                             - data_4_4[1][1] * (data_4_4[2][0] * data_4_4[3][3] - data_4_4[2][3] * data_4_4[3][0])
                             + data_4_4[1][3] * (data_4_4[2][0] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][0])) * det;

		temp.data_4_4[2][1] = (data_4_4[0][0] * (data_4_4[2][3] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][3])
                             - data_4_4[0][1] * (data_4_4[2][3] * data_4_4[3][0] - data_4_4[2][0] * data_4_4[3][3])
                             + data_4_4[0][3] * (data_4_4[2][1] * data_4_4[3][0] - data_4_4[2][0] * data_4_4[3][1])) * det;

		temp.data_4_4[2][2] = (data_4_4[0][0] * (data_4_4[1][1] * data_4_4[3][3] - data_4_4[1][3] * data_4_4[3][1])
                             - data_4_4[0][1] * (data_4_4[1][0] * data_4_4[3][3] - data_4_4[1][3] * data_4_4[3][0])
                             + data_4_4[0][3] * (data_4_4[1][0] * data_4_4[3][1] - data_4_4[1][1] * data_4_4[3][0])) * det;

		temp.data_4_4[2][3] = (data_4_4[0][0] * (data_4_4[1][3] * data_4_4[2][1] - data_4_4[1][1] * data_4_4[2][3])
                             - data_4_4[0][1] * (data_4_4[1][3] * data_4_4[2][0] - data_4_4[1][0] * data_4_4[2][3])
                             + data_4_4[0][3] * (data_4_4[1][1] * data_4_4[2][0] - data_4_4[1][0] * data_4_4[2][1])) * det;

		temp.data_4_4[3][0] = (data_4_4[1][0] * (data_4_4[2][2] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][2])
                             - data_4_4[1][1] * (data_4_4[2][0] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][0])
                             + data_4_4[1][2] * (data_4_4[2][0] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][0])) * det;

		temp.data_4_4[3][1] = (data_4_4[0][0] * (data_4_4[2][1] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][1])
                             - data_4_4[0][1] * (data_4_4[2][0] * data_4_4[3][2] - data_4_4[2][2] * data_4_4[3][0])
                             + data_4_4[0][2] * (data_4_4[2][0] * data_4_4[3][1] - data_4_4[2][1] * data_4_4[3][0])) * det;

		temp.data_4_4[3][2] = (data_4_4[0][0] * (data_4_4[1][2] * data_4_4[3][1] - data_4_4[1][1] * data_4_4[3][2])
                             - data_4_4[0][1] * (data_4_4[1][0] * data_4_4[3][2] - data_4_4[1][2] * data_4_4[3][0])
                             + data_4_4[0][2] * (data_4_4[1][0] * data_4_4[3][1] - data_4_4[1][1] * data_4_4[3][0])) * det;

		temp.data_4_4[3][3] = (data_4_4[0][0] * (data_4_4[1][1] * data_4_4[2][2] - data_4_4[1][2] * data_4_4[2][1])
                             - data_4_4[0][1] * (data_4_4[1][0] * data_4_4[2][2] - data_4_4[1][2] * data_4_4[2][0])
                             + data_4_4[0][2] * (data_4_4[1][0] * data_4_4[2][1] - data_4_4[1][1] * data_4_4[2][0])) * det;

		*this = temp;
	}
}
inline static Maths::Mat4 Maths::Mat4::GetInverse(const Mat4& _Mat)   const
{
	float det = _Mat.Determinant();
	if (det != 0.f)
	{
		det = 1.f / det;

		Mat4 temp;

		temp.data_4_4[0][0] = (_Mat.data_4_4[1][1] * (_Mat.data_4_4[2][2] * _Mat.data_4_4[3][3] - _Mat.data_4_4[2][3] * _Mat.data_4_4[3][2])
                             - _Mat.data_4_4[1][2] * (_Mat.data_4_4[2][1] * _Mat.data_4_4[3][3] - _Mat.data_4_4[2][3] * _Mat.data_4_4[3][1])
                             + _Mat.data_4_4[1][3] * (_Mat.data_4_4[2][1] * _Mat.data_4_4[3][2] - _Mat.data_4_4[2][2] * _Mat.data_4_4[3][1])) * det;

		temp.data_4_4[0][1] = (_Mat.data_4_4[0][1] * (_Mat.data_4_4[2][3] * _Mat.data_4_4[3][2] - _Mat.data_4_4[2][2] * _Mat.data_4_4[3][3])
                             - _Mat.data_4_4[0][2] * (_Mat.data_4_4[2][3] * _Mat.data_4_4[3][1] - _Mat.data_4_4[2][1] * _Mat.data_4_4[3][3])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[2][2] * _Mat.data_4_4[3][1] - _Mat.data_4_4[2][1] * _Mat.data_4_4[3][2])) * det;

		temp.data_4_4[0][2] = (_Mat.data_4_4[0][1] * (_Mat.data_4_4[1][3] * _Mat.data_4_4[3][2] - _Mat.data_4_4[1][2] * _Mat.data_4_4[3][3])
                             - _Mat.data_4_4[0][2] * (_Mat.data_4_4[1][3] * _Mat.data_4_4[3][1] - _Mat.data_4_4[1][1] * _Mat.data_4_4[3][3])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[1][2] * _Mat.data_4_4[3][1] - _Mat.data_4_4[1][1] * _Mat.data_4_4[3][2])) * det;

		temp.data_4_4[0][3] = (_Mat.data_4_4[0][1] * (_Mat.data_4_4[1][2] * _Mat.data_4_4[2][3] - _Mat.data_4_4[1][3] * _Mat.data_4_4[2][2])
                             - _Mat.data_4_4[0][2] * (_Mat.data_4_4[1][1] * _Mat.data_4_4[2][3] - _Mat.data_4_4[1][3] * _Mat.data_4_4[2][1])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[1][1] * _Mat.data_4_4[2][2] - _Mat.data_4_4[1][2] * _Mat.data_4_4[2][1])) * det;

		temp.data_4_4[1][0] = (_Mat.data_4_4[1][0] * (_Mat.data_4_4[2][3] * _Mat.data_4_4[3][2] - _Mat.data_4_4[2][2] * _Mat.data_4_4[3][3])
                             - _Mat.data_4_4[1][2] * (_Mat.data_4_4[2][3] * _Mat.data_4_4[3][0] - _Mat.data_4_4[2][0] * _Mat.data_4_4[3][3])
                             + _Mat.data_4_4[1][3] * (_Mat.data_4_4[2][2] * _Mat.data_4_4[3][0] - _Mat.data_4_4[2][0] * _Mat.data_4_4[3][2])) * det;

		temp.data_4_4[1][1] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[2][2] * _Mat.data_4_4[3][3] - _Mat.data_4_4[2][3] * _Mat.data_4_4[3][2])
                             - _Mat.data_4_4[0][2] * (_Mat.data_4_4[2][2] * _Mat.data_4_4[3][0] - _Mat.data_4_4[2][0] * _Mat.data_4_4[3][2])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[2][0] * _Mat.data_4_4[3][2] - _Mat.data_4_4[2][2] * _Mat.data_4_4[3][0])) * det;

		temp.data_4_4[1][2] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[1][3] * _Mat.data_4_4[3][2] - _Mat.data_4_4[1][2] * _Mat.data_4_4[3][3])
                             - _Mat.data_4_4[0][2] * (_Mat.data_4_4[1][3] * _Mat.data_4_4[3][0] - _Mat.data_4_4[1][0] * _Mat.data_4_4[3][3])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[1][2] * _Mat.data_4_4[3][0] - _Mat.data_4_4[1][0] * _Mat.data_4_4[3][2])) * det;

		temp.data_4_4[1][3] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[1][2] * _Mat.data_4_4[2][3] - _Mat.data_4_4[1][3] * _Mat.data_4_4[2][2])
                             - _Mat.data_4_4[0][2] * (_Mat.data_4_4[1][2] * _Mat.data_4_4[2][0] - _Mat.data_4_4[1][0] * _Mat.data_4_4[2][2])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[1][0] * _Mat.data_4_4[2][2] - _Mat.data_4_4[1][2] * _Mat.data_4_4[2][0])) * det;

		temp.data_4_4[2][0] = (_Mat.data_4_4[1][0] * (_Mat.data_4_4[2][1] * _Mat.data_4_4[3][3] - _Mat.data_4_4[2][3] * _Mat.data_4_4[3][1])
                             - _Mat.data_4_4[1][1] * (_Mat.data_4_4[2][0] * _Mat.data_4_4[3][3] - _Mat.data_4_4[2][3] * _Mat.data_4_4[3][0])
                             + _Mat.data_4_4[1][3] * (_Mat.data_4_4[2][0] * _Mat.data_4_4[3][1] - _Mat.data_4_4[2][1] * _Mat.data_4_4[3][0])) * det;

		temp.data_4_4[2][1] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[2][3] * _Mat.data_4_4[3][1] - _Mat.data_4_4[2][1] * _Mat.data_4_4[3][3])
                             - _Mat.data_4_4[0][1] * (_Mat.data_4_4[2][3] * _Mat.data_4_4[3][0] - _Mat.data_4_4[2][0] * _Mat.data_4_4[3][3])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[2][1] * _Mat.data_4_4[3][0] - _Mat.data_4_4[2][0] * _Mat.data_4_4[3][1])) * det;

		temp.data_4_4[2][2] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[1][1] * _Mat.data_4_4[3][3] - _Mat.data_4_4[1][3] * _Mat.data_4_4[3][1])
                             - _Mat.data_4_4[0][1] * (_Mat.data_4_4[1][0] * _Mat.data_4_4[3][3] - _Mat.data_4_4[1][3] * _Mat.data_4_4[3][0])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[1][0] * _Mat.data_4_4[3][1] - _Mat.data_4_4[1][1] * _Mat.data_4_4[3][0])) * det;

		temp.data_4_4[2][3] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[1][3] * _Mat.data_4_4[2][1] - _Mat.data_4_4[1][1] * _Mat.data_4_4[2][3])
                             - _Mat.data_4_4[0][1] * (_Mat.data_4_4[1][3] * _Mat.data_4_4[2][0] - _Mat.data_4_4[1][0] * _Mat.data_4_4[2][3])
                             + _Mat.data_4_4[0][3] * (_Mat.data_4_4[1][1] * _Mat.data_4_4[2][0] - _Mat.data_4_4[1][0] * _Mat.data_4_4[2][1])) * det;

		temp.data_4_4[3][0] = (_Mat.data_4_4[1][0] * (_Mat.data_4_4[2][2] * _Mat.data_4_4[3][1] - _Mat.data_4_4[2][1] * _Mat.data_4_4[3][2])
                             - _Mat.data_4_4[1][1] * (_Mat.data_4_4[2][0] * _Mat.data_4_4[3][2] - _Mat.data_4_4[2][2] * _Mat.data_4_4[3][0])
                             + _Mat.data_4_4[1][2] * (_Mat.data_4_4[2][0] * _Mat.data_4_4[3][1] - _Mat.data_4_4[2][1] * _Mat.data_4_4[3][0])) * det;

		temp.data_4_4[3][1] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[2][1] * _Mat.data_4_4[3][2] - _Mat.data_4_4[2][2] * _Mat.data_4_4[3][1])
                             - _Mat.data_4_4[0][1] * (_Mat.data_4_4[2][0] * _Mat.data_4_4[3][2] - _Mat.data_4_4[2][2] * _Mat.data_4_4[3][0])
                             + _Mat.data_4_4[0][2] * (_Mat.data_4_4[2][0] * _Mat.data_4_4[3][1] - _Mat.data_4_4[2][1] * _Mat.data_4_4[3][0])) * det;

		temp.data_4_4[3][2] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[1][2] * _Mat.data_4_4[3][1] - _Mat.data_4_4[1][1] * _Mat.data_4_4[3][2])
                             - _Mat.data_4_4[0][1] * (_Mat.data_4_4[1][0] * _Mat.data_4_4[3][2] - _Mat.data_4_4[1][2] * _Mat.data_4_4[3][0])
                             + _Mat.data_4_4[0][2] * (_Mat.data_4_4[1][0] * _Mat.data_4_4[3][1] - _Mat.data_4_4[1][1] * _Mat.data_4_4[3][0])) * det;

		temp.data_4_4[3][3] = (_Mat.data_4_4[0][0] * (_Mat.data_4_4[1][1] * _Mat.data_4_4[2][2] - _Mat.data_4_4[1][2] * _Mat.data_4_4[2][1])
                             - _Mat.data_4_4[0][1] * (_Mat.data_4_4[1][0] * _Mat.data_4_4[2][2] - _Mat.data_4_4[1][2] * _Mat.data_4_4[2][0])
                             + _Mat.data_4_4[0][2] * (_Mat.data_4_4[1][0] * _Mat.data_4_4[2][1] - _Mat.data_4_4[1][1] * _Mat.data_4_4[2][0])) * det;

		return temp;
	}
	return _Mat;
}
inline float Maths::Mat4::Trace()                                     const
{
	return data_4_4[0][0] + data_4_4[1][1] + data_4_4[2][2] + data_4_4[3][3];
}

inline static Maths::Mat4 Maths::Mat4::CreateIdentityMatrix()                                                                  const
{
	Mat4 temp;

	temp.data_4_4[0][0] = 1.f;
	temp.data_4_4[1][1] = 1.f;
	temp.data_4_4[2][2] = 1.f;
	temp.data_4_4[3][3] = 1.f;

	return temp;
}
inline static Maths::Mat4 Maths::Mat4::CreateXRotationMatrix(float x)                                                          const
{
	float cosX = cosf(x);
	float sinX = sinf(x);

	Mat4 temp;

	temp.data_4_4[0][0] = 1.f;
	temp.data_4_4[1][1] = cosX;
	temp.data_4_4[1][2] = -sinX;
	temp.data_4_4[2][1] = sinX;
	temp.data_4_4[2][2] = cosX;
	temp.data_4_4[3][3] = 1.f;

	return temp;
}
inline static Maths::Mat4 Maths::Mat4::CreateYRotationMatrix(float y)                                                          const
{
	float cosY = cosf(y);
	float sinY = sinf(y);

	Mat4 temp;

	temp.data_4_4[0][0] = cosY;
	temp.data_4_4[0][2] = sinY;
	temp.data_4_4[1][1] = 1.f;
	temp.data_4_4[2][0] = -sinY;
	temp.data_4_4[2][2] = cosY;
	temp.data_4_4[3][3] = 1.f;

	return temp;
}
inline static Maths::Mat4 Maths::Mat4::CreateZRotationMatrix(float z)                                                          const
{
	float cosZ = cosf(z);
	float sinZ = sinf(z);

	Mat4 temp;

	temp.data_4_4[0][0] = cosZ;
	temp.data_4_4[0][1] = -sinZ;
	temp.data_4_4[1][0] = sinZ;
	temp.data_4_4[1][1] = cosZ;
	temp.data_4_4[2][2] = 1.f;
	temp.data_4_4[3][3] = 1.f;

	return temp;
}
#ifndef DISABLE_VEC3
inline static Maths::Mat4 Maths::Mat4::CreateTranslationMatrix(const Vec3& translation)                                        const
{
	Mat4 temp;

	temp.data_4_4[0][0] = 1.f;
	temp.data_4_4[1][1] = 1.f;
	temp.data_4_4[2][2] = 1.f;
	temp.data_4_4[3][3] = 1.f;

	temp.data_4_4[3][0] = translation.x;
	temp.data_4_4[3][1] = translation.y;
	temp.data_4_4[3][2] = translation.z;

	return temp;
}
inline static Maths::Mat4 Maths::Mat4::CreateRotationMatrix(const Vec3& rotation)                                              const
{
	return CreateXRotationMatrix(rotation.x) * CreateYRotationMatrix(rotation.y) * CreateZRotationMatrix(rotation.z);
}
inline static Maths::Mat4 Maths::Mat4::CreateScaleMatrix(const Vec3& scale)                                                    const
{
	Mat4 temp;

	temp.data_4_4[0][0] = scale.x;
	temp.data_4_4[1][1] = scale.y;
	temp.data_4_4[2][2] = scale.z;
	temp.data_4_4[3][3] = 1.f;

	return temp;
}
inline static Maths::Mat4 Maths::Mat4::CreateTransformMatrix(const Vec3& translation, const Vec3& rotation, const Vec3& scale) const
{
	return CreateScaleMatrix(scale) * CreateRotationMatrix(rotation) * CreateTranslationMatrix(translation);
}
#else
inline static Maths::Mat4 Maths::Mat4::CreateTranslationMatrix(float[3] translation)                                           const
{
	Mat4 temp;

	temp.data_4_4[0][0] = 1.f;
	temp.data_4_4[1][1] = 1.f;
	temp.data_4_4[2][2] = 1.f;
	temp.data_4_4[3][3] = 1.f;

	temp.data_4_4[3][0] = translation[0];
	temp.data_4_4[3][1] = translation[1];
	temp.data_4_4[3][2] = translation[2];

	return temp;
}
inline static Maths::Mat4 Maths::Mat4::CreateRotationMatrix(float[3] rotation)                                                 const
{
	return CreateXRotationMatrix(rotation[0]) * CreateYRotationMatrix(rotation[1]) * CreateZRotationMatrix(rotation[2]);
}
inline static Maths::Mat4 Maths::Mat4::CreateScaleMatrix(float[3] scale)                                                       const
{
	Mat4 temp;

	temp.data_4_4[0][0] = scale[0];
	temp.data_4_4[1][1] = scale[1];
	temp.data_4_4[2][2] = scale[2];
	temp.data_4_4[3][3] = 1.f;

	return temp;
}
inline static Maths::Mat4 Maths::Mat4::CreateTransformMatrix(float[3] translation, float[3] rotation, float[3] scale)          const
{
	return CreateScaleMatrix(scale) * CreateRotationMatrix(rotation) * CreateTranslationMatrix(translation);
}
#endif

//ASSINGMENT AND EQUALITY OPERATIONS :

inline Maths::Mat4 Maths::Mat4::operator=(float _data[16])
{
	for (int i = 0; i < 16; i++)
	{
		data[i] = _data[i];
	}
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator=(const Mat4& _Mat)
{
	for (int i = 0; i < 16; i++)
	{
		data[i] = _Mat.data[i];
	}
	return *this;
}

//Mat4 TO Mat4 OPERATIONS :

inline Maths::Mat4 Maths::Mat4::operator+(const Mat4& _Mat) const
{
	Mat4 temp;
	for (int i = 0; i < 16; i++)
	{
		temp.data[i] = data[i] + _Mat.data[i];
	}
	return temp;
}
inline Maths::Mat4 Maths::Mat4::operator-(const Mat4& _Mat) const
{
	Mat4 temp;
	for (int i = 0; i < 16; i++)
	{
		temp.data[i] = data[i] - _Mat.data[i];
	}
	return temp;
}
inline Maths::Mat4 Maths::Mat4::operator*(const Mat4& _Mat) const
{
	Mat4 temp;

	temp.data[0] = data[0] * _Mat.data[0] + data[4] * _Mat.data[1] + data[8] * _Mat.data[2] + data[12] * _Mat.data[3];
	temp.data[1] = data[1] * _Mat.data[0] + data[5] * _Mat.data[1] + data[9] * _Mat.data[2] + data[13] * _Mat.data[3];
	temp.data[2] = data[2] * _Mat.data[0] + data[6] * _Mat.data[1] + data[10] * _Mat.data[2] + data[14] * _Mat.data[3];
	temp.data[3] = data[3] * _Mat.data[0] + data[7] * _Mat.data[1] + data[11] * _Mat.data[2] + data[15] * _Mat.data[3];

	temp.data[4] = data[0] * _Mat.data[4] + data[4] * _Mat.data[5] + data[8] * _Mat.data[6] + data[12] * _Mat.data[7];
	temp.data[5] = data[1] * _Mat.data[4] + data[5] * _Mat.data[5] + data[9] * _Mat.data[6] + data[13] * _Mat.data[7];
	temp.data[6] = data[2] * _Mat.data[4] + data[6] * _Mat.data[5] + data[10] * _Mat.data[6] + data[14] * _Mat.data[7];
	temp.data[7] = data[3] * _Mat.data[4] + data[7] * _Mat.data[5] + data[11] * _Mat.data[6] + data[15] * _Mat.data[7];

	temp.data[8] = data[0] * _Mat.data[8] + data[4] * _Mat.data[9] + data[8] * _Mat.data[10] + data[12] * _Mat.data[11];
	temp.data[9] = data[1] * _Mat.data[8] + data[5] * _Mat.data[9] + data[9] * _Mat.data[10] + data[13] * _Mat.data[11];
	temp.data[10] = data[2] * _Mat.data[8] + data[6] * _Mat.data[9] + data[10] * _Mat.data[10] + data[14] * _Mat.data[11];
	temp.data[11] = data[3] * _Mat.data[8] + data[7] * _Mat.data[9] + data[11] * _Mat.data[10] + data[15] * _Mat.data[11];

	temp.data[12] = data[0] * _Mat.data[12] + data[4] * _Mat.data[13] + data[8] * _Mat.data[14] + data[12] * _Mat.data[15];
	temp.data[13] = data[1] * _Mat.data[12] + data[5] * _Mat.data[13] + data[9] * _Mat.data[14] + data[13] * _Mat.data[15];
	temp.data[14] = data[2] * _Mat.data[12] + data[6] * _Mat.data[13] + data[10] * _Mat.data[14] + data[14] * _Mat.data[15];
	temp.data[15] = data[3] * _Mat.data[12] + data[7] * _Mat.data[13] + data[11] * _Mat.data[14] + data[15] * _Mat.data[15];

	return temp;
}

//Mat4 TO THIS OPERATIONS :

inline Maths::Mat4 Maths::Mat4::operator+=(const Mat4& _Mat)
{
	for (int i = 0; i < 16; i++)
	{
		data[i] += _Mat.data[i];
	}
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator-=(const Mat4& _Mat)
{
	for (int i = 0; i < 16; i++)
	{
		data[i] -= _Mat.data[i];
	}
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator*=(const Mat4& _Mat)
{
	Mat4 temp;

	temp.data[0] = data[0] * _Mat.data[0] + data[4] * _Mat.data[1] + data[8] * _Mat.data[2] + data[12] * _Mat.data[3];
	temp.data[1] = data[1] * _Mat.data[0] + data[5] * _Mat.data[1] + data[9] * _Mat.data[2] + data[13] * _Mat.data[3];
	temp.data[2] = data[2] * _Mat.data[0] + data[6] * _Mat.data[1] + data[10] * _Mat.data[2] + data[14] * _Mat.data[3];
	temp.data[3] = data[3] * _Mat.data[0] + data[7] * _Mat.data[1] + data[11] * _Mat.data[2] + data[15] * _Mat.data[3];

	temp.data[4] = data[0] * _Mat.data[4] + data[4] * _Mat.data[5] + data[8] * _Mat.data[6] + data[12] * _Mat.data[7];
	temp.data[5] = data[1] * _Mat.data[4] + data[5] * _Mat.data[5] + data[9] * _Mat.data[6] + data[13] * _Mat.data[7];
	temp.data[6] = data[2] * _Mat.data[4] + data[6] * _Mat.data[5] + data[10] * _Mat.data[6] + data[14] * _Mat.data[7];
	temp.data[7] = data[3] * _Mat.data[4] + data[7] * _Mat.data[5] + data[11] * _Mat.data[6] + data[15] * _Mat.data[7];

	temp.data[8] = data[0] * _Mat.data[8] + data[4] * _Mat.data[9] + data[8] * _Mat.data[10] + data[12] * _Mat.data[11];
	temp.data[9] = data[1] * _Mat.data[8] + data[5] * _Mat.data[9] + data[9] * _Mat.data[10] + data[13] * _Mat.data[11];
	temp.data[10] = data[2] * _Mat.data[8] + data[6] * _Mat.data[9] + data[10] * _Mat.data[10] + data[14] * _Mat.data[11];
	temp.data[11] = data[3] * _Mat.data[8] + data[7] * _Mat.data[9] + data[11] * _Mat.data[10] + data[15] * _Mat.data[11];

	temp.data[12] = data[0] * _Mat.data[12] + data[4] * _Mat.data[13] + data[8] * _Mat.data[14] + data[12] * _Mat.data[15];
	temp.data[13] = data[1] * _Mat.data[12] + data[5] * _Mat.data[13] + data[9] * _Mat.data[14] + data[13] * _Mat.data[15];
	temp.data[14] = data[2] * _Mat.data[12] + data[6] * _Mat.data[13] + data[10] * _Mat.data[14] + data[14] * _Mat.data[15];
	temp.data[15] = data[3] * _Mat.data[12] + data[7] * _Mat.data[13] + data[11] * _Mat.data[14] + data[15] * _Mat.data[15];

	*this = temp;
	return *this;
}
#pragma endregion Mat4
#endif

// Quaternion ----------------------------------------------------------------------------------------------
#ifndef DISABLE_QUAT
/************************\
 *------QUATERNION------*
\************************/
#pragma region Quat
//CONSTRUCTORS :

inline Maths::Quat::Quat(void) : a(0), b(0), c(0), d(0) {}
inline Maths::Quat::Quat(float a, float b, float c, float d) : a(a), b(b), c(c), d(d) {}
inline Maths::Quat::Quat(float pitch, float yaw, float roll);

//DESTRUCTOR :

inline Maths::Quat::~Quat(void) {}

//UTILS :

inline static Maths::Quat Maths::Quat::CreateFromEuler(const Maths::Vec3& _VecRotation)   const
{
	CreateFromRadians(_VecRotation * DEG2RAD)
}
inline static Maths::Quat Maths::Quat::CreateFromRadians(const Maths::Vec3& _VecRotation) const
{
	float sinX = sinf(_VecRotation.x * 0.5f);
	float cosX = cosf(_VecRotation.x * 0.5f);
	float sinY = sinf(_VecRotation.y * 0.5f);
	float cosY = cosf(_VecRotation.y * 0.5f);
	float sinZ = sinf(_VecRotation.z * 0.5f);
	float cosZ = cosf(_VecRotation.z * 0.5f);

	a = sinX * cosY * cosZ + cosX * sinY * sinZ;
	b = sinX * cosY * sinZ + cosX * sinY * cosZ;
	c = cosX * cosY * sinZ - sinX * sinY * cosZ;
	d = cosX * cosY * cosZ - sinX * sinY * sinZ;
}
inline static Maths::Quat Maths::Quat::CreateFromMatrix(const Maths::Mat4& _MatRotation)  const
{
	//TODO
}

inline Maths::Vec3 Maths::Quat::ToEuler()                                                  const
{
	//TODO
}
inline Maths::Vec3 Maths::Quat::ToRadians()                                                const
{
	//TODO
}
inline Maths::Mat4 Maths::Quat::ToMatrix()                                                 const
{
	//TODO
}

//ASSINGMENT AND EQUALITY OPERATIONS :



//IVec4 TO Vec2 OPERATIONS :



//IVec4 TO THIS OPERATIONS :



//SCALER TO IVec4 OPERATIONS :



//SCALER TO THIS OPERATIONS :


#pragma endregion Quat
#endif