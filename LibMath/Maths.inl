/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 18/09/2023                      *
\***********************************************/
#include "Maths.hpp"

#include <cmath>
#include <cassert>

inline float MATHS_LIB_API Maths::ToRadians(float _angleDegrees)
{
	return _angleDegrees * Constants::DEG2RAD;
}
inline double MATHS_LIB_API Maths::ToRadians(double _angleDegrees)
{
	return _angleDegrees * Constants::DEG2RAD_PRECISE;
}

inline float Maths::ToDegrees(float _angleRadians)
{
	return _angleRadians * Constants::RAD2DEG;
}
inline double Maths::ToDegrees(double _angleRadians)
{
	return _angleRadians * Constants::RAD2DEG_PRECISE;
}

#pragma region Vector

#ifndef DISABLE_VEC2
/************************\
 *-------VECTOR_2-------*
\************************/
#pragma region Vec2

//CONSTRUCTORS :
inline Maths::Vec2::Vec2(void) : x(0), y(0) {}
inline Maths::Vec2::Vec2(float _xy) : x(_xy), y(_xy) {}
inline Maths::Vec2::Vec2(float _x, float _y) : x(_x), y(_y) {}
inline Maths::Vec2::Vec2(const Vec3& _vec) : x(_vec.x), y(_vec.y) {}
inline Maths::Vec2::Vec2(const Vec4& _vec) : x(_vec.x), y(_vec.y) {}

//DESTRUCTOR :
inline Maths::Vec2::~Vec2(void) {}

//UTILS :
inline float Maths::Vec2::GetMagnitude()           const
{
	return sqrt(GetMagnitudeSquared());
}
inline float Maths::Vec2::GetMagnitudeSquared()    const
{
	return DotProduct(*this, *this);
}
inline Maths::Vec2 Maths::Vec2::GetNormalized()    const
{
	float i = GetMagnitude();
	if (i != 0)
		return operator*(1 / i);
	return *this;
}
inline Maths::Vec2 Maths::Vec2::GetPerpendicular() const
{
	return {y, -x};
}

//ASSINGMENT AND EQUALITY OPERATIONS :
inline Maths::Vec2 Maths::Vec2::operator = (const Vec3& _vec)
{
	x = _vec.x;
	y = _vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator = (const Vec4& _vec)
{
	x = _vec.x;
	y = _vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator = (float _sca)
{
	x = _sca;
	y = _sca;
	return *this;
}

inline Maths::Vec2 Maths::Vec2::operator - (void)       const
{
	return
	{
		-x,
		-y
	};
}
inline bool Maths::Vec2::operator == (const Vec2& _vec) const
{
	return (x == _vec.x && y == _vec.y);
}
inline bool Maths::Vec2::operator != (const Vec2& _vec) const
{
	return (x != _vec.x || y != _vec.y);
}

inline float Maths::Vec2::operator [] (int _index) const
{
	assert(_index > -1 && _index < 3);
	return xy[_index];
}

//Vec2 TO Vec2 OPERATIONS :
inline Maths::Vec2 Maths::Vec2::operator + (const Vec2& _vec) const
{
	return
	{
		x + _vec.x,
		y + _vec.y
	};
}
inline Maths::Vec2 Maths::Vec2::operator - (const Vec2& _vec) const
{
	return
	{
		x - _vec.x,
		y - _vec.y
	};
}

//Vec2 TO THIS OPERATIONS :
inline Maths::Vec2 Maths::Vec2::operator += (const Vec2& _vec)
{
	x += _vec.x;
	y += _vec.y;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator -= (const Vec2& _vec)
{
	x -= _vec.x;
	y -= _vec.y;
	return *this;
}

//SCALER TO Vec2 OPERATIONS :
inline Maths::Vec2 Maths::Vec2::operator + (float _sca) const
{
	return
	{
		x + _sca,
		y + _sca
	};
}
inline Maths::Vec2 Maths::Vec2::operator - (float _sca) const
{
	return
	{
		x - _sca,
		y - _sca
	};
}
inline Maths::Vec2 Maths::Vec2::operator * (float _sca) const
{
	return
	{
		x * _sca,
		y * _sca
	};
}
inline Maths::Vec2 Maths::Vec2::operator / (float _sca) const
{
	return
	{
		x / _sca,
		y / _sca
	};
}

//SCALER TO THIS OPERATIONS :
inline Maths::Vec2 Maths::Vec2::operator += (float _sca)
{
	x += _sca;
	y += _sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator -= (float _sca)
{
	x -= _sca;
	y -= _sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator *= (float _sca)
{
	x *= _sca;
	y *= _sca;
	return *this;
}
inline Maths::Vec2 Maths::Vec2::operator /= (float _sca)
{
	x /= _sca;
	y /= _sca;
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
inline Maths::Vec3::Vec3(float _xyz) : x(_xyz), y(_xyz), z(_xyz) {}
inline Maths::Vec3::Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
inline Maths::Vec3::Vec3(const Vec2& _vec, float _z) : x(_vec.x), y(_vec.y), z(_z) {}
inline Maths::Vec3::Vec3(const Vec4& _vec) : x(_vec.x), y(_vec.y), z(_vec.z) {}

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

inline float Maths::Vec3::GetMagnitude()        const
{
	return sqrt(GetMagnitudeSquared());
}
inline float Maths::Vec3::GetMagnitudeSquared() const
{
	return DotProduct(*this, *this);
}
inline Maths::Vec3 Maths::Vec3::GetNormalized() const
{
	float i = GetMagnitude();
	if (i != 0)
		return operator*(1 / i);
	return *this;
}

//ASSINGMENT AND EQUALITY OPERATIONS :
inline Maths::Vec3 Maths::Vec3::operator = (const Vec2& _vec)
{
	x = _vec.x;
	y = _vec.y;
	z = 0.f;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator = (const Vec4& _vec)
{
	x = _vec.x;
	y = _vec.y;
	z = _vec.z;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator = (float _sca)
{
	x = _sca;
	y = _sca;
	z = _sca;
	return *this;
}

inline Maths::Vec3 Maths::Vec3::operator - (void)		const
{
	return 
	{
		-x,
		-y,
		-z
	};
}
inline bool Maths::Vec3::operator == (const Vec3& _vec)	const
{
	return (x == _vec.x && y == _vec.y && z == _vec.z);
}
inline bool Maths::Vec3::operator != (const Vec3& _vec)	const
{
	return (x != _vec.x || y != _vec.y || z != _vec.z);
}

inline float Maths::Vec3::operator [] (int _index) const
{
	assert(_index > -1 && _index < 4);
	return xyz[_index];
}

//Vec3 TO Vec3 OPERATIONS :
inline Maths::Vec3 Maths::Vec3::operator + (const Vec3& _vec) const
{
	return
	{
		x + _vec.x,
		y + _vec.y,
		z + _vec.z
	};
}
inline Maths::Vec3 Maths::Vec3::operator - (const Vec3& _vec) const
{
	return
	{
		x - _vec.x,
		y - _vec.y,
		z - _vec.z
	};
}

//Vec3 TO THIS OPERATIONS :
inline Maths::Vec3 Maths::Vec3::operator += (const Vec3& _vec)
{
	x += _vec.x;
	y += _vec.y;
	z += _vec.z;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator -= (const Vec3& _vec)
{
	x -= _vec.x;
	y -= _vec.y;
	z -= _vec.z;
	return *this;
}

//SCALER TO Vec3 OPERATIONS :
inline Maths::Vec3 Maths::Vec3::operator + (float _sca) const
{
	return 
	{
		x + _sca,
		y + _sca,
		z + _sca
	};
}
inline Maths::Vec3 Maths::Vec3::operator - (float _sca) const
{
	return 
	{
		x - _sca,
		y - _sca,
		z - _sca
	};
}
inline Maths::Vec3 Maths::Vec3::operator * (float _sca) const
{
	return 
	{
		x * _sca,
		y * _sca,
		z * _sca
	};
}
inline Maths::Vec3 Maths::Vec3::operator / (float _sca) const
{
	return 
	{
		x / _sca,
		y / _sca,
		z / _sca
	};
}

//SCALER TO THIS OPERATIONS :
inline Maths::Vec3 Maths::Vec3::operator += (float _sca)
{
	x += _sca;
	y += _sca;
	z += _sca;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator -= (float _sca)
{
	x -= _sca;
	y -= _sca;
	z -= _sca;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator *= (float _sca)
{
	x *= _sca;
	y *= _sca;
	z *= _sca;
	return *this;
}
inline Maths::Vec3 Maths::Vec3::operator /= (float _sca)
{
	x /= _sca;
	y /= _sca;
	z /= _sca;
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
inline Maths::Vec4::Vec4(const float _xyzw) : x(_xyzw), y(_xyzw), z(_xyzw), w(_xyzw) {}
inline Maths::Vec4::Vec4(const float _x, const float _y, const float _z, const float _w) : x(_x), y(_y), z(_z), w(_w) {}
inline Maths::Vec4::Vec4(const class Vec2& _vec, float _z, float _w) : x(_vec.x), y(_vec.y), z(_z), w(_w) {}
inline Maths::Vec4::Vec4(const class Vec3& _vec, float _w) : x(_vec.x), y(_vec.y), z(_vec.z), w(_w) {}

//DESTRUCTOR :
inline Maths::Vec4::~Vec4(void) {}

//UTILS :
inline Maths::Vec3 Maths::Vec4::xyz() const
{
	return Vec3(x, y, z);
}
inline Maths::Vec3 Maths::Vec4::xzw() const
{
	return Vec3(x, z, w);
}
inline Maths::Vec3 Maths::Vec4::xyw() const
{
	return Vec3(x, y, w);
}
inline Maths::Vec3 Maths::Vec4::yzw() const
{
	return Vec3(y, z, w);
}

inline float Maths::Vec4::GetMagnitude()         const
{
	return sqrt(GetMagnitudeSquared());
}
inline float Maths::Vec4::GetMagnitudeSquared()  const
{
	return DotProduct(*this, *this);
}
inline Maths::Vec4 Maths::Vec4::GetNormalized()  const
{
	float i = GetMagnitude();
	if (i != 0)
		return operator*(1/i);
	return *this;
}
inline Maths::Vec4 Maths::Vec4::GetHomogenized() const
{
	if (w == 0)
		return { x, y, z, w };
	return { x / w, y / w, z / w, 1 };
}

//ASSINGMENT AND EQUALITY OPERATIONS :
inline Maths::Vec4 Maths::Vec4::operator = (const Vec2& _vec)
{
	x = _vec.x;
	y = _vec.y;
	z = 0.f;
	w = 1.f;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator = (const Vec3& _vec)
{
	x = _vec.x;
	y = _vec.y;
	z = _vec.z;
	w = 1.f;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator = (float _sca)
{
	x = _sca;
	y = _sca;
	z = _sca;
	w = _sca;
	return *this;
}

inline Maths::Vec4 Maths::Vec4::operator - (void)		const
{
	return
	{
		-x,
		-y,
		-z,
		-w
	};
}
inline bool Maths::Vec4::operator == (const Vec4& _vec)	const
{
	return (x == _vec.x && y == _vec.y && z == _vec.z && w == _vec.w);
}
inline bool Maths::Vec4::operator != (const Vec4& _vec)	const
{
	return (x != _vec.x || y != _vec.y || z != _vec.z || w != _vec.w);
}

inline float Maths::Vec4::operator [] (int _index) const
{
	assert(_index > -1 && _index < 5);
	return xyzw[_index];
}

//Vec4 TO Vec4 OPERATIONS :
inline Maths::Vec4 Maths::Vec4::operator + (const Vec4& _vec) const
{
	return
	{
		x + _vec.x,
		y + _vec.y,
		z + _vec.z,
		w + _vec.w
	};
}
inline Maths::Vec4 Maths::Vec4::operator - (const Vec4& _vec) const
{
	return
	{
		x - _vec.x,
		y - _vec.y,
		z - _vec.z,
		w - _vec.w
	};
}

//Vec4 TO THIS OPERATIONS :
inline Maths::Vec4 Maths::Vec4::operator += (const Vec4& _vec)
{
	x += _vec.x;
	y += _vec.y;
	z += _vec.z;
	w += _vec.w;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator -= (const Vec4& _vec)
{
	x -= _vec.x;
	y -= _vec.y;
	z -= _vec.z;
	w -= _vec.w;
	return *this;
}

//SCALER TO Vec4 OPERATIONS :
inline Maths::Vec4 Maths::Vec4::operator + (float _sca) const
{
	return
	{
		x + _sca,
		y + _sca,
		z + _sca,
		w + _sca
	};

}
inline Maths::Vec4 Maths::Vec4::operator - (float _sca) const
{
	return
	{
		x - _sca,
		y - _sca,
		z - _sca,
		w - _sca
	};
}
inline Maths::Vec4 Maths::Vec4::operator * (float _sca) const
{
	return
	{
		x * _sca,
		y * _sca,
		z * _sca,
		w * _sca
	};
}
inline Maths::Vec4 Maths::Vec4::operator / (float _sca) const
{
	return
	{
		x / _sca,
		y / _sca,
		z / _sca,
		w / _sca
	};
}

//SCALER TO THIS OPERATIONS :

inline Maths::Vec4 Maths::Vec4::operator += (float _sca)
{
	x += _sca;
	y += _sca;
	z += _sca;
	w += _sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator -= (float _sca)
{
	x -= _sca;
	y -= _sca;
	z -= _sca;
	w -= _sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator *= (float _sca)
{
	x *= _sca;
	y *= _sca;
	z *= _sca;
	w *= _sca;
	return *this;
}
inline Maths::Vec4 Maths::Vec4::operator /= (float _sca)
{
	x /= _sca;
	y /= _sca;
	z /= _sca;
	w /= _sca;
	return *this;
}

#pragma endregion Vec4
#endif

inline void MATHS_LIB_API Maths::Normalize(Vec2& _vec)
{
	float m = _vec.GetMagnitude();
	if (m != 0.f)
		_vec.operator*=(1 / m);
}
inline void MATHS_LIB_API Maths::Normalize(Vec3& _vec)
{
	float m = _vec.GetMagnitude();
	if (m != 0.f)
		_vec.operator*=(1 / m);
}
inline void MATHS_LIB_API Maths::Normalize(Vec4& _vec)
{
	float m = _vec.GetMagnitude();
	if (m != 0.f)
		_vec.operator*=(1 / m);
}

inline float MATHS_LIB_API Maths::DotProduct(const Vec2& _vecA, const Vec2& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y);
}
inline float MATHS_LIB_API Maths::DotProduct(const Vec3& _vecA, const Vec3& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y + _vecA.z * _vecB.z);
}
inline float MATHS_LIB_API Maths::DotProduct(const Vec4& _vecA, const Vec4& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y + _vecA.z * _vecB.z + _vecA.w * _vecB.w);
}

inline float MATHS_LIB_API Maths::DistanceBetween(const Vec2& _vecA, const Vec2& _vecB)
{
	return sqrt((_vecA.x - _vecB.x) * (_vecA.x - _vecB.x) + (_vecA.y - _vecB.y) * (_vecA.y - _vecB.y));
}
inline float MATHS_LIB_API Maths::DistanceBetween(const Vec3& _vecA, const Vec3& _vecB)
{
	return sqrt((_vecA.x - _vecB.x) * (_vecA.x - _vecB.x) + (_vecA.y - _vecB.y) * (_vecA.y - _vecB.y) + (_vecA.z - _vecB.z) * (_vecA.z - _vecB.z));
}
inline float MATHS_LIB_API Maths::DistanceBetween(const Vec4& _vecA, const Vec4& _vecB)
{
	return sqrt((_vecA.x - _vecB.x) * (_vecA.x - _vecB.x) + (_vecA.y - _vecB.y) * (_vecA.y - _vecB.y) + (_vecA.z - _vecB.z) * (_vecA.z - _vecB.z) + (_vecA.w - _vecB.w) * (_vecA.w - _vecB.w));
}

inline float MATHS_LIB_API Maths::AngleBetween(const Vec2& _vecA, const Vec2& _vecB)
{
	float angle = acos(DotProduct(_vecA, _vecB) / (_vecA.GetMagnitude() * _vecB.GetMagnitude()));
	if (CrossProduct(_vecA, _vecB) >= 0)
		return angle;
	return -angle;
}
inline float MATHS_LIB_API Maths::AngleBetween(const Vec3& _vecA, const Vec3& _vecB)
{
	return acos(DotProduct(_vecA, _vecB) / (_vecA.GetMagnitude() * _vecB.GetMagnitude()));
}
inline float MATHS_LIB_API Maths::AngleBetween(const Vec4& _vecA, const Vec4& _vecB)
{
	return acos(DotProduct(_vecA, _vecB) / (_vecA.GetMagnitude() * _vecB.GetMagnitude()));
}

inline float MATHS_LIB_API Maths::CrossProduct(const Vec2& _vecA, const Vec2& _vecB)
{
	return _vecA.x * _vecB.y - _vecA.y * _vecB.x;
}

inline Maths::Vec3 MATHS_LIB_API Maths::CrossProduct(const Vec3& _vecA, const Vec3& _vecB)
{
	return
	{
		_vecA.y * _vecB.z - _vecA.z * _vecB.y,
		_vecA.z * _vecB.x - _vecA.x * _vecB.z,
		_vecA.x * _vecB.y - _vecA.y * _vecB.x
	};
}
inline Maths::Vec3 MATHS_LIB_API Maths::Rotate(const Vec3& _vec, float _angle, const Vec3& _axis)
{
	Quat rotator = FromAngleAxis(_angle, _axis);
	return rotator.RotateVector(_vec);
}

#pragma endregion Vector

#pragma region Matrix

#ifndef DISABLE_MAT3
/************************\
 *-------MATRIX_3-------*
\************************/
#pragma region Mat3

//CONSTRUCTORS :
inline Maths::Mat3::Mat3(void)
{
	data[0] = 0.f;
	data[1] = 0.f;
	data[2] = 0.f;

	data[3] = 0.f;
	data[4] = 0.f;
	data[5] = 0.f;

	data[6] = 0.f;
	data[7] = 0.f;
	data[8] = 0.f;

}
inline Maths::Mat3::Mat3(float _data[9])
{
	data[0] = _data[0];
	data[1] = _data[1];
	data[2] = _data[2];

	data[3] = _data[3];
	data[4] = _data[4];
	data[5] = _data[5];

	data[6] = _data[6];
	data[7] = _data[7];
	data[8] = _data[8];

}
inline Maths::Mat3::Mat3(float _identityValue)
{
	data[0] = _identityValue;
	data[1] = 0.f;
	data[2] = 0.f;

	data[3] = 0.f;
	data[4] = _identityValue;
	data[5] = 0.f;

	data[6] = 0.f;
	data[7] = 0.f;
	data[8] = _identityValue;
}
inline Maths::Mat3::Mat3(float _0, float _1, float _2,
						float _3, float _4, float _5,
						float _6, float _7, float _8)
{
	data[0] = _0;
	data[1] = _1;
	data[2] = _2;

	data[3] = _3;
	data[4] = _4;
	data[5] = _5;

	data[6] = _6;
	data[7] = _7;
	data[8] = _8;
}

inline Maths::Mat3::Mat3(const class Mat4& _mat)
{
	data[0] = _mat.data[0];
	data[1] = _mat.data[1];
	data[2] = _mat.data[2];

	data[3] = _mat.data[4];
	data[4] = _mat.data[5];
	data[5] = _mat.data[6];

	data[6] = _mat.data[8];
	data[7] = _mat.data[9];
	data[8] = _mat.data[10];
}

//DESTRUCTOR :
inline Maths::Mat3::~Mat3(void){}

//UTILS :
inline Maths::Mat3 Maths::Mat3::Rotate2D(float _angleInRad)
{
	float ca = 0.f;
	float sa = 1.f;
	if (_angleInRad)
	{
		ca = std::cos(_angleInRad);
		sa = std::sin(_angleInRad);
		//Pas obligatoire
		if (abs(ca) <= Constants::TOLERANCE)
			ca = 0.f;
		else if (abs(sa) <= Constants::TOLERANCE)
			sa = 0.f;
	}
	return
	{
		ca, sa, 0,
		-sa, ca, 0,
		0,  0,  1,
	};

}
inline Maths::Mat3 Maths::Mat3::Translate2D(const Vec2& _translation)
{
	return
	{
		1.f,			 0.f,			0.f,
		0.f,			 1.f,			0.f,
		_translation.x, _translation.y, 1.f
	};
}
inline Maths::Mat3 Maths::Mat3::Scale2D(const Vec2& _scaling)
{
	return
	{
		_scaling.x, 0.f,        0.f,
		0.f,        _scaling.y, 0.f,
		0.f,        0.f,        1.f
	};
}
inline Maths::Mat3 Maths::Mat3::Transform(const Vec2& _translation, float _angleInRad, const Vec2& _scaling)
{
	float ca = 1.f;
	float sa = 0.f;
	if (_angleInRad)
	{
		ca = std::cos(_angleInRad);
		sa = std::sin(_angleInRad);
		//Not necessary
		if (abs(ca) <= Constants::TOLERANCE)
			ca = 0.f;
		else if (abs(sa) <= Constants::TOLERANCE)
			sa = 0.f;
	}
	return
	{
		_scaling[0] * ca, _scaling[0] * sa, 0.f,
		_scaling[1] * -sa, _scaling[1] * ca, 0.f,
		_translation[0]  , _translation[1] , 1.f
	};

}

inline Maths::Mat3 Maths::Mat3::GetTranspose() const
{
	Mat3 temp;
	return Inverse(temp);
}
inline Maths::Mat3 Maths::Mat3::GetInverse()   const
{
	Mat3 temp;
	return Inverse(temp);
}
inline float Maths::Mat3::GetDeterminant()     const
{
	return data[0] * (data[4] * data[8] - data[7] * data[5])
		- data[1] * (data[3] * data[8] - data[6] * data[5])
		+ data[2] * (data[3] * data[7] - data[6] * data[4]);
}
inline float Maths::Mat3::GetTrace()           const
{
	return data[0] + data[4] + data[8];
}

//ASSINGMENT AND EQUALITY OPERATIONS :
inline Maths::Mat3 Maths::Mat3::operator = (float _data[9])
{
	return *this =
	{
		_data[0],
		_data[1],
		_data[2],

		_data[3],
		_data[4],
		_data[5],

		_data[6],
		_data[7],
		_data[8]
	};
}
inline Maths::Mat3 Maths::Mat3::operator = (const Mat4& _mat)
{
	return *this =
	{
		_mat.data[0],
		_mat.data[1],
		_mat.data[2],

		_mat.data[4],
		_mat.data[5],
		_mat.data[6],

		_mat.data[8],
		_mat.data[9],
		_mat.data[10]
	};
}

inline Maths::Mat3 Maths::Mat3::operator - (void)       const
{
	return
	{
		-data[0],
		-data[1],
		-data[2],

		-data[3],
		-data[4],
		-data[5],

		-data[6],
		-data[7],
		-data[8]
	};
}
inline bool Maths::Mat3::operator == (const Mat3& _mat) const
{
	for (int i = 0; i < 9; i++)
	{
		if (data[i] != _mat.data[i]) return false;
	}
	return true;
}
inline bool Maths::Mat3::operator != (const Mat3& _mat) const
{
	for (int i = 0; i < 9; i++)
	{
		if (data[i] == _mat.data[i]) return false;
	}
	return true;
}

inline Maths::Vec3 Maths::Mat3::operator [] (int _index) const
{
	assert(_index > -1 && _index < 4);
	return data3V[_index];
}

//Mat3 TO Mat3 OPERATIONS :
inline Maths::Mat3 Maths::Mat3::operator + (const Mat3& _mat) const
{
	return
	{
		data[0] + _mat.data[0],
		data[1] + _mat.data[1],
		data[2] + _mat.data[2],

		data[3] + _mat.data[3],
		data[4] + _mat.data[4],
		data[5] + _mat.data[5],

		data[6] + _mat.data[6],
		data[7] + _mat.data[7],
		data[8] + _mat.data[8]
	};
}
inline Maths::Mat3 Maths::Mat3::operator - (const Mat3& _mat) const
{
	return
	{
		data[0] - _mat.data[0],
		data[1] - _mat.data[1],
		data[2] - _mat.data[2],

		data[3] - _mat.data[3],
		data[4] - _mat.data[4],
		data[5] - _mat.data[5],

		data[6] - _mat.data[6],
		data[7] - _mat.data[7],
		data[8] - _mat.data[8]
	};
}
inline Maths::Mat3 Maths::Mat3::operator * (const Mat3& _mat) const
{
	return
	{

		data[0] * _mat.data[0] + data[3] * _mat.data[1] + data[6] * _mat.data[2],
		data[1] * _mat.data[0] + data[4] * _mat.data[1] + data[7] * _mat.data[2],
		data[2] * _mat.data[0] + data[5] * _mat.data[1] + data[8] * _mat.data[2],

		data[0] * _mat.data[3] + data[3] * _mat.data[4] + data[6] * _mat.data[5],
		data[1] * _mat.data[3] + data[4] * _mat.data[4] + data[7] * _mat.data[5],
		data[2] * _mat.data[3] + data[5] * _mat.data[4] + data[8] * _mat.data[5],

		data[0] * _mat.data[6] + data[3] * _mat.data[7] + data[6] * _mat.data[8],
		data[1] * _mat.data[6] + data[4] * _mat.data[7] + data[7] * _mat.data[8],
		data[2] * _mat.data[6] + data[5] * _mat.data[7] + data[8] * _mat.data[8]

	};
}

//Mat3 TO THIS OPERATIONS :
inline Maths::Mat3 Maths::Mat3::operator += (const Mat3& _mat)
{
	data[0] += _mat.data[0];
	data[1] += _mat.data[1];
	data[2] += _mat.data[2];

	data[3] += _mat.data[3];
	data[4] += _mat.data[4];
	data[5] += _mat.data[5];

	data[6] += _mat.data[6];
	data[7] += _mat.data[7];
	data[8] += _mat.data[8];
	return *this;
}
inline Maths::Mat3 Maths::Mat3::operator -= (const Mat3& _mat)
{
	data[0] -= _mat.data[0];
	data[1] -= _mat.data[1];
	data[2] -= _mat.data[2];

	data[3] -= _mat.data[3];
	data[4] -= _mat.data[4];
	data[5] -= _mat.data[5];

	data[6] -= _mat.data[6];
	data[7] -= _mat.data[7];
	data[8] -= _mat.data[8];
	return *this;
}
inline Maths::Mat3 Maths::Mat3::operator *= (const Mat3& _mat)
{
	return *this =
	{
		data[0] * _mat.data[0] + data[3] * _mat.data[1] + data[6] * _mat.data[2],
		data[1] * _mat.data[0] + data[4] * _mat.data[1] + data[7] * _mat.data[2],
		data[2] * _mat.data[0] + data[5] * _mat.data[1] + data[8] * _mat.data[2],

		data[0] * _mat.data[3] + data[3] * _mat.data[4] + data[6] * _mat.data[5],
		data[1] * _mat.data[3] + data[4] * _mat.data[4] + data[7] * _mat.data[5],
		data[2] * _mat.data[3] + data[5] * _mat.data[4] + data[8] * _mat.data[5],

		data[0] * _mat.data[6] + data[3] * _mat.data[7] + data[6] * _mat.data[8],
		data[1] * _mat.data[6] + data[4] * _mat.data[7] + data[7] * _mat.data[8],
		data[2] * _mat.data[6] + data[5] * _mat.data[7] + data[8] * _mat.data[8]
	};
}

//Sca TO Mat3 OPERATIONS :
inline Maths::Mat3 Maths::Mat3::operator * (float _sca) const
{
	return
	{

		data[0] * _sca,
		data[1] * _sca,
		data[2] * _sca,

		data[3] * _sca,
		data[4] * _sca,
		data[5] * _sca,

		data[6] * _sca,
		data[7] * _sca,
		data[8] * _sca

	};
}
inline Maths::Mat3 Maths::Mat3::operator / (float _sca) const
{
	return
	{

		data[0] / _sca,
		data[1] / _sca,
		data[2] / _sca,

		data[3] / _sca,
		data[4] / _sca,
		data[5] / _sca,

		data[6] / _sca,
		data[7] / _sca,
		data[8] / _sca

	};
}

//Sca TO This OPERATIONS :
inline Maths::Mat3 Maths::Mat3::operator *= (float _sca)
{
	data[0] *= _sca;
	data[1] *= _sca;
	data[2] *= _sca;

	data[3] *= _sca;
	data[4] *= _sca;
	data[5] *= _sca;

	data[6] *= _sca;
	data[7] *= _sca;
	data[8] *= _sca;

	return *this;
}
inline Maths::Mat3 Maths::Mat3::operator /= (float _sca)
{
	data[0] /= _sca;
	data[1] /= _sca;
	data[2] /= _sca;

	data[3] /= _sca;
	data[4] /= _sca;
	data[5] /= _sca;

	data[6] /= _sca;
	data[7] /= _sca;
	data[8] /= _sca;

	return *this;
}

//Mat3 TO Vec2 OPERATIONS :
inline Maths::Vec2 Maths::Mat3::operator * (const Vec2& _vec) const
{
	return
	{

		data[0] * _vec.x + data[1] * _vec.y + data[2],

		data[3] * _vec.x + data[4] * _vec.y + data[5]

	};
}

//Mat3 TO Vec3 OPERATIONS :
inline Maths::Vec3 Maths::Mat3::operator * (const Vec3& _vec) const
{
	return
	{

		data[0] * _vec.x + data[1] * _vec.y + data[2] * _vec.z,

		data[3] * _vec.x + data[4] * _vec.y + data[5] * _vec.z,

		data[6] * _vec.x + data[7] * _vec.y + data[8] * _vec.z

	};
}

#pragma endregion Mat3
#endif

#ifndef DISABLE_MAT4
/************************\
 *-------MATRIX_4-------*
\************************/
#pragma region Mat4


#pragma endregion Mat4
#endif

#pragma endregion Matrix