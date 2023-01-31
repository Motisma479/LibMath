#include <iostream>

#include "Maths.hpp"

#if ENABLE_VEC2
Maths::Vec2 sampleVec2(2, 4);
#endif
#if ENABLE_VEC3
Maths::Vec3 sampleVec3(3, 6, 9);
#endif
#if ENABLE_VEC4
Maths::Vec4 sampleVec4(4, 8, 12, 16);
#endif

int main()
{
	std::cout << "Launch" << std::endl;

#if ENABLE_VEC2
	std::cout << "\n--VECTOR_2--" << std::endl;

	Maths::Vec2 vec1;
	std::cout << "\nwaited result : x = 0, y = 0. The result :" << std::endl;
	vec1.Print();

	Maths::Vec2 vec2(8.f);
	std::cout << "\nwaited result : x = 8, y = 8. The result :" << std::endl;
	vec2.Print();
	
	Maths::Vec2 vec3(8.f,16.f);
	std::cout << "\nwaited result : x = 8, y = 16. The result :" << std::endl;
	vec3.Print();

	Maths::Vec2 vec4(sampleVec2);
	std::cout << "\nwaited result : x = 2, y = 4. The result :" << std::endl;
	vec4.Print();
#if ENABLE_VEC3
	Maths::Vec2 vec5(sampleVec3);
	std::cout << "\nwaited result : x = 3, y = 6. The result :" << std::endl;
	vec5.Print();
#endif
#if ENABLE_VEC4
	Maths::Vec2 vec6(sampleVec4);
	std::cout << "\nwaited result : x = 4, y = 8. The result :" << std::endl;
	vec6.Print();
#endif
#endif
#if ENABLE_MAT3
	std::cout << "\n--MAT_3--" << std::endl;

	Maths::Mat3 mat1;
	std::cout << "\nwaited result : \n[ 0  0  0 ]\n[ 0  0  0 ]\n[ 0  0  0 ]\nThe result :" << std::endl;
	mat1.Print();

	float mat2Data[9] = { 1,2,3,4,5,6,7,8,9 };
	Maths::Mat3 mat2(mat2Data);
	std::cout << "\nwaited result : \n[ 1  4  7 ]\n[ 2  5  8 ]\n[ 3  6  9 ]\nThe result :" << std::endl;
	mat2.Print();

#endif
	return 0;
}