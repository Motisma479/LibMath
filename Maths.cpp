#include "Maths.hpp"

#include <iostream>

#if PRINT_FUNCTION

	#if ENABLE_VEC2
	void Maths::Vec2::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ";" << std::endl;
	}
	#endif //ENABLE_VEC2

	#if ENABLE_VEC3
	void Maths::Vec3::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ", z = " << z << ";" << std::endl;
	}
	#endif //ENABLE_VEC3

	#if ENABLE_VEC4
	void Maths::Vec4::Print()
	{
		std::cout << this << " Value : x = " << x << ", y = " << y << ", z = " << z << ", w = " << w << ";" << std::endl;
	}
	#endif //ENABLE_VEC4

	#if ENABLE_MAT3
	void Maths::Mat3::Print()
	{
		std::cout << this << " Value :" << std::endl;
		std::cout << "--------------------" << std::endl;
		for (int y = 0; y < 3; y++)
		{
			std::cout << '[';
			for (int x = 0; x < 3; x++)
			{
				std::cout << ' ' << data[x][y] << ' ';
			}
			std::cout << ']' << std::endl;
		}
		std::cout << "Order:" << std::endl;
		std::cout << '[';
		for (int y = 0; y < 9; y++)
		{

			std::cout << ' ' << (*data)[y] << ' ';
		}
		std::cout << ']' << std::endl;
		std::cout << "--------------------" << std::endl;
	}
	#endif //ENABLE_MAT3

	#if ENABLE_MAT4
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

