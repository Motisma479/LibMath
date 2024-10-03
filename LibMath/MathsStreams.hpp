/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 03/10/2024                      *
\***********************************************/
#pragma once
#include <iostream>
#include "Maths.hpp"

namespace Maths
{
	inline std::ostream& operator<<(std::ostream& _os, const Vec2& _vec);
	inline std::ostream& operator<<(std::ostream& _os, const Vec3& _vec);
	inline std::ostream& operator<<(std::ostream& _os, const Vec4& _vec);
	inline std::ostream& operator<<(std::ostream& _os, const Mat3& _mat);
	inline std::ostream& operator<<(std::ostream& _os, const Mat4& _mat);
	inline std::ostream& operator<<(std::ostream& _os, const Quat& _quat);
}

#include "MathsStreams.inl"