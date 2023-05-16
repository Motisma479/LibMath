/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 16/05/2023                      *
\***********************************************/
#include "Maths.hpp"

#include <cmath>
#ifndef DISABLE_VEC2
/************************\
 *-------VECTOR_2-------*
\************************/
#pragma region Vec2
//CONSTRUCTORS :

inline Maths::Vec2::Vec2(void)              : x(0),       y(0)       {}
inline Maths::Vec2::Vec2(float xy)          : x(xy),      y(xy)      {}
inline Maths::Vec2::Vec2(float x, float y)  : x(x),       y(y)       {}
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
	return sqrtf((x * x) + (y * y));
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
inline float Maths::Vec2::DotProduct(const Vec2& _VecB)                    const
{
	return (float)(x * _VecB.x + y * _VecB.y);
}
inline float Maths::Vec2::DotProduct(const Vec2& _VecA, const Vec2& _VecB) const
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y);
}
inline float Maths::Vec2::GetLength()                                      const
{
	return sqrtf(LenghtSquared());
}
inline float Maths::Vec2::LenghtSquared()                                  const
{
	return (x * x + y * y);
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

inline Maths::Vec3::Vec3(void)                       : x(0),       y(0),       z(0)       {}
inline Maths::Vec3::Vec3(float xyz)                  : x(xyz),     y(xyz),     z(xyz)     {}
inline Maths::Vec3::Vec3(float x, float y, float z)	 : x(x),       y(y),       z(z)       {}
#ifndef DISABLE_VEC2
inline Maths::Vec3::Vec3(const Vec2& _Vec2)          : x(_Vec2.x), y(_Vec2.y), z(0)       {}
inline Maths::Vec3::Vec3(const Vec2& _Vec2, float z) : x(_Vec2.x), y(_Vec2.y), z(z)       {}
#endif
#ifndef DISABLE_VEC4
inline Maths::Vec3::Vec3(const Vec4& _Vec4)          : x(_Vec4.x), y(_Vec4.y), z(_Vec4.z) {}
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
	return sqrtf((x * x) + (y * y) + (z * z));
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
inline float Maths::Vec3::DotProduct(const Vec3& _VecA, const Vec3& _VecB)         const
{
	return (float)(_VecA.x * _VecB.x + _VecA.y * _VecB.y + _VecA.z * _VecB.z);
}
inline Maths::Vec3 Maths::Vec3::CrossProduct(const Vec3& _VecB)                    const
{
	return { y * _VecB.z - z * _VecB.y, z * _VecB.x - x * _VecB.z, x * _VecB.y - y * _VecB.x };
}
inline Maths::Vec3 Maths::Vec3::CrossProduct(const Vec3& _VecA, const Vec3& _VecB) const
{
	return { _VecA.y * _VecB.z - _VecA.z * _VecB.y, _VecA.z * _VecB.x - _VecA.x * _VecB.z, _VecA.x * _VecB.y - _VecA.y * _VecB.x };
}
inline float Maths::Vec3::GetLength()                                              const
{
	return sqrtf(LenghtSquared());
}
inline float Maths::Vec3::LenghtSquared()                                          const
{
	return (x * x + y * y + z * z);
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

inline Maths::Vec4::Vec4(void)                                                       : x(0),       y(0),       z(0),       w(0)    {}
inline Maths::Vec4::Vec4(const float xyzw)                                           : x(xyzw),    y(xyzw),    z(xyzw),    w(xyzw) {}
inline Maths::Vec4::Vec4(const float x, const float y, const float z, const float w) : x(x),       y(y),       z(z),       w(w)    {}
#ifndef DISABLE_VEC2
inline Maths::Vec4::Vec4(const Vec2& _Vec2)                                          : x(_Vec2.x), y(_Vec2.y), z(0),       w(0)    {}
#endif
#ifndef DISABLE_VEC3
inline Maths::Vec4::Vec4(const Vec3& _Vec3)                                          : x(_Vec3.x), y(_Vec3.y), z(_Vec3.z), w(0)    {}
inline Maths::Vec4::Vec4(const Vec3& _Vec3, float w)                                 : x(_Vec3.x), y(_Vec3.y), z(_Vec3.z), w(w)    {}
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
	return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
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
inline float Maths::Vec4::DotProduct(const Vec4& _VecA, const Vec4& _VecB) const
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
inline float Maths::Vec4::GetLength()                                      const
{
	return sqrtf(LenghtSquared());
}
inline float Maths::Vec4::LenghtSquared()                                  const
{
	return (x * x + y * y + z * z + w * w);
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


#ifndef DISABLE_IVEC2
/************************\
 *------IVECTOR_2-------*
\************************/
#pragma region IVec2
//CONSTRUCTORS :

inline Maths::IVec2::IVec2(void)                     : x(0),                         y(0)                         {}
inline Maths::IVec2::IVec2(const int xy)             : x(xy),                        y(xy)                        {}
inline Maths::IVec2::IVec2(const int x, const int y) : x(x),                         y(y)                         {}
#ifndef DISABLE_VEC2
inline Maths::IVec2::IVec2(const class Vec2& _Vec2)  : x(static_cast<int>(_Vec2.x)), y(static_cast<int>(_Vec2.y)) {}
#endif

//DESTRUCTOR :

inline Maths::IVec2::~IVec2(void) {}

//UTILS :

inline float Maths::IVec2::GetLength()     const
{
	return sqrtf(LenghtSquared());
}
inline float Maths::IVec2::LenghtSquared() const
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

//Vec2 TO Vec2 OPERATIONS :

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

//Vec2 TO THIS OPERATIONS :

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

//SCALER TO Vec2 OPERATIONS :

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

inline Maths::IVec3::IVec3(void)                                  : x(0),                         y(0),                         z(0)                         {}
inline Maths::IVec3::IVec3(const int xyz)                         : x(xyz),                       y(xyz),                       z(xyz)                       {}
inline Maths::IVec3::IVec3(const int x, const int y, const int z) : x(x),                         y(y),                         z(z)                         {}
#ifndef DISABLE_VEC3
inline Maths::IVec3::IVec3(const class Vec3& _Vec3)               : x(static_cast<int>(_Vec3.x)), y(static_cast<int>(_Vec3.y)), z(static_cast<int>(_Vec3.z)) {}
#endif

//DESTRUCTOR :

inline Maths::IVec3::~IVec3(void) {}

//UTILS :

inline float Maths::IVec3::GetLength()     const
{
	return sqrtf(LenghtSquared());
}
inline float Maths::IVec3::LenghtSquared() const
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

//Vec2 TO Vec2 OPERATIONS :

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

//Vec2 TO THIS OPERATIONS :

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

//SCALER TO Vec2 OPERATIONS :

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

inline Maths::IVec4::IVec4(void)                                               : x(0),                         y(0),                         z(0),                         w(0)                         {}
inline Maths::IVec4::IVec4(const int xyzw)                                     : x(xyzw),                      y(xyzw),                      z(xyzw),                      w(xyzw)                      {}
inline Maths::IVec4::IVec4(const int x, const int y, const int z, const int w) : x(x),                         y(y),                         z(z),                         w(w)                         {}
#ifndef DISABLE_VEC4
inline Maths::IVec4::IVec4(const class Vec4& _Vec4)                            : x(static_cast<int>(_Vec4.x)), y(static_cast<int>(_Vec4.y)), z(static_cast<int>(_Vec4.z)), w(static_cast<int>(_Vec4.w)) {}
#endif

//DESTRUCTOR :

inline Maths::IVec4::~IVec4(void) {}

//UTILS :

inline float Maths::IVec4::GetLength()     const
{
	return sqrtf(LenghtSquared());
}
inline float Maths::IVec4::LenghtSquared() const
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

//Vec2 TO Vec2 OPERATIONS :

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

//Vec2 TO THIS OPERATIONS :

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

//SCALER TO Vec2 OPERATIONS :

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