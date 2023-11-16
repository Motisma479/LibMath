#include <iostream>

#include "LibMath/Maths.hpp"

#include "glm/glm.hpp"
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VTest/VTest.hpp"

VTEST(Maths)
{
	NAMESPACE(Vector2)
	{

		NAMESPACE(Vector2_Constructor)
		{

			TEST(Vec2_Constructor_default)
			{
				Maths::Vec2 VM; glm::vec2 VG(0); // test default constructor

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
			}

			TEST(Vec2_Constructor_Scalar)
			{
				Maths::Vec2 VM(3); glm::vec2 VG(3); // test one scalar constructor

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
			}

			TEST(Vec2_Constructor_x_y)
			{
				Maths::Vec2 VM(1, 2); glm::vec2 VG(1, 2); // test constructor with x , y parameter

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
			}

			TEST(Vec2_Constructor_Vec3)
			{
				Maths::Vec3 TMP_1(3, 4, 5); glm::vec3 TMP_2(3, 4, 5);
				Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec3

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
			}

			TEST(Vec2_Constructor_Vec4)
			{
				Maths::Vec4 TMP_1(6, 7, 8, 9); glm::vec4 TMP_2(6, 7, 8, 9);
				Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec4

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
			}
		
		}

		NAMESPACE(Vector2_Utils)
		{

			TEST(Vec2_GetMagnitude)
			{
				Maths::Vec2 VM(2,5); glm::vec2 VG(2,5);
				
				COMPARE(VM.GetMagnitude(), glm::length(VG));
			}

			TEST(Vec2_GetMagnitudeSquared)
			{
				Maths::Vec2 VM(2, 5); glm::vec2 VG(2, 5);

				COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
			}

			TEST(Vec2_Normalize)
			{
				Maths::Vec2 VM(2, 5); glm::vec2 VG(2, 5);

				VM.Normalize();
				glm::vec2 tempG = glm::normalize(VG);

				COMPARE(VM.x, tempG.x);
				COMPARE(VM.y, tempG.y);
			}

			TEST(Vec2_GetNormalized)
			{
				Maths::Vec2 VM(2, 5); glm::vec2 VG(2, 5);

				Maths::Vec2 tempM = VM.GetNormalized();
				glm::vec2 tempG = glm::normalize(VG);

				COMPARE(tempM.x, tempG.x);
				COMPARE(tempM.y, tempG.y);
			}

			TEST(Vec2_GetPerpendicular)
			{
				Maths::Vec2 VM(2, 5); glm::vec2 VG(2, 5);

				Maths::Vec2 tempM = VM.GetPerpendicular();
				glm::vec2 tempG(-VG.y, VG.x);
				
				COMPARE(tempM.x, tempG.x);
				COMPARE(tempM.y, tempG.y);
			}

			TEST(Vec2_DotProduct)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);
				
				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				COMPARE(VMA.DotProduct(VMB), glm::dot(VGA, VGB));
			}

			TEST(Vec2_DotProduct_Static)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				COMPARE(Maths::Vec2::DotProduct(VMA, VMB), glm::dot(VGA, VGB));
			}
			
			TEST(Vec2_GetDistance)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				COMPARE(VMA.GetDistance(VMB), glm::distance(VGA, VGB));
			}

			TEST(Vec2_GetDistance_Static)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				COMPARE(Maths::Vec2::GetDistance(VMA, VMB), glm::distance(VGA, VGB));
			}

			TEST(Vec2_GetAngleBetween)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				VGA = glm::normalize(VGA);
				VGB = glm::normalize(VGB);

				COMPARE(VMA.GetAngleBetween(VMB), glm::degrees(glm::angle(VGA, VGB)));
			}

			TEST(Vec2_GetAngleBetween_Static)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				VGA = glm::normalize(VGA);
				VGB = glm::normalize(VGB);

				COMPARE(Maths::Vec2::GetAngleBetween(VMA, VMB), glm::degrees(glm::angle(VGA, VGB)));
			}
		
		}

		NAMESPACE(Vector2_Assignment_and_Equality_operations)
		{

			TEST(Vec2_Operator_equal_Vec)
			{
				Maths::Vec2 VMA(2, 5);

				Maths::Vec2 VMB;

				VMB = VMA;

				COMPARE(VMA.x, VMB.x);
				COMPARE(VMA.y, VMB.y);
			}

			TEST(Vec2_Operator_equal_Sca)
			{
				Maths::Vec2 VM;

				VM = 1;

				COMPARE(VM.x, 1);
				COMPARE(VM.y, 1);
			}

			TEST(Vec2_Operator_negate)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(-2, -5);

				COMPARE(-VMA.x, VMB.x);
				COMPARE(-VMA.y, VMB.y);
			}

			TEST(Vec2_Operator_isEqual)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(2, 5);
				Maths::Vec2 VMC(5, 2);

				COMPARE(VMA == VMB, true);
				COMPARE(VMA == VMC, false);
			}

			TEST(Vec2_Operator_isNotEqual)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(2, 5);
				Maths::Vec2 VMC(5, 2);

				COMPARE(VMA != VMB, false);
				COMPARE(VMA != VMC, true);
			}

		}
		
		NAMESPACE(Vector2_Vec2_to_Vec2_operations)
		{

			TEST(Vec2_Operator_Plus_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				Maths::Vec2 VMC = VMA + VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				glm::vec2 VGC = VGA + VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
			}

			TEST(Vec2_Operator_Minus_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				Maths::Vec2 VMC = VMA - VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				glm::vec2 VGC = VGA - VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
			}

			TEST(Vec2_Operator_Multiply_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				Maths::Vec2 VMC = VMA * VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				glm::vec2 VGC = VGA * VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
			}

			TEST(Vec2_Operator_Divide_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				Maths::Vec2 VMC = VMA / VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				glm::vec2 VGC = VGA / VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
			}

		}

		NAMESPACE(Vector2_Vec2_to_This_operations)
		{

			TEST(Vec2_Operator_PlusEqual_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				VMA += VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				VGA += VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

			TEST(Vec2_Operator_MinusEqual_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				VMA -= VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				VGA -= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

			TEST(Vec2_Operator_MultiplyEqual_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				VMA *= VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				VGA *= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

			TEST(Vec2_Operator_DivideEqual_Vec)
			{
				Maths::Vec2 VMA(2, 5);
				Maths::Vec2 VMB(5, 2);

				VMA /= VMB;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(5, 2);

				VGA /= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

		}

		NAMESPACE(Vector2_Scaler_to_Vec2_operations)
		{

			TEST(Vec2_Operator_Plus_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				Maths::Vec2 VMB = VMA + 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				glm::vec2 VGC = VGA + VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
			}

			TEST(Vec2_Operator_Minus_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				Maths::Vec2 VMB = VMA - 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				glm::vec2 VGC = VGA - VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
			}

			TEST(Vec2_Operator_Multiply_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				Maths::Vec2 VMB = VMA * 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				glm::vec2 VGC = VGA * VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
			}

			TEST(Vec2_Operator_Divide_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				Maths::Vec2 VMB = VMA / 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				glm::vec2 VGC = VGA / VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
			}

		}

		NAMESPACE(Vector2_Scaler_to_This_operations)
		{

			TEST(Vec2_Operator_PlusEqual_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				VMA += 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				VGA += VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

			TEST(Vec2_Operator_MinusEqual_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				VMA -= 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				VGA -= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

			TEST(Vec2_Operator_MultiplyEqual_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				VMA *= 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				VGA *= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

			TEST(Vec2_Operator_DivideEqual_Sca)
			{
				Maths::Vec2 VMA(2, 5);

				VMA /= 3;

				glm::vec2 VGA(2, 5);
				glm::vec2 VGB(3, 3);

				VGA /= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
			}

		}

	}

	NAMESPACE(Vector3)
	{

		NAMESPACE(Vector3_Constructor)
		{

			TEST(Vec3_Constructor_default)
			{
				Maths::Vec3 VM; glm::vec3 VG(0); // test default constructor

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
			}

			TEST(Vec3_Constructor_Scalar)
			{
				Maths::Vec3 VM(3); glm::vec3 VG(3); // test one scalar constructor

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
			}

			TEST(Vec3_Constructor_x_y_z)
			{
				Maths::Vec3 VM(1, 2, 3); glm::vec3 VG(1, 2, 3); // test constructor with x , y parameter

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
			}

			TEST(Vec3_Constructor_Vec2)
			{
				Maths::Vec2 TMP_1(3,4);
				Maths::Vec3 VM(TMP_1); glm::vec3 VG(3,4,0);

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
			}

			TEST(Vec3_Constructor_Vec2_z)
			{
				Maths::Vec2 TMP_1(3, 4);
				Maths::Vec3 VM(TMP_1, 5); glm::vec3 VG(3, 4, 5);

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
			}

			TEST(Vec3_Constructor_Vec4)
			{
				Maths::Vec4 TMP_1(6, 7, 8, 9); glm::vec4 TMP_2(6, 7, 8, 9);
				Maths::Vec3 VM(TMP_1); glm::vec3 VG(TMP_2); // test constructor from a Vec4

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
			}

		}

		NAMESPACE(Vector3_Utils)
		{

			TEST(Vec3_xy)
			{
				Maths::Vec3 VM1(1, 2, 3);
				Maths::Vec2 VM2(1, 2);

				COMPARE(VM1.xy().x, VM2.x);
				COMPARE(VM1.xy().y, VM2.y);
			}
			
			TEST(Vec3_xz)
			{
				Maths::Vec3 VM1(1, 2, 3);
				Maths::Vec2 VM2(1, 3);

				COMPARE(VM1.xz().x, VM2.x);
				COMPARE(VM1.xz().y, VM2.y);
			}

			TEST(Vec3_yz)
			{
				Maths::Vec3 VM1(1, 2, 3);
				Maths::Vec2 VM2(2, 3);

				COMPARE(VM1.yz().x, VM2.x);
				COMPARE(VM1.yz().y, VM2.y);
			}

			TEST(Vec3_GetMagnitude)
			{
				Maths::Vec3 VM(2, 5, 9); glm::vec3 VG(2, 5, 9);

				COMPARE(VM.GetMagnitude(), glm::length(VG));
			}

			TEST(Vec3_GetMagnitudeSquared)
			{
				Maths::Vec3 VM(2, 5, 9); glm::vec3 VG(2, 5, 9);

				COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
			}

			TEST(Vec3_Normalize)
			{
				Maths::Vec3 VM(2, 5, 9); glm::vec3 VG(2, 5, 9);

				VM.Normalize();
				glm::vec3 tempG = glm::normalize(VG);

				COMPARE(VM.x, tempG.x);
				COMPARE(VM.y, tempG.y);
				COMPARE(VM.z, tempG.z);
			}

			TEST(Vec3_GetNormalized)
			{
				Maths::Vec3 VM(2, 5, 9); glm::vec3 VG(2, 5, 9);

				Maths::Vec3 tempM = VM.GetNormalized();
				glm::vec3 tempG = glm::normalize(VG);

				COMPARE(tempM.x, tempG.x);
				COMPARE(tempM.y, tempG.y);
				COMPARE(tempM.z, tempG.z);
			}

			TEST(Vec3_DotProduct)
			{
				Maths::Vec3 VMA(2, 5, 9); 
				Maths::Vec3 VMB(9, 5, 2);

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				COMPARE(VMA.DotProduct(VMB), glm::dot(VGA, VGB));
			}

			TEST(Vec3_DotProduct_Static)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				COMPARE(Maths::Vec3::DotProduct(VMA, VMB), glm::dot(VGA, VGB));
			}

			TEST(Vec3_CrossProduct)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				Maths::Vec3 ResultM = VMA.CrossProduct(VMB);
				glm::vec3 ResultG = glm::cross(VGA, VGB);

				COMPARE(ResultM.x, ResultG.x);
				COMPARE(ResultM.y, ResultG.y);
				COMPARE(ResultM.z, ResultG.z);
			}

			TEST(Vec3_CrossProduct_Static)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				Maths::Vec3 ResultM = Maths::Vec3::CrossProduct(VMA, VMB);
				glm::vec3 ResultG = glm::cross(VGA, VGB);

				COMPARE(ResultM.x, ResultG.x);
				COMPARE(ResultM.y, ResultG.y);
				COMPARE(ResultM.z, ResultG.z);
			}

			TEST(Vec3_GetDistance)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				COMPARE(VMA.GetDistance(VMB), glm::distance(VGA, VGB));
			}

			TEST(Vec3_GetDistance_Static)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				COMPARE(Maths::Vec3::GetDistance(VMA, VMB), glm::distance(VGA, VGB));
			}

			TEST(Vec3_GetAngleBetween)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				/* /!\ glm seems not to be accurate
				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);
				VGA = glm::normalize(VGA);
				VGB = glm::normalize(VGB);
				COMPARE(VMA.GetAngleBetween(VMB), glm::degrees(glm::angle(VGA, VGB)));
				*/

				COMPARE(VMA.GetAngleBetween(VMB), 56.32058747374858F);
			}

			TEST(Vec3_GetAngleBetween_Static)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				/* /!\ glm seems not to be accurate
				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);
				VGA = glm::normalize(VGA);
				VGB = glm::normalize(VGB);
				COMPARE(Maths::Vec3::GetAngleBetween(VMA, VMB), glm::degrees(glm::angle(VGA, VGB)));
				*/

				COMPARE(Maths::Vec3::GetAngleBetween(VMA, VMB), 56.32058747374858F);
			}

		}

		NAMESPACE(Vector3_Assignment_and_Equality_operations)
		{

			TEST(Vec3_Operator_equal_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);

				Maths::Vec3 VMB;

				VMB = VMA;

				COMPARE(VMA.x, VMB.x);
				COMPARE(VMA.y, VMB.y);
				COMPARE(VMA.z, VMB.z);
			}

			TEST(Vec3_Operator_equal_Sca)
			{
				Maths::Vec3 VM;

				VM = 1;

				COMPARE(VM.x, 1);
				COMPARE(VM.y, 1);
				COMPARE(VM.z, 1);
			}

			TEST(Vec3_Operator_negate)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(-2, -5, -9);

				COMPARE(-VMA.x, VMB.x);
				COMPARE(-VMA.y, VMB.y);
				COMPARE(-VMA.z, VMB.z);
			}

			TEST(Vec3_Operator_isEqual)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(2, 5, 9);
				Maths::Vec3 VMC(9, 5, 2);

				COMPARE(VMA == VMB, true);
				COMPARE(VMA == VMC, false);
			}

			TEST(Vec3_Operator_isNotEqual)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(2, 5, 9);
				Maths::Vec3 VMC(9, 5, 2);

				COMPARE(VMA != VMB, false);
				COMPARE(VMA != VMC, true);
			}

		}
		
		NAMESPACE(Vector3_Vec3_to_Vec3_operations)
		{

			TEST(Vec3_Operator_Plus_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				Maths::Vec3 VMC = VMA + VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				glm::vec3 VGC = VGA + VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
			}

			TEST(Vec3_Operator_Minus_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				Maths::Vec3 VMC = VMA - VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				glm::vec3 VGC = VGA - VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
			}

			TEST(Vec3_Operator_Multiply_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				Maths::Vec3 VMC = VMA * VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				glm::vec3 VGC = VGA * VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
			}

			TEST(Vec3_Operator_Divide_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				Maths::Vec3 VMC = VMA / VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				glm::vec3 VGC = VGA / VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
			}

		}

		NAMESPACE(Vector3_Vec3_to_This_operations)
		{

			TEST(Vec3_Operator_PlusEqual_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				VMA += VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				VGA += VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec3_Operator_MinusEqual_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				VMA -= VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				VGA -= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec3_Operator_MultiplyEqual_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				VMA *= VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				VGA *= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec3_Operator_DivideEqual_Vec)
			{
				Maths::Vec3 VMA(2, 5, 9);
				Maths::Vec3 VMB(9, 5, 2);

				VMA /= VMB;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(9, 5, 2);

				VGA /= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

		}

		NAMESPACE(Vector3_Scaler_to_Vec3_operations)
		{

			TEST(Vec3_Operator_Plus_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				Maths::Vec3 VMB = VMA + 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				glm::vec3 VGC = VGA + VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}

			TEST(Vec3_Operator_Minus_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				Maths::Vec3 VMB = VMA - 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				glm::vec3 VGC = VGA - VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}

			TEST(Vec3_Operator_Multiply_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				Maths::Vec3 VMB = VMA * 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				glm::vec3 VGC = VGA * VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}

			TEST(Vec3_Operator_Divide_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				Maths::Vec3 VMB = VMA / 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				glm::vec3 VGC = VGA / VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}

		}

		NAMESPACE(Vector3_Scaler_to_This_operations)
		{

			TEST(Vec3_Operator_PlusEqual_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				VMA += 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				VGA += VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec3_Operator_MinusEqual_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				VMA -= 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				VGA -= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec3_Operator_MultiplyEqual_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				VMA *= 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				VGA *= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec3_Operator_DivideEqual_Sca)
			{
				Maths::Vec3 VMA(2, 5, 9);

				VMA /= 3;

				glm::vec3 VGA(2, 5, 9);
				glm::vec3 VGB(3, 3, 3);

				VGA /= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

		}

	}

	NAMESPACE(Vector4)
	{

		NAMESPACE(Vector4_Constructor)
		{

			TEST(Vec4_Constructor_default)
			{
				Maths::Vec4 VM; glm::vec4 VG(0); // test default constructor

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
				COMPARE(VM.w, VG.w);
			}

			TEST(Vec4_Constructor_Scalar)
			{
				Maths::Vec4 VM(4); glm::vec4 VG(4); // test one scalar constructor

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
				COMPARE(VM.w, VG.w);
			}

			TEST(Vec4_Constructor_x_y_z_w)
			{
				Maths::Vec4 VM(1, 2, 3, 4); glm::vec4 VG(1, 2, 3, 4); // test constructor with x , y parameter

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
				COMPARE(VM.w, VG.w);
			}

			TEST(Vec4_Constructor_Vec2)
			{
				Maths::Vec2 TMP_1(3, 4);
				Maths::Vec4 VM(TMP_1);
				
				glm::vec4 VG(3, 4, 0, 0);

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
				COMPARE(VM.w, VG.w);
			}

			TEST(Vec4_Constructor_Vec3)
			{
				Maths::Vec3 TMP_1(6, 7, 8);
				Maths::Vec4 VM(TMP_1);
				
				glm::vec4 VG(6, 7, 8, 0); // test constructor from a Vec4

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
				COMPARE(VM.w, VG.w);
			}

			TEST(Vec4_Constructor_Vec3_w)
			{
				Maths::Vec3 TMP_1(6, 7, 8);
				Maths::Vec4 VM(TMP_1, 9);

				glm::vec4 VG(6, 7, 8, 9); // test constructor from a Vec4

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
				COMPARE(VM.w, VG.w);
			}

		}

		NAMESPACE(Vector4_Utils)
		{

			TEST(Vec4_xyz)
			{
				Maths::Vec4 VM1(1, 2, 3, 4);
				Maths::Vec3 VM2(1, 2, 3);

				COMPARE(VM1.xyz().x, VM2.x);
				COMPARE(VM1.xyz().y, VM2.y);
				COMPARE(VM1.xyz().z, VM2.z);
			}

			TEST(Vec4_xzw)
			{
				Maths::Vec4 VM1(1, 2, 3, 4);
				Maths::Vec3 VM2(1, 3, 4);

				COMPARE(VM1.xzw().x, VM2.x);
				COMPARE(VM1.xzw().y, VM2.y);
				COMPARE(VM1.xzw().z, VM2.z);
			}

			TEST(Vec4_xyw)
			{
				Maths::Vec4 VM1(1, 2, 3, 4);
				Maths::Vec3 VM2(1, 2, 4);

				COMPARE(VM1.xyw().x, VM2.x);
				COMPARE(VM1.xyw().y, VM2.y);
				COMPARE(VM1.xyw().z, VM2.z);
			}

			TEST(Vec4_yzw)
			{
				Maths::Vec4 VM1(1, 2, 3, 4);
				Maths::Vec3 VM2(2, 3, 4);

				COMPARE(VM1.yzw().x, VM2.x);
				COMPARE(VM1.yzw().y, VM2.y);
				COMPARE(VM1.yzw().z, VM2.z);
			}

			TEST(Vec4_GetMagnitude)
			{
				Maths::Vec4 VM(2, 5, 9, 11); glm::vec4 VG(2, 5, 9, 11);

				COMPARE(VM.GetMagnitude(), glm::length(VG));
			}

			TEST(Vec4_GetMagnitudeSquared)
			{
				Maths::Vec4 VM(2, 5, 9, 11); glm::vec4 VG(2, 5, 9, 11);

				COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
			}

			TEST(Vec4_Normalize)
			{
				Maths::Vec4 VM(2, 5, 9, 11); glm::vec4 VG(2, 5, 9, 11);

				VM.Normalize();
				// glm::vec4 tempG = glm::normalize(VG);
				float i = glm::length(VG);
				if (i != 0)
				{
					VG/=i;
				}

				COMPARE(VM.x, VG.x);
				COMPARE(VM.y, VG.y);
				COMPARE(VM.z, VG.z);
				COMPARE(VM.w, VG.w);
			}

			TEST(Vec4_GetNormalized)
			{
				Maths::Vec4 VM(2, 5, 9, 11); glm::vec4 VG(2, 5, 9, 11);

				Maths::Vec4 tempM = VM.GetNormalized();
				// glm::vec4 tempG = glm::normalize(VG);
				glm::vec4 tempG;

				float i = glm::length(VG);
				if (i != 0)
				{
					tempG = VG/i;
				}

				COMPARE(tempM.x, tempG.x);
				COMPARE(tempM.y, tempG.y);
				COMPARE(tempM.z, tempG.z);
				COMPARE(tempM.w, tempG.w);
			}

			TEST(Vec4_DotProduct)
			{
				Maths::Vec4 VMA(2, 5, 9, 11); 
				Maths::Vec4 VMB(11, 9, 5, 2);

				glm::vec4 VGA(2, 5, 9, 11);
				glm::vec4 VGB(11, 9, 5, 2);

				COMPARE(VMA.DotProduct(VMB), glm::dot(VGA, VGB));
			}

			TEST(Vec4_DotProduct_Static)
			{
				Maths::Vec4 VMA(2, 5, 9, 11);
				Maths::Vec4 VMB(11, 9, 5, 2);

				glm::vec4 VGA(2, 5, 9, 11);
				glm::vec4 VGB(11, 9, 5, 2);

				COMPARE(Maths::Vec4::DotProduct(VMA, VMB), glm::dot(VGA, VGB));
			}

			TEST(Vec4_Homogenize)
			{
				Maths::Vec4 VM(2, 5, 9, 11); glm::vec4 VG(2, 5, 9, 11);

				VM.Homogenize();
				glm::vec4 ResultG = VG / VG.w;

				COMPARE(VM.x, ResultG.x);
				COMPARE(VM.y, ResultG.y);
				COMPARE(VM.z, ResultG.z);
				COMPARE(VM.w, ResultG.w);
			}

			TEST(Vec4_GetHomogenized)
			{
				Maths::Vec4 VM(2, 5, 9, 11); glm::vec4 VG(2, 5, 9, 11);

				Maths::Vec4 ResultM = VM.GetHomogenized();
				glm::vec4 ResultG = VG / VG.w;

				COMPARE(ResultM.x, ResultG.x);
				COMPARE(ResultM.y, ResultG.y);
				COMPARE(ResultM.z, ResultG.z);
				COMPARE(ResultM.w, ResultG.w);
			}

		}

		NAMESPACE(Vector4_Assignment_and_Equality_operations)
		{

			TEST(Vec4_Operator_equal_Vec)
			{
				Maths::Vec4 VMA(2, 5, 3, 8);

				Maths::Vec4 VMB;

				VMB = VMA;

				COMPARE(VMA.x, VMB.x);
				COMPARE(VMA.y, VMB.y);
				COMPARE(VMA.z, VMB.z);
				COMPARE(VMA.w, VMB.w);
			}

			TEST(Vec4_Operator_equal_Sca)
			{
				Maths::Vec4 VMA;

				VMA = 8;

				COMPARE(VMA.x, 8);
				COMPARE(VMA.y, 8);
				COMPARE(VMA.z, 8);
				COMPARE(VMA.w, 8);
			}

			TEST(Vec4_Operator_negate)
			{
				Maths::Vec4 VMA(2, 5, 3, 8);

				COMPARE(-VMA.x, -2);
				COMPARE(-VMA.y, -5);
				COMPARE(-VMA.z, -3);
				COMPARE(-VMA.w, -8);
			}

			TEST(Vec4_Operator_isEqual)
			{
				Maths::Vec4 VMA(2, 5, 3, 4);
				Maths::Vec4 VMB(2, 5, 3, 4);
				Maths::Vec4 VMC(5, 2, 5, 7);

				COMPARE(VMA == VMB, true);
				COMPARE(VMA == VMC, false);
			}

			TEST(Vec4_Operator_isNotEqual)
			{
				Maths::Vec4 VMA(2, 5, 3, 4);
				Maths::Vec4 VMB(2, 5, 3, 4);
				Maths::Vec4 VMC(5, 2, 5, 7);

				COMPARE(VMA != VMB, false);
				COMPARE(VMA != VMC, true);
			}

		}

		NAMESPACE(Vector4_Vec4_to_Vec4_operations)
		{

			TEST(Vec4_Operator_Plus_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				Maths::Vec4 VMC = VMA + VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				glm::vec4 VGC = VGA + VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
				COMPARE(VMC.w, VGC.w);
			}

			TEST(Vec4_Operator_Minus_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				Maths::Vec4 VMC = VMA - VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				glm::vec4 VGC = VGA - VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
				COMPARE(VMC.w, VGC.w);
			}

			TEST(Vec4_Operator_Multiply_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				Maths::Vec4 VMC = VMA * VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				glm::vec4 VGC = VGA * VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
				COMPARE(VMC.w, VGC.w);
			}

			TEST(Vec4_Operator_Divide_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				Maths::Vec4 VMC = VMA / VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				glm::vec4 VGC = VGA / VGB;

				COMPARE(VMC.x, VGC.x);
				COMPARE(VMC.y, VGC.y);
				COMPARE(VMC.z, VGC.z);
				COMPARE(VMC.w, VGC.w);
			}

		}

		NAMESPACE(Vector4_Vec4_to_This_operations)
		{

			TEST(Vec4_Operator_PlusEqual_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				VMA += VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				VGA += VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
				COMPARE(VMA.w, VGA.w);
			}

			TEST(Vec4_Operator_MinusEqual_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				VMA -= VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				VGA -= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
				COMPARE(VMA.w, VGA.w);
			}

			TEST(Vec4_Operator_MultiplyEqual_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				VMA *= VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				VGA *= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
				COMPARE(VMA.w, VGA.w);
			}

			TEST(Vec4_Operator_DivideEqual_Vec)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);
				Maths::Vec4 VMB(9, 5, 2, 5);

				VMA /= VMB;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(9, 5, 2, 5);

				VGA /= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
				COMPARE(VMA.w, VGA.w);
			}

		}

		NAMESPACE(Vector4_Scaler_to_Vec4_operations)
		{

			TEST(Vec4_Operator_Plus_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				Maths::Vec4 VMB = VMA + 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				glm::vec4 VGC = VGA + VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}

			TEST(Vec4_Operator_Minus_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				Maths::Vec4 VMB = VMA - 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				glm::vec4 VGC = VGA - VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}

			TEST(Vec4_Operator_Multiply_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				Maths::Vec4 VMB = VMA * 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				glm::vec4 VGC = VGA * VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}

			TEST(Vec4_Operator_Divide_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				Maths::Vec4 VMB = VMA / 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				glm::vec4 VGC = VGA / VGB;

				COMPARE(VMB.x, VGC.x);
				COMPARE(VMB.y, VGC.y);
				COMPARE(VMB.z, VGC.z);
			}
		}

		NAMESPACE(Vector4_Scaler_to_This_operations)
		{

			TEST(Vec4_Operator_PlusEqual_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				VMA += 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				VGA += VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec4_Operator_MinusEqual_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				VMA -= 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				VGA -= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec4_Operator_MultiplyEqual_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				VMA *= 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				VGA *= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}

			TEST(Vec4_Operator_DivideEqual_Sca)
			{
				Maths::Vec4 VMA(2, 5, 9, 7);

				VMA /= 3;

				glm::vec4 VGA(2, 5, 9, 7);
				glm::vec4 VGB(3, 3, 3, 3);

				VGA /= VGB;

				COMPARE(VMA.x, VGA.x);
				COMPARE(VMA.y, VGA.y);
				COMPARE(VMA.z, VGA.z);
			}
		
		}

	}
}

int main()
{
	system("cls");
	std::cout << "Library used for the tests : glm\n";
	runTests();
	system("pause");
	return 0;
}