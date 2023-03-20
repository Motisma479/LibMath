#include "Maths.hpp"

#include <iostream>

#ifdef PRINT_FUNCTION

	#ifdef ENABLE_VEC2
	void Maths::Vec2::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ";" << std::endl;
	}
	#endif //ENABLE_VEC2
	#ifdef ENABLE_IVEC2
	void Maths::IVec2::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ";" << std::endl;
	}
	#endif //ENABLE_IVEC2

	#ifdef ENABLE_VEC3
	void Maths::Vec3::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ", z = " << z << ";" << std::endl;
	}
	#endif //ENABLE_VEC3
	#ifdef ENABLE_IVEC3
	void Maths::IVec3::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ", z = " << z << ";" << std::endl;
	}
	#endif //ENABLE_IVEC3

	#ifdef ENABLE_VEC4
	void Maths::Vec4::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ", z = " << z << ", w = " << w << ";" << std::endl;
	}
	#endif //ENABLE_VEC4
	#ifdef ENABLE_IVEC4
	void Maths::IVec4::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ", z = " << z << ", w = " << w << ";" << std::endl;
	}
	#endif //ENABLE_IVEC4

	#ifdef ENABLE_MAT3
	void Maths::Mat3::Print()
	{
		std::cout << this << " Value :" << std::endl;
		std::cout << "--------------------" << std::endl;

		for (int y = 0; y < 3; y++)
		{
			std::cout << '[';
			for (int x = 0; x < 3; x++)
			{
				std::cout << ' ' << data[y+x*3] << ' ';
			}
			std::cout << ']' << std::endl;
		}

		std::cout << "Order:" << std::endl;
		std::cout << '[';
		for (int i = 0; i < 9; i++)
		{

			std::cout << ' ' << data[i] << ' ';
		}
		std::cout << ']' << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	#endif //ENABLE_MAT3

	#ifdef ENABLE_MAT4
	void Maths::Mat4::Print()
	{
		std::cout << this << " Value :" << std::endl;
		std::cout << "--------------------" << std::endl;
		for (int y = 0; y < 4; y++)
		{
			std::cout << '[';
			for (int x = 0; x < 4; x++)
			{
				std::cout << ' ' << data[x][y] << ' ';
			}
			std::cout << ']' << std::endl;
		}
		std::cout << "Order:" << std::endl;
		std::cout << '[';
		for (int y = 0; y < 16; y++)
		{

			std::cout << ' ' << (*data)[y] << ' ';
		}
		std::cout << ']' << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	#endif //ENABLE_MAT4

#endif // PRINT_FUNCTION

