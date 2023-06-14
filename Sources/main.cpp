#include <iostream>

#include "LibMath/Maths.hpp"
#include "glm/glm.hpp"
#include "VTest/VTest.hpp"

NAMESPACE(Vector2)
	NAMESPACE(Vector2_Constructor)

		TEST(Vec2_Constructor_default) {
			Maths::Vec2 VM; glm::vec2 VG(0); // test default constructor

			COMPARE(VM.x, VG.x);
			COMPARE(VM.y, VG.y);
		}

		TEST(Vec2_Constructor_Scalar) {
			Maths::Vec2 VM(3); glm::vec2 VG(3); // test one scalar constructor

			COMPARE(VM.x, VG.x);
			COMPARE(VM.y, VG.y);
		}

		TEST(Vec2_Constructor_x_y) {
			Maths::Vec2 VM(1, 2); glm::vec2 VG(1, 2); // test constructor with x , y parameter

			COMPARE(VM.x, VG.x);
			COMPARE(VM.y, VG.y);
		}

		TEST(Vec2_Constructor_Vec3) {
			Maths::Vec3 TMP_1(3, 4, 5); glm::vec3 TMP_2(3, 4, 5);
			Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec3

			COMPARE(VM.x, VG.x);
			COMPARE(VM.y, VG.y);
		}

		TEST(Vec2_Constructor_Vec4) {
			Maths::Vec4 TMP_1(6,7,8,9); glm::vec4 TMP_2(6,7,8,9);
			Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec4

			COMPARE(VM.x, VG.x);
			COMPARE(VM.y, VG.y);
		}

	END_NAMESPACE(Vector2_Constructor)
END_NAMESPACE(Vector2)

int main()
{
	system("cls");
	std::cout << "Library used for the tests : glm\n";
	runTests();
	system("pause");
	return 0;
}