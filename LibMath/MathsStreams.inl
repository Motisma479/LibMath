/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Unit Test Based on : OpenGL Mathematics (GLM) *
* Last Update : 03/10/2024                      *
\***********************************************/
#include "MathsStreams.hpp"

using namespace Maths;

inline std::ostream& operator<<(std::ostream& _os, const Vec2& _vec)
{
    return _os << '[' << _vec.x << ", " << _vec.y << ']';
}

inline std::ostream& operator<<(std::ostream& _os, const Vec3& _vec)
{
    return _os << '[' << _vec.x << ", " << _vec.y << ", " << _vec.z << ']';
}

inline std::ostream& operator<<(std::ostream& _os, const Vec4& _vec)
{
    return _os << '[' << _vec.x << ", " << _vec.y << ", " << _vec.z << ", " << _vec.w << ']';
}

inline std::ostream& operator<<(std::ostream& _os, const Mat3& _mat)
{
    return _os << '[' << _mat[0] << ", " << _mat[1] << ", " << _mat[2] << ']';
}

inline std::ostream& operator<<(std::ostream& _os, const Mat4& _mat)
{
    return _os << '[' << _mat[0] << ", " << _mat[1] << ", " << _mat[2] << ", " << _mat[3] << ']';
}

inline std::ostream& operator<<(std::ostream& _os, const Quat& _quat)
{
    return _os << '[' << _quat.x << "i, " << _quat.y << "j, " << _quat.z << "k, " << _quat.w << ']';
}