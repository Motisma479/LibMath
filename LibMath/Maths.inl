/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 10/10/2024                      *
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
	return Vectors::DotProduct(*this, *this);
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
	return Vectors::DotProduct(*this, *this);
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
	return Vectors::DotProduct(*this, *this);
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

inline void MATHS_LIB_API Maths::Vectors::Normalize(Vec2& _vec)
{
	float m = _vec.GetMagnitude();
	if (m != 0.f)
		_vec.operator*=(1 / m);
}
inline void MATHS_LIB_API Maths::Vectors::Normalize(Vec3& _vec)
{
	float m = _vec.GetMagnitude();
	if (m != 0.f)
		_vec.operator*=(1 / m);
}
inline void MATHS_LIB_API Maths::Vectors::Normalize(Vec4& _vec)
{
	float m = _vec.GetMagnitude();
	if (m != 0.f)
		_vec.operator*=(1 / m);
}

inline float MATHS_LIB_API Maths::Vectors::DotProduct(const Vec2& _vecA, const Vec2& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y);
}
inline float MATHS_LIB_API Maths::Vectors::DotProduct(const Vec3& _vecA, const Vec3& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y + _vecA.z * _vecB.z);
}
inline float MATHS_LIB_API Maths::Vectors::DotProduct(const Vec4& _vecA, const Vec4& _vecB)
{
	return (_vecA.x * _vecB.x + _vecA.y * _vecB.y + _vecA.z * _vecB.z + _vecA.w * _vecB.w);
}

inline float MATHS_LIB_API Maths::Vectors::DistanceBetween(const Vec2& _vecA, const Vec2& _vecB)
{
	return sqrt((_vecA.x - _vecB.x) * (_vecA.x - _vecB.x) + (_vecA.y - _vecB.y) * (_vecA.y - _vecB.y));
}
inline float MATHS_LIB_API Maths::Vectors::DistanceBetween(const Vec3& _vecA, const Vec3& _vecB)
{
	return sqrt((_vecA.x - _vecB.x) * (_vecA.x - _vecB.x) + (_vecA.y - _vecB.y) * (_vecA.y - _vecB.y) + (_vecA.z - _vecB.z) * (_vecA.z - _vecB.z));
}
inline float MATHS_LIB_API Maths::Vectors::DistanceBetween(const Vec4& _vecA, const Vec4& _vecB)
{
	return sqrt((_vecA.x - _vecB.x) * (_vecA.x - _vecB.x) + (_vecA.y - _vecB.y) * (_vecA.y - _vecB.y) + (_vecA.z - _vecB.z) * (_vecA.z - _vecB.z) + (_vecA.w - _vecB.w) * (_vecA.w - _vecB.w));
}

inline float MATHS_LIB_API Maths::Vectors::AngleBetween(const Vec2& _vecA, const Vec2& _vecB)
{
	float angle = acos(DotProduct(_vecA, _vecB) / (_vecA.GetMagnitude() * _vecB.GetMagnitude()));
	if (CrossProduct(_vecA, _vecB) >= 0)
		return angle;
	return -angle;
}
inline float MATHS_LIB_API Maths::Vectors::AngleBetween(const Vec3& _vecA, const Vec3& _vecB)
{
	return acos(DotProduct(_vecA, _vecB) / (_vecA.GetMagnitude() * _vecB.GetMagnitude()));
}
inline float MATHS_LIB_API Maths::Vectors::AngleBetween(const Vec4& _vecA, const Vec4& _vecB)
{
	return acos(DotProduct(_vecA, _vecB) / (_vecA.GetMagnitude() * _vecB.GetMagnitude()));
}

inline float MATHS_LIB_API Maths::Vectors::CrossProduct(const Vec2& _vecA, const Vec2& _vecB)
{
	return _vecA.x * _vecB.y - _vecA.y * _vecB.x;
}

inline Maths::Vec3 MATHS_LIB_API Maths::Vectors::CrossProduct(const Vec3& _vecA, const Vec3& _vecB)
{
	return
	{
		_vecA.y * _vecB.z - _vecA.z * _vecB.y,
		_vecA.z * _vecB.x - _vecA.x * _vecB.z,
		_vecA.x * _vecB.y - _vecA.y * _vecB.x
	};
}
inline Maths::Vec3 MATHS_LIB_API Maths::Vectors::Rotate(const Vec3& _vec, float _angle, const Vec3& _axis)
{
	Quat rotator = Quaternions::FromAngleAxis(_angle, _axis);
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
	return matrixes::Inverse(temp);
}
inline Maths::Mat3 Maths::Mat3::GetInverse()   const
{
	Mat3 temp;
	return matrixes::Inverse(temp);
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

inline Maths::Mat4::Mat4(void)
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;

	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
	data[7] = 0;

	data[8] = 0;
	data[9] = 0;
	data[10] = 0;
	data[11] = 0;

	data[12] = 0;
	data[13] = 0;
	data[14] = 0;
	data[15] = 0;
}
inline Maths::Mat4::Mat4(float _data[16])
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
	data[9] = _data[9];
	data[10] = _data[10];
	data[11] = _data[11];

	data[12] = _data[12];
	data[13] = _data[13];
	data[14] = _data[14];
	data[15] = _data[15];
}
inline Maths::Mat4::Mat4(float _identityValue)
{
	data[0] = _identityValue;
	data[1] = 0.f;
	data[2] = 0.f;
	data[3] = 0.f;

	data[4] = 0.f;
	data[5] = _identityValue;
	data[6] = 0.f;
	data[7] = 0.f;

	data[8] = 0.f;
	data[9] = 0.f;
	data[10] = _identityValue;
	data[11] = 0.f;

	data[12] = 0.f;
	data[13] = 0.f;
	data[14] = 0.f;
	data[15] = _identityValue;
}
inline Maths::Mat4::Mat4(float _0, float _1, float _2, float _3,
	float _4, float _5, float _6, float _7,
	float _8, float _9, float _10, float _11,
	float _12, float _13, float _14, float _15)
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
	data[9] = _9;
	data[10] = _10;
	data[11] = _11;

	data[12] = _12;
	data[13] = _13;
	data[14] = _14;
	data[15] = _15;
}

inline Maths::Mat4::Mat4(const Mat3& _mat3)
{
	data[0] = _mat3.data[0];
	data[1] = _mat3.data[1];
	data[2] = _mat3.data[2];
	data[3] = 0.f;

	data[4] = _mat3.data[3];
	data[5] = _mat3.data[4];
	data[6] = _mat3.data[5];
	data[7] = 0.f;

	data[8] = _mat3.data[6];
	data[9] = _mat3.data[7];
	data[10] = _mat3.data[8];
	data[11] = 0.f;

	data[12] = 0.f;
	data[13] = 0.f;
	data[14] = 0.f;
	data[15] = 1.f;
}

inline Maths::Mat4::~Mat4(void) {}

inline Maths::Mat4 Maths::Mat4::Transform(const Vec3& _translation, const Vec3& _anglesInRad, const Vec3& _scaling)
{
	//rotation
	Mat4 temp = Rotate(_anglesInRad);

	//scaling
	temp.data[0] *= _scaling.x; temp.data[1] *= _scaling.x; temp.data[2] *= _scaling.x;
	temp.data[4] *= _scaling.y; temp.data[5] *= _scaling.y; temp.data[6] *= _scaling.y;
	temp.data[8] *= _scaling.z; temp.data[9] *= _scaling.z; temp.data[10] *= _scaling.z;

	//translation
	temp.data[12] = _translation.x;
	temp.data[13] = _translation.y;
	temp.data[14] = _translation.z;

	return temp;
}
inline Maths::Mat4 Maths::Mat4::Transform(const Vec3& _translation, const Quat& _rotation, const Vec3& _scaling)
{
	float xx = _rotation.x * _rotation.x;
	float yy = _rotation.y * _rotation.y;
	float zz = _rotation.z * _rotation.z;

	float xy = _rotation.x * _rotation.y;
	float xz = _rotation.x * _rotation.z;
	float xw = _rotation.x * _rotation.w;
	float yw = _rotation.y * _rotation.w;
	float yz = _rotation.y * _rotation.z;
	float zw = _rotation.z * _rotation.w;
	return {
			(1.f - 2.f * (yy + zz)) * _scaling.x,   (2.f * (xy + zw)) * _scaling.x, (2.f * (xz - yw)) * _scaling.x, 0.f,
			(2.f * (xy - zw)) * _scaling.y , (1.f - 2.f * (xx + zz)) * _scaling.y, (2.f * (yz + xw)) * _scaling.y,  0.f,
			(2.f * (xz + yw)) * _scaling.z , (2.f * (yz - xw)) * _scaling.z, (1.f - 2.f * (xx + yy)) * _scaling.z,  0.f,
			 _translation.x				   , _translation.y				   ,  _translation.z                     ,  1.f
	};
}
inline Maths::Mat4 Maths::Mat4::Rotate(const Vec3& _anglesInRad)
{
	float cosA = cos(_anglesInRad.x);
	float cosB = cos(_anglesInRad.y);
	float cosC = cos(_anglesInRad.z);

	float sinA = sin(_anglesInRad.x);
	float sinB = sin(_anglesInRad.y);
	float sinC = sin(_anglesInRad.z);

	return
	{
		cosB * cosC ,  sinA * sinB * cosC + cosA * sinC, -cosA * sinB * cosC + sinA * sinC, 0.f,
		-cosB * sinC, -sinA * sinB * sinC + cosA * cosC,  cosA * sinB * sinC + sinA * cosC, 0.f,
		sinB		, -sinA * cosB					   , cosA * cosB					  , 0.f,
		0.f			,0.f							   ,0.f								  ,1.f
	};
}
inline Maths::Mat4 Maths::Mat4::RotateX(float _angleInRad)
{
	float cosX = cos(_angleInRad);
	float sinX = sin(_angleInRad);

	return
	{
		1.f,
		0.f,
		0.f,
		0.f,

		0.f,
		cosX,
		sinX,
		0.f,

		0.f,
		-sinX,
		cosX,
		0.f,

		0.f,
		0.f,
		0.f,
		1.f
	};
}

inline Maths::Mat4 Maths::Mat4::RotateY(float _angleInRad)
{
	float cosY = cos(_angleInRad);
	float sinY = sin(_angleInRad);

	return
	{
		cosY,
		0.f,
		-sinY,
		0.f,

		0.f,
		1.f,
		0.f,
		0.f,

		sinY,
		0.f,
		cosY,
		0.f,

		0.f,
		0.f,
		0.f,
		1.f
	};
}

inline Maths::Mat4 Maths::Mat4::RotateZ(float _angleInRad)
{
	float cosZ = cos(_angleInRad);
	float sinZ = sin(_angleInRad);

	return
	{
		cosZ,
		sinZ,
		0.f,
		0.f,

		-sinZ,
		cosZ,
		0.f,
		0.f,

		0.f,
		0.f,
		1.f,
		0.f,

		0.f,
		0.f,
		0.f,
		1.f
	};
}

inline Maths::Mat4 Maths::Mat4::Translate(const Vec3& _translation)
{
	return
	{
		 1.f,
		 0.f,
		 0.f,
		 0.f,

		 0.f,
		 1.f,
		 0.f,
		 0.f,

		 0.f,
		 0.f,
		 1.f,
		 0.f,

		 _translation.x,
		 _translation.y,
		 _translation.z,
		 1.f
	};
}

inline Maths::Mat4 Maths::Mat4::Scale(const Vec3& _scaling)
{
	return
	{
		_scaling.x,
		0.f,
		0.f,
		0.f,

		0.f,
		_scaling.y,
		0.f,
		0.f,

		0.f,
		0.f,
		_scaling.z,
		0.f,

		0.f,
		0.f,
		0.f,
		1.f
	};;
}

inline float Maths::Mat4::GetDeterminant() const
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
inline float Maths::Mat4::GetTrace() const
{
	return data[0] + data[5] + data[10] + data[15];
}

inline Maths::Mat4 Maths::Mat4::GetInverse() const
{
	//DISCLAIMER: this abomination runs 15 times faster than its equivalent from glm
	float det = GetDeterminant();
	if (det != 0.f)
	{
		det = 1.f / det;

		float values[18] =
		{
			(data[10] * data[15] - data[11] * data[14]),
			(data[6] * data[15] - data[7] * data[14]),
			(data[6] * data[11] - data[7] * data[10]),
			(data[2] * data[15] - data[3] * data[14]),
			(data[2] * data[11] - data[3] * data[10]),
			(data[2] * data[7] - data[3] * data[6]),
			(data[9] * data[15] - data[11] * data[13]),
			(data[5] * data[15] - data[7] * data[13]),
			(data[5] * data[11] - data[7] * data[9]),
			(data[1] * data[15] - data[3] * data[13]),
			(data[1] * data[11] - data[3] * data[9]),
			(data[1] * data[7] - data[3] * data[5]),
			(data[9] * data[14] - data[10] * data[13]),
			(data[5] * data[14] - data[6] * data[13]),
			(data[5] * data[10] - data[6] * data[9]),
			(data[1] * data[14] - data[2] * data[13]),
			(data[1] * data[10] - data[2] * data[9]),
			(data[1] * data[6] - data[2] * data[5])
		};

		return
		{
			(data[5] * (values[0])
			- data[9] * (values[1])
			+ data[13] * values[2]) * det,

			-(data[1] * (values[0])
			- data[9] * (values[3])
			+ data[13] * (values[4])) * det,

			(data[1] * (values[1])
			- data[5] * (values[3])
			+ data[13] * (values[5])) * det,

			-(data[1] * values[2]
			- data[5] * (values[4])
			+ data[9] * (values[5])) * det,

			-(data[4] * (values[0])
			- data[8] * (values[1])
			+ data[12] * values[2]) * det,

			(data[0] * (values[0])
			- data[8] * (values[3])
			+ data[12] * (values[4])) * det,

			-(data[0] * (values[1])
			- data[4] * (values[3])
			+ data[12] * (values[5])) * det,

			(data[0] * values[2]
			- data[4] * (values[4])
			+ data[8] * (values[5])) * det,

			(data[4] * (values[6])
			- data[8] * (values[7])
			+ data[12] * (values[8])) * det,

			-(data[0] * (values[6])
			- data[8] * (values[9])
			+ data[12] * (values[10])) * det,

			(data[0] * (values[7])
			- data[4] * (values[9])
			+ data[12] * (values[11])) * det,

			-(data[0] * (values[8])
			- data[4] * (values[10])
			+ data[8] * (values[11])) * det,

			-(data[4] * (values[12])
			- data[8] * (values[13])
			+ data[12] * (values[14])) * det,

			(data[0] * (values[12])
			- data[8] * (values[15])
			+ data[12] * (values[16])) * det,

			-(data[0] * (values[13])
			- data[4] * (values[15])
			+ data[12] * (values[17])) * det,

			(data[0] * (values[14])
			- data[4] * (values[16])
			+ data[8] * (values[17])) * det
		};
	}
	return *this;
}

inline Maths::Mat4 Maths::Mat4::GetTranspose() const
{
	return
	{
		data[0],
		data[4],
		data[8],
		data[12],

		data[1],
		data[5],
		data[9],
		data[13],

		data[2],
		data[6],
		data[10],
		data[14],

		data[3],
		data[7],
		data[11],
		data[15]
	};
}

inline Maths::Mat4 Maths::Mat4::operator = (float _data[16])
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
	data[9] = _data[9];
	data[10] = _data[10];
	data[11] = _data[11];

	data[12] = _data[12];
	data[13] = _data[13];
	data[14] = _data[14];
	data[15] = _data[15];

	return *this;
}

inline Maths::Mat4 Maths::Mat4::operator - (void) const
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

		-data[8],
		-data[9],
		-data[10],
		-data[11],

		-data[12],
		-data[13],
		-data[14],
		-data[15]
	};
}
inline bool Maths::Mat4::operator == (const Mat4& _mat) const
{
	for (int i = 0; i < 16; i++)
	{
		if (data[i] != _mat.data[i]) return false;
	}
	return true;
}
inline bool Maths::Mat4::operator != (const Mat4& _mat) const
{
	for (int i = 0; i < 16; i++)
	{
		if (data[i] != _mat.data[i]) return true;
	}
	return false;
}

inline Maths::Vec4 Maths::Mat4::operator [] (int _index) const
{
	assert(_index > -1 && _index < 5);
	return data4V[_index];
}

inline Maths::Mat4 Maths::Mat4::operator + (const Mat4& _mat) const
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

		data[8] + _mat.data[8],
		data[9] + _mat.data[9],
		data[10] + _mat.data[10],
		data[11] + _mat.data[11],

		data[12] + _mat.data[12],
		data[13] + _mat.data[13],
		data[14] + _mat.data[14],
		data[15] + _mat.data[15]
	};
}
inline Maths::Mat4 Maths::Mat4::operator - (const Mat4& _mat) const
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

		data[8] - _mat.data[8],
		data[9] - _mat.data[9],
		data[10] - _mat.data[10],
		data[11] - _mat.data[11],

		data[12] - _mat.data[12],
		data[13] - _mat.data[13],
		data[14] - _mat.data[14],
		data[15] - _mat.data[15]
	};
}
inline Maths::Mat4 Maths::Mat4::operator * (const Mat4& _mat) const
{
	return
	{
		data[0] * _mat.data[0] + data[4] * _mat.data[1] + data[8] * _mat.data[2] + data[12] * _mat.data[3],
		data[1] * _mat.data[0] + data[5] * _mat.data[1] + data[9] * _mat.data[2] + data[13] * _mat.data[3],
		data[2] * _mat.data[0] + data[6] * _mat.data[1] + data[10] * _mat.data[2] + data[14] * _mat.data[3],
		data[3] * _mat.data[0] + data[7] * _mat.data[1] + data[11] * _mat.data[2] + data[15] * _mat.data[3],

		data[0] * _mat.data[4] + data[4] * _mat.data[5] + data[8] * _mat.data[6] + data[12] * _mat.data[7],
		data[1] * _mat.data[4] + data[5] * _mat.data[5] + data[9] * _mat.data[6] + data[13] * _mat.data[7],
		data[2] * _mat.data[4] + data[6] * _mat.data[5] + data[10] * _mat.data[6] + data[14] * _mat.data[7],
		data[3] * _mat.data[4] + data[7] * _mat.data[5] + data[11] * _mat.data[6] + data[15] * _mat.data[7],

		data[0] * _mat.data[8] + data[4] * _mat.data[9] + data[8] * _mat.data[10] + data[12] * _mat.data[11],
		data[1] * _mat.data[8] + data[5] * _mat.data[9] + data[9] * _mat.data[10] + data[13] * _mat.data[11],
		data[2] * _mat.data[8] + data[6] * _mat.data[9] + data[10] * _mat.data[10] + data[14] * _mat.data[11],
		data[3] * _mat.data[8] + data[7] * _mat.data[9] + data[11] * _mat.data[10] + data[15] * _mat.data[11],

		data[0] * _mat.data[12] + data[4] * _mat.data[13] + data[8] * _mat.data[14] + data[12] * _mat.data[15],
		data[1] * _mat.data[12] + data[5] * _mat.data[13] + data[9] * _mat.data[14] + data[13] * _mat.data[15],
		data[2] * _mat.data[12] + data[6] * _mat.data[13] + data[10] * _mat.data[14] + data[14] * _mat.data[15],
		data[3] * _mat.data[12] + data[7] * _mat.data[13] + data[11] * _mat.data[14] + data[15] * _mat.data[15]
	};
}

inline Maths::Mat4 Maths::Mat4::operator += (const Mat4& _mat)
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
	data[9] += _mat.data[9];
	data[10] += _mat.data[10];
	data[11] += _mat.data[11];

	data[12] += _mat.data[12];
	data[13] += _mat.data[13];
	data[14] += _mat.data[14];
	data[15] += _mat.data[15];
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator -= (const Mat4& _mat)
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
	data[9] -= _mat.data[9];
	data[10] -= _mat.data[10];
	data[11] -= _mat.data[11];

	data[12] -= _mat.data[12];
	data[13] -= _mat.data[13];
	data[14] -= _mat.data[14];
	data[15] -= _mat.data[15];
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator *= (const Mat4& _mat)
{
	return *this =
	{
		data[0] * _mat.data[0] + data[4] * _mat.data[1] + data[8] * _mat.data[2] + data[12] * _mat.data[3],
		data[1] * _mat.data[0] + data[5] * _mat.data[1] + data[9] * _mat.data[2] + data[13] * _mat.data[3],
		data[2] * _mat.data[0] + data[6] * _mat.data[1] + data[10] * _mat.data[2] + data[14] * _mat.data[3],
		data[3] * _mat.data[0] + data[7] * _mat.data[1] + data[11] * _mat.data[2] + data[15] * _mat.data[3],

		data[0] * _mat.data[4] + data[4] * _mat.data[5] + data[8] * _mat.data[6] + data[12] * _mat.data[7],
		data[1] * _mat.data[4] + data[5] * _mat.data[5] + data[9] * _mat.data[6] + data[13] * _mat.data[7],
		data[2] * _mat.data[4] + data[6] * _mat.data[5] + data[10] * _mat.data[6] + data[14] * _mat.data[7],
		data[3] * _mat.data[4] + data[7] * _mat.data[5] + data[11] * _mat.data[6] + data[15] * _mat.data[7],

		data[0] * _mat.data[8] + data[4] * _mat.data[9] + data[8] * _mat.data[10] + data[12] * _mat.data[11],
		data[1] * _mat.data[8] + data[5] * _mat.data[9] + data[9] * _mat.data[10] + data[13] * _mat.data[11],
		data[2] * _mat.data[8] + data[6] * _mat.data[9] + data[10] * _mat.data[10] + data[14] * _mat.data[11],
		data[3] * _mat.data[8] + data[7] * _mat.data[9] + data[11] * _mat.data[10] + data[15] * _mat.data[11],

		data[0] * _mat.data[12] + data[4] * _mat.data[13] + data[8] * _mat.data[14] + data[12] * _mat.data[15],
		data[1] * _mat.data[12] + data[5] * _mat.data[13] + data[9] * _mat.data[14] + data[13] * _mat.data[15],
		data[2] * _mat.data[12] + data[6] * _mat.data[13] + data[10] * _mat.data[14] + data[14] * _mat.data[15],
		data[3] * _mat.data[12] + data[7] * _mat.data[13] + data[11] * _mat.data[14] + data[15] * _mat.data[15]
	};
}

inline Maths::Mat4 Maths::Mat4::operator * (float _sca) const
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

		data[8] * _sca,
		data[9] * _sca,
		data[10] * _sca,
		data[11] * _sca,

		data[12] * _sca,
		data[13] * _sca,
		data[14] * _sca,
		data[15] * _sca
	};
}
inline Maths::Mat4 Maths::Mat4::operator / (float _sca) const
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

		data[8] / _sca,
		data[9] / _sca,
		data[10] / _sca,
		data[11] / _sca,

		data[12] / _sca,
		data[13] / _sca,
		data[14] / _sca,
		data[15] / _sca
	};
}

inline Maths::Mat4 Maths::Mat4::operator *= (float _sca)
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
	data[9] *= _sca;
	data[10] *= _sca;
	data[11] *= _sca;

	data[12] *= _sca;
	data[13] *= _sca;
	data[14] *= _sca;
	data[15] *= _sca;
	return *this;
}
inline Maths::Mat4 Maths::Mat4::operator /= (float _sca)
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
	data[9] /= _sca;
	data[10] /= _sca;
	data[11] /= _sca;

	data[12] /= _sca;
	data[13] /= _sca;
	data[14] /= _sca;
	data[15] /= _sca;
	return *this;
}

inline Maths::Vec3 Maths::Mat4::operator * (const Vec3& _vec) const
{
	return
	{
		data[0] * _vec.x + data[1] * _vec.y + data[2] * _vec.z + data[3],

		data[4] * _vec.x + data[5] * _vec.y + data[6] * _vec.z + data[7],

		data[8] * _vec.x + data[9] * _vec.y + data[10] * _vec.z + data[11]
	};
}

inline Maths::Vec4 Maths::Mat4::operator * (const Vec4& _vec) const
{
	return
	{
		data[0] * _vec.x + data[1] * _vec.y + data[2] * _vec.z + data[3] * _vec.w,

		data[4] * _vec.x + data[5] * _vec.y + data[6] * _vec.z + data[7] * _vec.w,

		data[8] * _vec.x + data[9] * _vec.y + data[10] * _vec.z + data[11] * _vec.w,

		data[12] * _vec.x + data[13] * _vec.y + data[14] * _vec.z + data[15] * _vec.w
	};
}

inline Maths::Mat4 Maths::matrixes::Transpose(Mat4& _mat)
{
	_mat = _mat.GetTranspose();
}

inline Maths::Mat4 Maths::matrixes::Inverse(Mat4& _mat)
{
	_mat = _mat.GetInverse();
}

inline Maths::Mat4 Maths::matrixes::Frustum(float _left, float _right, float _bottom, float _top, float _near, float _far)
{
	assert((_right - _left) && (_top - _bottom) && (_far - _near));
	float iHdist = 1.f / (_right - _left);
	float iVdist = 1.f / (_top - _bottom);
	float iZdist = 1.f / (_far - _near);
	//Same computation for [2][2] and [2][3]
	float quickZ = (_far + _near) * _near * iZdist;

	return { 2.f * _near * iHdist , 0.f					   , 0.f						,0.f,
				0.f					 , 2.f * _near * iVdist , 0.f						,0.f,
			(_right + _left) * iHdist ,(_top + _bottom) * iVdist,-quickZ						,0.f,
				0.f					 , 0.f					   ,-2.f * quickZ				,1.f };
}
inline Maths::Mat4 Maths::matrixes::Ortho(float _left, float _right, float _bottom, float _top, float _near, float _far)
{
	assert((_right - _left) && (_top - _bottom) && (_far - _near));
	float iHdist = 1.f / (_right - _left);
	float iVdist = 1.f / (_top - _bottom);
	float iZdist = 1.f / (_far - _near);

	return { 2.f * iHdist			 ,0.f						,0.f					 , 0.f,
				0.f					 ,2.f * iVdist				,0.f					 , 0.f,
				0.f	  	             ,0.f						,-2.f * iZdist			 , 0.f ,
				-(_right + _left) * iHdist                  ,-(_top + _bottom) * iVdist                       ,-(_far + _near) * iZdist                     , 1.f };
}

//Doesn't assume all vec3 are normalized
inline Maths::Mat4 Maths::matrixes::LookAt(float _eyeX, float _eyeY, float _eyeZ, float _centerX, float _centerY, float _centerZ, float _upX, float _upY, float _upZ)
{
	return LookAt(Vec3(_eyeX, _eyeY, _eyeZ), Vec3(_centerX, _centerY, _centerZ), Vec3(_upX, _upY, _upZ));
}
//Doesn't assume all vec3 are normalized
inline Maths::Mat4 Maths::matrixes::LookAt(Vec3 _eye, Vec3 _center, Vec3 _up)
{
	Vec3 forward = (_center - _eye).GetNormalized();
	Vectors::Normalize(_up);
	Vec3 side = Vectors::CrossProduct(forward, _up);
	Vec3 newUp = Vectors::CrossProduct(side, _up);// Should be the same as previous, just a check

	return { side.x, newUp.x, -forward.x, 0.f,
			 side.y, newUp.y, -forward.y, 0.f,
			 side.z, newUp.z, -forward.z, 0.f,
			 0.f	  , 0.f	   ,  0.f	, 1.f };
}
//Doesn't assume all vec3 are normalized
inline Maths::Mat4 Maths::matrixes::LookAt(Vec3 _forward, Vec3 _localUp)
{
	Vectors::Normalize(_forward);
	Vectors::Normalize(_localUp);
	Vec3 side = Vectors::CrossProduct(_forward, _localUp);

	return { side.x, _localUp.x, -_forward.x, 0.f,
			 side.y, _localUp.y, -_forward.y, 0.f,
			 side.z, _localUp.z, -_forward.z, 0.f,
			 0.f	  , 0.f	   ,  0.f	   , 1.f };
}
//Assumes all vec3 are normalized
inline Maths::Mat4 Maths::matrixes::LookAtNormalized(Vec3 _eye, Vec3 _center, Vec3 _up)
{
	Vec3 forward = (_center - _eye);
	Vec3 side = Vectors::CrossProduct(forward, _up);
	Vec3 newUp = Vectors::CrossProduct(side, _up); // Should be the same as previous, just a check

	return { side.x, newUp.x, -forward.x, 0.f,
			 side.y, newUp.y, -forward.y, 0.f,
			 side.z, newUp.z, -forward.z, 0.f,
			 0.f	  , 0.f	   ,  0.f	   , 1.f };
}
//Assumes all vec3 are normalized
inline Maths::Mat4 Maths::matrixes::LookAtNormalized(Vec3 _forward, Vec3 _localUp)
{
	Vec3 side = Vectors::CrossProduct(_forward, _localUp);

	return { side.x, _localUp.x, -_forward.x, 0.f,
			 side.y, _localUp.y, -_forward.y, 0.f,
			 side.z, _localUp.z, -_forward.z, 0.f,
			 0.f	  , 0.f	   ,  0.f	   , 1.f };
}

inline Maths::Mat4 Maths::matrixes::Perspective(float _fovY, float _aspect, float _near, float _far)
{
	using namespace Constants;
	// Safe tan
	float f = 0.f;
	// Could be too specific
	if (_fovY != 0.f && _fovY != PI)
		f = tan((PI - _fovY) * 0.5f);
	float iDist = 1.f / (_near - _far);
	return { f / _aspect,0.f	,0.f						, 0.f,
				0.f		,f		,0.f						, 0.f,
				0.f		,0.f	,(_far + _near) * iDist		,-1.f,
				0.f		,0.f	,2.f * _far * _near * iDist , 0.f };
}


#pragma endregion Mat4
#endif

#pragma endregion Matrix

#ifndef DISABLE_QUAT
/************************\
 *---------QUAT---------*
\************************/
#pragma region Quat


#pragma endregion Quat
#endif