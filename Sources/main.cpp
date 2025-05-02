#include <iostream>
#include <algorithm>

#include "LibMath/Maths.hpp"
#include "LibMath/MathsStreams.hpp"

#include "glm/glm.hpp"
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VTest/VTest.hpp"

#define RAND_FLOAT static_cast <float> (rand())
//#define RAND_FLOAT  *((float*)(void*)(rand()))
#define RAND_DOUBLE static_cast <double> (rand())

VTEST(Maths)
{

    NAMESPACE(Maths_Constants)
    {
        NAMESPACE(PI_Float)
        {

            TEST(PI)
            {
                COMPARE(Maths::Constants::PI, glm::pi<float>());
            }
            
            TEST(TAU)
            {
                COMPARE(Maths::Constants::TAU, glm::two_pi<float>());
            }
            
            TEST(PI/2)
            {
                COMPARE(Maths::Constants::PI_2, glm::half_pi<float>());
            }
            
            TEST(PI/3)
            {
                COMPARE(Maths::Constants::PI_3, glm::pi<float>()/3);
            }
            
            TEST(PI/4)
            {
                COMPARE(Maths::Constants::PI_4, glm::quarter_pi<float>());
            }
            
            TEST(PI/6)
            {
                COMPARE(Maths::Constants::PI_6, glm::pi<float>()/6);
            }
            
            TEST(1/PI)
            {
                COMPARE(Maths::Constants::I_PI, glm::one_over_pi<float>());
            }
            
            TEST(1/TAU)
            {
                COMPARE(Maths::Constants::I_TAU, glm::one_over_two_pi<float>());
            }
        }
        NAMESPACE(PI_Double)
        {
            TEST(PI)
            {
                COMPARE(Maths::Constants::PI_PRECISE, glm::pi<double>());
            }
        }
    }
    NAMESPACE(Maths_Functions)
    {

        TEST(float_Angle_to_Radians)
        {
            float value = RAND_FLOAT;
            COMPARE(Maths::ToRadians(value), glm::radians(value));
        }

        TEST(double_Angle_to_Radians)
        {
            double value = RAND_DOUBLE;
            COMPARE(Maths::ToRadians(value), glm::radians(value));
        }

        TEST(float_Angle_to_Degrees)
        {
            float value = RAND_FLOAT;
            COMPARE(Maths::ToDegrees(value), glm::degrees(value));
        }

        TEST(double_Angle_to_Degrees)
        {
            float value = RAND_DOUBLE;
            COMPARE(Maths::ToRadians(value), glm::radians(value));
        }

    }

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
                float value = RAND_FLOAT;
                Maths::Vec2 VM(value); glm::vec2 VG(value); // test one scalar constructor

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(Vec2_Constructor_x_y)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]); // test constructor with x , y parameter

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(Vec2_Constructor_Vec3)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 TMP_1(value[0], value[1], value[2]); glm::vec3 TMP_2(value[0], value[1], value[2]);
                Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec3

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(Vec2_Constructor_Vec4)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec4 TMP_1(value[0], value[1], value[2], value[3]); glm::vec4 TMP_2(value[0], value[1], value[2], value[3]);
                Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec4

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }
        
        }

        NAMESPACE(Vector2_Utils)
        {

            TEST(Vec2_GetMagnitude)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);
                
                COMPARE(VM.GetMagnitude(), glm::length(VG));
            }

            TEST(Vec2_GetMagnitudeSquared)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);

                COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
            }

            TEST(Vec2_GetNormalized)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);

                Maths::Vec2 tempM = VM.GetNormalized();
                glm::vec2 tempG = glm::normalize(VG);

                COMPARE(tempM.x, tempG.x);
                COMPARE(tempM.y, tempG.y);
            }

            TEST(Vec2_GetPerpendicular)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);

                Maths::Vec2 tempM = VM.GetPerpendicular();
                glm::vec2 tempG(VG.y, -VG.x);
                
                COMPARE(tempM.x, tempG.x);
                COMPARE(tempM.y, tempG.y);
            }
        
        }

        NAMESPACE(Vector2_Assignment_and_Equality_operations)
        {

            TEST(Vec2_Operator=_Vec3)
            {
                Maths::Vec3 VMA(RAND_FLOAT, RAND_FLOAT, RAND_FLOAT);

                Maths::Vec2 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
            }

            TEST(Vec2_Operator=_Vec4)
            {
                Maths::Vec4 VMA(RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT);

                Maths::Vec2 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
            }

            TEST(Vec2_Operator=_Sca)
            {
                Maths::Vec2 VM;
                float value = RAND_FLOAT;

                VM = value;

                COMPARE(VM.x, value);
                COMPARE(VM.y, value);
            }

            TEST(Vec2_Operator_negate)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(-value[0], -value[1]);

                COMPARE((-VMA).x, VMB.x);
                COMPARE((-VMA).y, VMB.y);
            }

            TEST(Vec2_Operator==)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[0], value[1]);
                Maths::Vec2 VMC(RAND_FLOAT, RAND_FLOAT);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(Vec2_Operator!=)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[0], value[1]);
                Maths::Vec2 VMC(RAND_FLOAT, RAND_FLOAT);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

            TEST(Vec2_Operator[])
            {
                Maths::Vec2 VM(RAND_FLOAT, RAND_FLOAT);
                COMPARE(VM[0], VM.x);
                COMPARE(VM[1], VM.y);
            }
        }
        
        NAMESPACE(Vector2_Vec2_to_Vec2_operations)
        {

            TEST(Vec2_Operator+)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[2], value[3]);

                Maths::Vec2 VMC = VMA + VMB;

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[3]);

                glm::vec2 VGC = VGA + VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
            }

            TEST(Vec2_Operator-)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[2], value[3]);

                Maths::Vec2 VMC = VMA - VMB;

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[3]);

                glm::vec2 VGC = VGA - VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
            }

        }

        NAMESPACE(Vector2_Vec2_to_This_operations)
        {

            TEST(Vec2_Operator+=)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[2], value[3]);

                VMA += VMB;

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[3]);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(Vec2_Operator-=)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[2], value[3]);

                VMA -= VMB;

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[3]);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

        }

        NAMESPACE(Vector2_Scaler_to_Vec2_operations)
        {

            TEST(Vec2_Operator+)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT};

                Maths::Vec2 VMA(value[0], value[1]);

                Maths::Vec2 VMB = VMA + value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

                glm::vec2 VGC = VGA + VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

            TEST(Vec2_Operator-)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);

                Maths::Vec2 VMB = VMA - value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

                glm::vec2 VGC = VGA - VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

            TEST(Vec2_Operator*)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);

                Maths::Vec2 VMB = VMA * value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

                glm::vec2 VGC = VGA * VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

            TEST(Vec2_Operator/)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);

                Maths::Vec2 VMB = VMA / value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

                glm::vec2 VGC = VGA / VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

        }

        NAMESPACE(Vector2_Scaler_to_This_operations)
        {

            TEST(Vec2_Operator+=)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);

                VMA += value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(Vec2_Operator-=)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);

                VMA -= value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(Vec2_Operator*=)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);

                VMA *= value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(Vec2_Operator/=)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);

                VMA /= value[2];

                glm::vec2 VGA(value[0], value[1]);
                glm::vec2 VGB(value[2], value[2]);

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

            TEST(Vec3_GetNormalized)
            {
                Maths::Vec3 VM(2, 5, 9); glm::vec3 VG(2, 5, 9);

                Maths::Vec3 tempM = VM.GetNormalized();
                glm::vec3 tempG = glm::normalize(VG);

                COMPARE(tempM.x, tempG.x);
                COMPARE(tempM.y, tempG.y);
                COMPARE(tempM.z, tempG.z);
            }

        }

        NAMESPACE(Vector3_Assignment_and_Equality_operations)
        {

            TEST(Vec3_Operator=_Vec2)
            {
                Maths::Vec2 VMA(2, 5);

                Maths::Vec3 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(0, VMB.z);
            }

            TEST(Vec3_Operator=_Vec4)
            {
                Maths::Vec4 VMA(2, 5, 8, 11);

                Maths::Vec3 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(VMA.z, VMB.z);
            }

            TEST(Vec3_Operator=_Sca)
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

                COMPARE((-VMA).x, VMB.x);
                COMPARE((-VMA).y, VMB.y);
                COMPARE((-VMA).z, VMB.z);
            }

            TEST(Vec3_Operator==)
            {
                Maths::Vec3 VMA(2, 5, 9);
                Maths::Vec3 VMB(2, 5, 9);
                Maths::Vec3 VMC(9, 5, 2);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(Vec3_Operator!=)
            {
                Maths::Vec3 VMA(2, 5, 9);
                Maths::Vec3 VMB(2, 5, 9);
                Maths::Vec3 VMC(9, 5, 2);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

            TEST(Vec3_Operator[])
            {
                Maths::Vec3 VM(2, 5, 8);
                COMPARE(VM[0], VM.x);
                COMPARE(VM[1], VM.y);
                COMPARE(VM[2], VM.z);
            }

        }
        
        NAMESPACE(Vector3_Vec3_to_Vec3_operations)
        {

            TEST(Vec3_Operator+)
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

            TEST(Vec3_Operator-)
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

        }

        NAMESPACE(Vector3_Vec3_to_This_operations)
        {

            TEST(Vec3_Operator+=)
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

            TEST(Vec3_Operator-=)
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

        }

        NAMESPACE(Vector3_Scaler_to_Vec3_operations)
        {

            TEST(Vec3_Operator+)
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

            TEST(Vec3_Operator-)
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

            TEST(Vec3_Operator*)
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

            TEST(Vec3_Operator/)
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

            TEST(Vec3_Operator+=)
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

            TEST(Vec3_Operator-=)
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

            TEST(Vec3_Operator*=)
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

            TEST(Vec3_Operator/=)
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
                
                glm::vec4 VG(3, 4, 0, 1);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec4_Constructor_Vec2_z)
            {
                Maths::Vec2 TMP_1(3, 4);
                Maths::Vec4 VM(TMP_1, 5);
                
                glm::vec4 VG(3, 4, 5, 1);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec4_Constructor_Vec2_z_w)
            {
                Maths::Vec2 TMP_1(3, 4);
                Maths::Vec4 VM(TMP_1, 5, 6);
                
                glm::vec4 VG(3, 4, 5, 6);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec4_Constructor_Vec3)
            {
                Maths::Vec3 TMP_1(6, 7, 8);
                Maths::Vec4 VM(TMP_1);
                
                glm::vec4 VG(6, 7, 8, 1); // test constructor from a Vec4

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
                COMPARE_WITH_PRECISION(tempM.w, tempG.w, Maths::Constants::TOLERANCE);
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

            TEST(Vec4_Operator=_Vec2)
            {
                Maths::Vec2 VMA(2, 5);

                Maths::Vec4 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(0, VMB.z);
                COMPARE(1, VMB.w);
            }

            TEST(Vec4_Operator=_Vec3)
            {
                Maths::Vec3 VMA(2, 5, 3);

                Maths::Vec4 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(VMA.z, VMB.z);
                COMPARE(1, VMB.w);
            }

            TEST(Vec4_Operator=_Sca)
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

                COMPARE((-VMA).x, -2);
                COMPARE((-VMA).y, -5);
                COMPARE((-VMA).z, -3);
                COMPARE((-VMA).w, -8);
            }

            TEST(Vec4_Operator==)
            {
                Maths::Vec4 VMA(2, 5, 3, 4);
                Maths::Vec4 VMB(2, 5, 3, 4);
                Maths::Vec4 VMC(5, 2, 5, 7);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(Vec4_Operator!=)
            {
                Maths::Vec4 VMA(2, 5, 3, 4);
                Maths::Vec4 VMB(2, 5, 3, 4);
                Maths::Vec4 VMC(5, 2, 5, 7);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

            TEST(Vec4_Operator[])
            {
                Maths::Vec4 VM(2, 5, 8, 11);
                COMPARE(VM[0], VM.x);
                COMPARE(VM[1], VM.y);
                COMPARE(VM[2], VM.z);
                COMPARE(VM[3], VM.w);
            }

        }

        NAMESPACE(Vector4_Vec4_to_Vec4_operations)
        {

            TEST(Vec4_Operator+)
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

            TEST(Vec4_Operator-)
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

        }

        NAMESPACE(Vector4_Vec4_to_This_operations)
        {

            TEST(Vec4_Operator+=)
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

            TEST(Vec4_Operator-=)
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

        }

        NAMESPACE(Vector4_Scaler_to_Vec4_operations)
        {

            TEST(Vec4_Operator+)
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

            TEST(Vec4_Operator-)
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

            TEST(Vec4_Operator*)
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

            TEST(Vec4_Operator/)
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

            TEST(Vec4_Operator+=)
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

            TEST(Vec4_Operator-=)
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

            TEST(Vec4_Operator*=)
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

            TEST(Vec4_Operator/=)
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

    NAMESPACE(Vector_functions)
    {
        NAMESPACE(Normalize)
        {
            TEST(Vec2)
            {
                Maths::Vec2 MV(5,6); glm::vec2 GV(5,6);

                Maths::Vectors::Normalize(MV); GV = glm::normalize(GV);

                COMPARE(MV.x, GV.x);
                COMPARE(MV.x, GV.x);
            }

            TEST(Vec3)
            {
                Maths::Vec3 MV(5,6,12); glm::vec3 GV(5,6,12);

                Maths::Vectors::Normalize(MV); GV = glm::normalize(GV);

                COMPARE(MV.x, GV.x);
                COMPARE(MV.x, GV.x);
                COMPARE(MV.z, GV.z);
            }

            TEST(Vec4)
            {
                Maths::Vec4 MV(5,6,12,45); glm::vec4 GV(5,6,12,45);

                Maths::Vectors::Normalize(MV); GV = glm::normalize(GV);

                COMPARE(MV.x, GV.x);
                COMPARE(MV.x, GV.x);
                COMPARE(MV.z, GV.z);
                COMPARE(MV.w, GV.w);
            }
        }

        NAMESPACE(DotProduct)
        {
            TEST(Vec2)
            {
                Maths::Vec2 MVA(5, 6); Maths::Vec2 MVB(7, 8);
                glm::vec2 GVA(5, 6); glm::vec2 GVB(7, 8);

                COMPARE(Maths::Vectors::DotProduct(MVA, MVB), glm::dot(GVA, GVB));
            }

            TEST(Vec3)
            {
                Maths::Vec3 MVA(5,6,12); Maths::Vec3 MVB(7, 8, 13); 
                glm::vec3 GVA(5,6,12); glm::vec3 GVB(7, 8, 13);

                COMPARE(Maths::Vectors::DotProduct(MVA, MVB), glm::dot(GVA, GVB));
            }

            TEST(Vec4)
            {
                Maths::Vec4 MVA(5, 6, 12, 45); Maths::Vec4 MVB(7, 8, 13, 46); 
                glm::vec4 GVA(5, 6, 12, 45); glm::vec4 GVB(7, 8, 13, 46);

                COMPARE(Maths::Vectors::DotProduct(MVA, MVB), glm::dot(GVA, GVB));
            }
        }

        NAMESPACE(DistanceBetween)
        {
            TEST(Vec2)
            {
                Maths::Vec2 MVA(5, 6); Maths::Vec2 MVB(7, 8);
                glm::vec2 GVA(5, 6); glm::vec2 GVB(7, 8);

                COMPARE(Maths::Vectors::DistanceBetween(MVA, MVB), glm::distance(GVA, GVB));
            }

            TEST(Vec3)
            {
                Maths::Vec3 MVA(5,6,12); Maths::Vec3 MVB(7, 8, 13); 
                glm::vec3 GVA(5,6,12); glm::vec3 GVB(7, 8, 13);

                COMPARE(Maths::Vectors::DistanceBetween(MVA, MVB), glm::distance(GVA, GVB));
            }

            TEST(Vec4)
            {
                Maths::Vec4 MVA(5, 6, 12, 45); Maths::Vec4 MVB(7, 8, 13, 46); 
                glm::vec4 GVA(5, 6, 12, 45); glm::vec4 GVB(7, 8, 13, 46);

                COMPARE(Maths::Vectors::DistanceBetween(MVA, MVB), glm::distance(GVA, GVB));
            }
        }

        NAMESPACE(AngleBetween)
        {
            TEST(Vec2)
            {
                Maths::Vec2 MVA(5, 6); Maths::Vec2 MVB(7, 8);

                glm::vec2 GVA(5, 6); glm::vec2 GVB(7, 8);
                GVA = glm::normalize(GVA);
                GVB = glm::normalize(GVB);

                COMPARE(Maths::Vectors::AngleBetween(MVA, MVB), glm::orientedAngle(GVA, GVB));
                float a = Maths::Vectors::AngleBetween(MVA, MVB);
                float b = glm::angle(GVA, GVB);
            }

            TEST(Vec3)
            {
                Maths::Vec3 MVA(5,6,12); Maths::Vec3 MVB(7, 8, 13);

                glm::vec3 GVA(5,6,12); glm::vec3 GVB(7, 8, 13);
                GVA = glm::normalize(GVA);
                GVB = glm::normalize(GVB);
                glm::vec3 normal(0.0f, 0.0f, -1.0f);

                COMPARE_WITH_PRECISION(Maths::Vectors::AngleBetween(MVA, MVB), glm::orientedAngle(GVA, GVB, normal), 0.000001f);
                std::cout << "a normal variable added to work with glm" << std::endl;
            }

            TEST(Vec4)
            {
                Maths::Vec4 MVA(5, 6, 12, 45); Maths::Vec4 MVB(7, 8, 13, 46); 

                glm::vec4 GVA(5, 6, 12, 45); glm::vec4 GVB(7, 8, 13, 46);
                
                float anglebetweenGLM = acos(std::clamp(glm::dot(GVA, GVB) / ( glm::length(GVA) * glm::length(GVB)), -1.0f, 1.0f));

                COMPARE(Maths::Vectors::AngleBetween(MVA, MVB), anglebetweenGLM);
                std::cout << "since glm does not have an angle bewteen two vector 4 I implemented it using glm functions." <<std::endl;
            }
        }

        NAMESPACE(CrossProduct)
        {
            TEST(Vec2)
            {
                Maths::Vec2 MVA(5, 6); Maths::Vec2 MVB(7, 8);
                glm::vec2 GVA(5, 6); glm::vec2 GVB(7, 8);
                float crossForGLM = GVA.x * GVB.y - GVA.y * GVB.x;

                COMPARE(Maths::Vectors::CrossProduct(MVA, MVB), crossForGLM);
                std::cout << "glm does not have a cross for vec2 so i manually caculate here." <<std::endl;
            }

            TEST(Vec3)
            {
                Maths::Vec3 MVA(5,6,12); Maths::Vec3 MVB(7, 8, 13); 
                glm::vec3 GVA(5,6,12); glm::vec3 GVB(7, 8, 13);

                Maths::Vec3 resultM = Maths::Vectors::CrossProduct(MVA, MVB);
                glm::vec3 resultG = glm::cross(GVA, GVB);

                COMPARE(resultM.x, resultG.x);
                COMPARE(resultM.y, resultG.y);
                COMPARE(resultM.z, resultG.z);
            }
        }

        NAMESPACE(Rotate)
        {
            TEST(Vec3)
            {
                Maths::Vec3 MV(5,6,12); 
                glm::vec3 GV(5,6,12);

                float angle = 90.f;

                float x = 0.f;
                float y = 0.f;
                float z = 1.f;

                Maths::Vec3 resultM = Maths::Vectors::Rotate(MV, angle, Maths::Vec3(x,y,z));
                glm::vec3 resultG = glm::angleAxis(angle, glm::vec3(x,y,z)) * GV;

                COMPARE(resultM.x, resultG.x);
                COMPARE(resultM.y, resultG.y);
                COMPARE(resultM.z, resultG.z);
            }
        }
    }
/*
    NAMESPACE(IVector2)
    {

        NAMESPACE(IVector2_Constructor)
        {

            TEST(IVec2_Constructor_default)
            {
                Maths::IVec2 VM; glm::ivec2 VG(0);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(IVec2_Constructor_Scalar)
            {
                Maths::IVec2 VM(8); glm::ivec2 VG(8);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(IVec2_Constructor_x_y)
            {
                Maths::IVec2 VM(8,42); glm::ivec2 VG(8,42);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(IVec2_Constructor_Vec2)
            {
                Maths::Vec2 temp(8, 42);
                Maths::IVec2 VM(temp); glm::ivec2 VG(8,42);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

        }

        NAMESPACE(IVector2_Utils)
        {

            TEST(IVec2_GetMagnitude)
            {
                Maths::IVec2 VM(8, 42);
                glm::vec2 VG(8, 42); // use of vec2 insted of ivec2 due to length function
                
                COMPARE(VM.GetMagnitude(), glm::length(VG));
            }

            TEST(IVec2_GetMagnitudeSquared)
            {
                Maths::IVec2 VM(8, 42); 
                glm::vec2 VG(8, 42); // use of vec2 insted of ivec2 due to length2 function

                COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
            }

        }

        NAMESPACE(IVector2_Assignment_and_Equality_operations)
        {
            TEST(IVec2_Operator_equal_Vec)
            {
                Maths::IVec2 VMA(8, 42);

                Maths::IVec2 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
            }

            TEST(IVec2_Operator_equal_Sca)
            {
                Maths::IVec2 VM;

                VM = 1;

                COMPARE(VM.x, 1);
                COMPARE(VM.y, 1);
            }

            TEST(IVec2_Operator_negate)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(-8, -42);

                COMPARE(-VMA.x, VMB.x);
                COMPARE(-VMA.y, VMB.y);
            }

            TEST(IVec2_Operator_isEqual)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(8, 42);
                Maths::IVec2 VMC(42, 8);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(IVec2_Operator_isNotEqual)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(8, 42);
                Maths::IVec2 VMC(42, 8);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

        }

        NAMESPACE(IVector2_IVec2_to_IVec2_operations)
        {
            TEST(IVec2_Operator_Plus_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                Maths::IVec2 VMC = VMA + VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                glm::ivec2 VGC = VGA + VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
            }

            TEST(IVec2_Operator_Minus_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                Maths::IVec2 VMC = VMA - VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                glm::ivec2 VGC = VGA - VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
            }

            TEST(IVec2_Operator_Multiply_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                Maths::IVec2 VMC = VMA * VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                glm::ivec2 VGC = VGA * VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
            }

            TEST(IVec2_Operator_Divide_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                Maths::IVec2 VMC = VMA / VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                glm::ivec2 VGC = VGA / VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
            }

        }

        NAMESPACE(IVector2_IVec2_to_This_operations)
        {
            TEST(IVec2_Operator_PlusEqual_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                VMA += VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(IVec2_Operator_MinusEqual_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                VMA -= VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(IVec2_Operator_MultiplyEqual_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                VMA *= VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(IVec2_Operator_DivideEqual_Vec)
            {
                Maths::IVec2 VMA(8, 42);
                Maths::IVec2 VMB(42, 8);

                VMA /= VMB;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(42, 8);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

        }

        NAMESPACE(IVector2_Scaler_to_IVec2_operations)
        {
            TEST(IVec2_Operator_Plus_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                Maths::IVec2 VMB = VMA + 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                glm::ivec2 VGC = VGA + VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

            TEST(IVec2_Operator_Minus_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                Maths::IVec2 VMB = VMA - 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                glm::ivec2 VGC = VGA - VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

            TEST(IVec2_Operator_Multiply_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                Maths::IVec2 VMB = VMA * 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                glm::vec2 VGC = VGA * VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

            TEST(IVec2_Operator_Divide_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                Maths::IVec2 VMB = VMA / 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                glm::ivec2 VGC = VGA / VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
            }

        }

        NAMESPACE(IVector2_Scaler_to_This_operations)
        {
            TEST(IVec2_Operator_PlusEqual_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                VMA += 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(IVec2_Operator_MinusEqual_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                VMA -= 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(IVec2_Operator_MultiplyEqual_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                VMA *= 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

            TEST(IVec2_Operator_DivideEqual_Sca)
            {
                Maths::IVec2 VMA(8, 42);

                VMA /= 3;

                glm::ivec2 VGA(8, 42);
                glm::ivec2 VGB(3, 3);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
            }

        }

    }
    
    NAMESPACE(IVector3)
    {

        NAMESPACE(IVector3_Constructor)
        {

            TEST(IVec3_Constructor_default)
            {
                Maths::IVec3 VM; glm::ivec3 VG(0); // test default constructor

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(IVec3_Constructor_Scalar)
            {
                Maths::IVec3 VM(3); glm::ivec3 VG(3); // test one scalar constructor

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(IVec3_Constructor_x_y_z)
            {
                Maths::IVec3 VM(1, 2, 3); glm::ivec3 VG(1, 2, 3); // test constructor with x , y parameter

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(IVec3_Constructor_Vec3)
            {
                Maths::Vec3 temp(3, 4, 5);
                Maths::IVec3 VM(temp); glm::ivec3 VG(3, 4, 5);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

        }

        NAMESPACE(IVector3_Utils)
        {

            TEST(IVec3_GetMagnitude)
            {
                Maths::IVec3 VM(8, 42, 75);
                glm::vec3 VG(8, 42, 75); // use of vec3 insted of ivec3 due to length function

                COMPARE(VM.GetMagnitude(), glm::length(VG));
            }

            TEST(IVec3_GetMagnitudeSquared)
            {
                Maths::IVec3 VM(8, 42, 75);
                glm::vec3 VG(8, 42, 75); // use of vec3 insted of ivec3 due to length2 function

                COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
            }

        }

        NAMESPACE(IVector3_Assignment_and_Equality_operations)
        {

            TEST(IVec3_Operator_equal_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);

                Maths::IVec3 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(VMA.z, VMB.z);
            }

            TEST(IVec3_Operator_equal_Sca)
            {
                Maths::IVec3 VM;

                VM = 1;

                COMPARE(VM.x, 1);
                COMPARE(VM.y, 1);
                COMPARE(VM.z, 1);
            }

            TEST(IVec3_Operator_negate)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(-2, -5, -9);

                COMPARE(-VMA.x, VMB.x);
                COMPARE(-VMA.y, VMB.y);
                COMPARE(-VMA.z, VMB.z);
            }

            TEST(IVec3_Operator_isEqual)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(2, 5, 9);
                Maths::IVec3 VMC(9, 5, 2);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(IVec3_Operator_isNotEqual)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(2, 5, 9);
                Maths::IVec3 VMC(9, 5, 2);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

        }

        NAMESPACE(IVector3_IVec3_to_IVec3_operations)
        {

            TEST(IVec3_Operator_Plus_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                Maths::IVec3 VMC = VMA + VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                glm::ivec3 VGC = VGA + VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
            }

            TEST(IVec3_Operator_Minus_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                Maths::IVec3 VMC = VMA - VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                glm::ivec3 VGC = VGA - VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
            }

            TEST(IVec3_Operator_Multiply_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                Maths::IVec3 VMC = VMA * VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                glm::ivec3 VGC = VGA * VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
            }

            TEST(IVec3_Operator_Divide_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                Maths::IVec3 VMC = VMA / VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                glm::ivec3 VGC = VGA / VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
            }

        }

        NAMESPACE(IVector3_IVec3_to_This_operations)
        {

            TEST(IVec3_Operator_PlusEqual_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                VMA += VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec3_Operator_MinusEqual_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                VMA -= VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec3_Operator_MultiplyEqual_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                VMA *= VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec3_Operator_DivideEqual_Vec)
            {
                Maths::IVec3 VMA(2, 5, 9);
                Maths::IVec3 VMB(9, 5, 2);

                VMA /= VMB;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(9, 5, 2);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

        }

        NAMESPACE(IVector3_Scaler_to_IVec3_operations)
        {

            TEST(IVec3_Operator_Plus_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                Maths::IVec3 VMB = VMA + 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                glm::ivec3 VGC = VGA + VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(IVec3_Operator_Minus_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                Maths::IVec3 VMB = VMA - 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                glm::ivec3 VGC = VGA - VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Vec3_Operator_Multiply_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                Maths::IVec3 VMB = VMA * 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                glm::ivec3 VGC = VGA * VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Vec3_Operator_Divide_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                Maths::IVec3 VMB = VMA / 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                glm::ivec3 VGC = VGA / VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

        }

        NAMESPACE(IVector3_Scaler_to_This_operations)
        {

            TEST(IVec3_Operator_PlusEqual_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                VMA += 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec3_Operator_MinusEqual_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                VMA -= 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec3_Operator_MultiplyEqual_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                VMA *= 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Vec3_Operator_DivideEqual_Sca)
            {
                Maths::IVec3 VMA(2, 5, 9);

                VMA /= 3;

                glm::ivec3 VGA(2, 5, 9);
                glm::ivec3 VGB(3, 3, 3);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

        }

    }

    NAMESPACE(IVector4)
    {

        NAMESPACE(IVector4_Constructor)
        {
            TEST(IVec4_Constructor_default)
            {
                Maths::IVec4 VM; glm::ivec4 VG(0); // test default constructor

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(IVec4_Constructor_Scalar)
            {
                Maths::IVec4 VM(4); glm::ivec4 VG(4); // test one scalar constructor

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(IVec4_Constructor_x_y_z_w)
            {
                Maths::IVec4 VM(1, 2, 3, 4); glm::ivec4 VG(1, 2, 3, 4); // test constructor with x , y parameter

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(IVec4_Constructor_Vec4)
            {
                Maths::Vec4 temp(3, 4, 8, 9);
                Maths::IVec4 VM(temp);

                glm::vec4 VG(3, 4, 8, 9);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

        }

        NAMESPACE(IVector4_Utils)
        {

            TEST(IVec4_GetMagnitude)
            {
                Maths::IVec4 VM(2, 5, 9, 11);
                glm::vec4 VG(2, 5, 9, 11);// use of vec4 insted of ivec4 due to length function

                COMPARE(VM.GetMagnitude(), glm::length(VG));
            }

            TEST(IVec4_GetMagnitudeSquared)
            {
                Maths::IVec4 VM(2, 5, 9, 11);
                glm::vec4 VG(2, 5, 9, 11);// use of vec4 insted of ivec4 due to length function

                COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
            }

        }

        NAMESPACE(IVector4_Assignment_and_Equality_operations)
        {
            TEST(IVec4_Operator_equal_Vec)
            {
                Maths::IVec4 VMA(2, 5, 3, 8);

                Maths::IVec4 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(VMA.z, VMB.z);
                COMPARE(VMA.w, VMB.w);
            }

            TEST(IVec4_Operator_equal_Sca)
            {
                Maths::IVec4 VMA;

                VMA = 8;

                COMPARE(VMA.x, 8);
                COMPARE(VMA.y, 8);
                COMPARE(VMA.z, 8);
                COMPARE(VMA.w, 8);
            }

            TEST(IVec4_Operator_negate)
            {
                Maths::IVec4 VMA(2, 5, 3, 8);

                COMPARE(-VMA.x, -2);
                COMPARE(-VMA.y, -5);
                COMPARE(-VMA.z, -3);
                COMPARE(-VMA.w, -8);
            }

            TEST(IVec4_Operator_isEqual)
            {
                Maths::IVec4 VMA(2, 5, 3, 4);
                Maths::IVec4 VMB(2, 5, 3, 4);
                Maths::IVec4 VMC(5, 2, 5, 7);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(IVec4_Operator_isNotEqual)
            {
                Maths::IVec4 VMA(2, 5, 3, 4);
                Maths::IVec4 VMB(2, 5, 3, 4);
                Maths::IVec4 VMC(5, 2, 5, 7);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

        }

        NAMESPACE(IVector4_IVec4_to_IVec4_operations)
        {

            TEST(IVec4_Operator_Plus_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                Maths::IVec4 VMC = VMA + VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                glm::ivec4 VGC = VGA + VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
                COMPARE(VMC.w, VGC.w);
            }

            TEST(IVec4_Operator_Minus_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                Maths::IVec4 VMC = VMA - VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                glm::ivec4 VGC = VGA - VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
                COMPARE(VMC.w, VGC.w);
            }

            TEST(IVec4_Operator_Multiply_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                Maths::IVec4 VMC = VMA * VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                glm::ivec4 VGC = VGA * VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
                COMPARE(VMC.w, VGC.w);
            }

            TEST(IVec4_Operator_Divide_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                Maths::IVec4 VMC = VMA / VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                glm::ivec4 VGC = VGA / VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
                COMPARE(VMC.w, VGC.w);
            }

        }

        NAMESPACE(IVector4_IVec4_to_This_operations)
        {

            TEST(IVec4_Operator_PlusEqual_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                VMA += VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
                COMPARE(VMA.w, VGA.w);
            }

            TEST(IVec4_Operator_MinusEqual_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                VMA -= VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
                COMPARE(VMA.w, VGA.w);
            }

            TEST(IVec4_Operator_MultiplyEqual_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                VMA *= VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
                COMPARE(VMA.w, VGA.w);
            }

            TEST(IVec4_Operator_DivideEqual_Vec)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);
                Maths::IVec4 VMB(9, 5, 2, 5);

                VMA /= VMB;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(9, 5, 2, 5);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
                COMPARE(VMA.w, VGA.w);
            }

        }

        NAMESPACE(IVector4_Scaler_to_IVec4_operations)
        {

            TEST(IVec4_Operator_Plus_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                Maths::IVec4 VMB = VMA + 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                glm::ivec4 VGC = VGA + VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(IVec4_Operator_Minus_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                Maths::IVec4 VMB = VMA - 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                glm::ivec4 VGC = VGA - VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(IVec4_Operator_Multiply_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                Maths::IVec4 VMB = VMA * 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                glm::ivec4 VGC = VGA * VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(IVec4_Operator_Divide_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                Maths::IVec4 VMB = VMA / 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                glm::ivec4 VGC = VGA / VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

        }

        NAMESPACE(IVector4_Scaler_to_This_operations)
        {

            TEST(IVec4_Operator_PlusEqual_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                VMA += 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec4_Operator_MinusEqual_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                VMA -= 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec4_Operator_MultiplyEqual_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                VMA *= 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(IVec4_Operator_DivideEqual_Sca)
            {
                Maths::IVec4 VMA(2, 5, 9, 7);

                VMA /= 3;

                glm::ivec4 VGA(2, 5, 9, 7);
                glm::ivec4 VGB(3, 3, 3, 3);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

        }

    }
*/
    NAMESPACE(Matrix_3x3)
    {

        NAMESPACE(Constructor)
        {

            TEST(default)
            {
                Maths::Mat3 MM; glm::mat3 MG(0);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }

            }

            TEST(data)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }

            }

            TEST(from an indentity value)
            {
                Maths::Mat3 MM(1);

                glm::mat3 MG(1);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(separate value)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                Maths::Mat3 MM(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }
        
            TEST(from a matrix 4x4)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                Maths::Mat4 MTemp(data[0], data[1], data[2], 1,
                                  data[3], data[4], data[5], 1,
                                  data[6], data[7], data[8], 1,
                                  1,       1,       1,       1);

                Maths::Mat3 MM(MTemp);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }
        }
        
        NAMESPACE(Utils)
        {
            TEST(Rotate2D)
            {

                Maths::Mat3 MM = Maths::Mat3::Rotate2D(80.f);

                glm::mat4 MG = glm::rotate(80.f, glm::vec3(0, 0, 1));

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE_WITH_PRECISION(MM[i][j], MG[i][j], 0.0000001);
                    }
                }
            }

            TEST(Translate2D)
            {

                Maths::Mat3 MM = Maths::Mat3::Translate2D(Maths::Vec2(85.f, 963.f));

                glm::mat4 MG = glm::translate(glm::vec3(85.f, 963.f, 0.f));

                COMPARE(MM[2][0], MG[3][0]);
                COMPARE(MM[2][1], MG[3][1]);

            }

            TEST(Scale2D)
            {

                Maths::Mat3 MM = Maths::Mat3::Scale2D(Maths::Vec2(3.f, 3.f));

                glm::mat4 MG = glm::scale(glm::vec3(3.f, 3.f, 1.f));

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM.data_3_3[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Transform)
            {
                Maths::Mat3 MM = Maths::Mat3::Transform(Maths::Vec2(50.f, 734.f), 85.f, Maths::Vec2(5.f, 4.f));

                glm::mat4 MG = glm::identity<glm::mat4>();
                MG[2][0] = 50.f;
                MG[2][1] = 734.f;
                MG *= glm::rotate(85.f, glm::vec3(0.f, 0.f, 1.f)) * glm::scale(glm::vec3(5.f, 4.f, 1.f));

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM.data_3_3[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Transpose)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM = MM.Transpose();
                MG = glm::transpose(MG);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Inverse)
            {
                float data[9] =
                {
                    0,1,2,
                    3,415,5,
                    6,7,8
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM.Inverse();
                MG = glm::inverse(MG);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(GetDeterminant)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                COMPARE(MM.GetDeterminant(), glm::determinant(MG));
            }
   
            TEST(GetTrace)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                COMPARE(MM.GetTrace(), (MG[0][0]+MG[1][1]+MG[2][2]));
                std::cout << "no glm equivalent!";
            }

        }
        
        NAMESPACE(Assignment and Equality operators)
        {

            TEST(operator = on data)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };


                Maths::Mat3 MM;
                MM = data;

                for (int i = 0; i < 9; i++)
                {
                    COMPARE(MM.data[i], data[i]);
                }
            }

            TEST(operator = on Mat4)
            {
                float data[16] =
                {
                    0, 1, 2, 1,
                    3, 4, 5, 1,
                    6, 7, 8, 1,
                    1, 1, 1, 1
                };

                Maths::Mat4 M4(data);

                Maths::Mat3 MM;
                MM = M4;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], M4[i][j]);
                    }
                }
            }

            TEST(operator negate)
            {
                float data[9] =
                {
                    0, 1, 2,
                    3, 4, 5,
                    6, 7, 8
                };

                glm::mat3 GM(data[0], data[1], data[2],
                             data[3], data[4], data[5],
                             data[6], data[7], data[8]);

                Maths::Mat3 MM(data);
                
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE((-MM)[i][j], (-GM)[i][j]);
                    }
                }
            }

            TEST(operator ==)
            {
                float data[9] =
                {
                    0, 1, 2,
                    3, 4, 5,
                    6, 7, 8
                };

                float data2[9] =
                {
                    8, 1, 2,
                    3, 4, 5,
                    6, 7, 0
                };

                Maths::Mat3 MM_A(data);
                Maths::Mat3 MM_B(data);
                Maths::Mat3 MM_C(data2);

                COMPARE(MM_A == MM_B, true);
                COMPARE(MM_A == MM_C, false);

            }

            TEST(operator !=)
            {
                float data[9] =
                {
                    0, 1, 2,
                    3, 4, 5,
                    6, 7, 8
                };

                float data2[9] =
                {
                    8, 1, 2,
                    3, 4, 5,
                    6, 7, 0
                };

                Maths::Mat3 MM_A(data);
                Maths::Mat3 MM_B(data);
                Maths::Mat3 MM_C(data2);

                COMPARE(MM_A != MM_B, false);
                COMPARE(MM_A != MM_C, true);

            }

            TEST(operator [])
            {
                Maths::Vec3 data[3] =
                {
                    {0, 1, 2},
                    {3, 4, 5},
                    {6, 7, 8}
                };

                Maths::Mat3 MM(data[0][0], data[0][1], data[0][2],
                               data[1][0], data[1][1], data[1][2],
                               data[2][0], data[2][1], data[2][2]);

                for (int i = 0; i < 3; i++)
                {
                    COMPARE(MM[i].x, data[i].x);
                    COMPARE(MM[i].y, data[i].y);
                    COMPARE(MM[i].z, data[i].z);
                }
            }
        }

        NAMESPACE(Mat3 to Mat3 operators)
        {

            TEST(operator +)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };
                float data2[9] =
                {
                    85,63,0,
                    4,7,52,
                    12,35,47
                };

                Maths::Mat3 MM1(data);
                Maths::Mat3 MM2(data2);

                glm::mat3 MG1(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                glm::mat3 MG2(data2[0], data2[1], data2[2],
                    data2[3], data2[4], data2[5],
                    data2[6], data2[7], data2[8]);

                Maths::Mat3 MM3 = MM1 + MM2;
                glm::mat3 MG3 = MG1 + MG2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM3.data_3_3[i][j], MG3[i][j]);
                    }
                }

            }

            TEST(operator -)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };
                float data2[9] =
                {
                    85,63,0,
                    4,7,52,
                    12,35,47
                };

                Maths::Mat3 MM1(data);
                Maths::Mat3 MM2(data2);

                glm::mat3 MG1(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                glm::mat3 MG2(data2[0], data2[1], data2[2],
                    data2[3], data2[4], data2[5],
                    data2[6], data2[7], data2[8]);

                Maths::Mat3 MM3 = MM1 - MM2;
                glm::mat3 MG3 = MG1 - MG2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM3.data_3_3[i][j], MG3[i][j]);
                    }
                }
            }

            TEST(operator *)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };
                float data2[9] =
                {
                    85,63,0,
                    4,7,52,
                    12,35,47
                };

                Maths::Mat3 MM1(data);
                Maths::Mat3 MM2(data2);

                glm::mat3 MG1(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                glm::mat3 MG2(data2[0], data2[1], data2[2],
                    data2[3], data2[4], data2[5],
                    data2[6], data2[7], data2[8]);

                Maths::Mat3 MM3 = MM1 * MM2;
                glm::mat3 MG3 = MG1 * MG2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM3.data_3_3[i][j], MG3[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Mat3 to this operators)
        {

            TEST(operator +=)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };
                float data2[9] =
                {
                    85,63,0,
                    4,7,52,
                    12,35,47
                };

                Maths::Mat3 MM1(data);
                Maths::Mat3 MM2(data2);

                glm::mat3 MG1(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                glm::mat3 MG2(data2[0], data2[1], data2[2],
                    data2[3], data2[4], data2[5],
                    data2[6], data2[7], data2[8]);

                MM1 += MM2;
                MG1 += MG2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM1.data_3_3[i][j], MG1[i][j]);
                    }
                }

            }

            TEST(operator -=)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };
                float data2[9] =
                {
                    85,63,0,
                    4,7,52,
                    12,35,47
                };

                Maths::Mat3 MM1(data);
                Maths::Mat3 MM2(data2);

                glm::mat3 MG1(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                glm::mat3 MG2(data2[0], data2[1], data2[2],
                    data2[3], data2[4], data2[5],
                    data2[6], data2[7], data2[8]);

                MM1 -= MM2;
                MG1 -= MG2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM1.data_3_3[i][j], MG1[i][j]);
                    }
                }
            }

            TEST(operator *=)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };
                float data2[9] =
                {
                    85,63,0,
                    4,7,52,
                    12,35,47
                };

                Maths::Mat3 MM1(data);
                Maths::Mat3 MM2(data2);

                glm::mat3 MG1(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                glm::mat3 MG2(data2[0], data2[1], data2[2],
                    data2[3], data2[4], data2[5],
                    data2[6], data2[7], data2[8]);

                MM1 *= MM2;
                MG1 *= MG2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM1.data_3_3[i][j], MG1[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Scalar to Mat3 operators)
        {

            TEST(operator *)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);


                Maths::Mat3 MM2 = MM * 2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM2[i][j], MG[i][j]*2);
                    }
                }
            }

            TEST(operator /)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);


                Maths::Mat3 MM2 = MM / 2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM2[i][j], MG[i][j] / 2);
                    }
                }
            }

        }

        NAMESPACE(Scalar to this operators)
        {

            TEST(operator *=)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM *= 2;
                MG *= 2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(operator /=)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM /= 2;
                MG /= 2;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Mat3 to Vec2 operators)
        {
            TEST(operator *)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                float data2[2] = { 8, 16 };

                Maths::Mat3 MM(data);
                Maths::Vec2 MV(data2[0],data2[1]);

                glm::mat3 GM(data[0], data[1], data[2],
                             data[3], data[4], data[5],
                             data[6], data[7], data[8]);
                glm::vec3 GV(data2[0], data2[1], 1.0f);//vec2 extended to a vec3 due to lack of operator.

                Maths::Vec2 MR = MM * MV;
                glm::vec2 GR = GV * GM;

                COMPARE(MR.x, GR.x);
                COMPARE(MR.y, GR.y);
            }
        }

        NAMESPACE(Mat3 to Vec3 operators)
        {
            TEST(operator *)
            {
                float data[9] =
                {
                    0,1,2,
                    3,4,5,
                    6,7,8
                };

                float data2[3] = { 8, 16, 32 };

                Maths::Mat3 MM(data);
                Maths::Vec3 MV(data2[0], data2[1], data2[2]);

                glm::mat3 GM(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);
                glm::vec3 GV(data2[0], data2[1], data2[2]);//vec2 extended to a vec3 due to lack of operator.

                Maths::Vec3 MR = MM * MV;
                glm::vec3 GR = GV * GM;

                COMPARE(MR.x, GR.x);
                COMPARE(MR.y, GR.y);
                COMPARE(MR.z, GR.z);
            }
        }
    }
/*
    NAMESPACE(Matrix_4x4)
    {

        NAMESPACE(Matrix_4x4_Constructor)
        {

            TEST(Mat4_Constructor_default)
            {
                Maths::Mat4 MM; glm::mat4 MG(0);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }

            }

            TEST(Mat4_Constructor_data)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };


                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }

            }

        }

        NAMESPACE(Matrix_4x4_Utils)
        {

            TEST(Mat4_Transpose)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };


                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                MM.Transpose();
                MG = glm::transpose(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Mat4_GetTranspose)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };


                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                Maths::Mat4 MM2 = Maths::Mat4::GetTranspose(MM);
                glm::mat4 MG2 = glm::transpose(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM2.data_4_4[i][j], MG2[i][j]);
                    }
                }
            }

            TEST(Mat4_Determinant)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };


                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                COMPARE(MM.Determinant(), glm::determinant(MG));
            }

            TEST(Mat4_Inverse)
            {
                float data[16] =
                {
                    52,  1, 45, 12,
                    68, 85, 89, 77,
                    55, 41, 10, 81,
                    12,  3, 14,  5
                };

                float data[16] =
                {
                    73, 22, 58, 91,
                    86, 47, 33, 65,
                    20, 74, 17, 39,
                    29, 11, 42, 8
                };


                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                MM.Inverse();

                MG = glm::inverse(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM.data_4_4[i][j], MG[i][j], 0.0000001);
                    }
                }
            }

            TEST(Mat4_GetInverse)
            {
                float data[16] =
                {
                    73, 22, 58, 91,
                    86, 47, 33, 65,
                    20, 74, 17, 39,
                    29, 11, 42, 8
                };


                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                Maths::Mat4 MM2 = Maths::Mat4::GetInverse(MM);
                glm::mat4 MG2 = glm::inverse(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM2.data_4_4[i][j], MG2[i][j], 0.0000001);
                    }
                }
            }
            
            TEST(Mat4_Trace)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };


                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                COMPARE(MM.Trace(), (MG[0][0] + MG[1][1] + MG[2][2] + MG[3][3]));
            }

            TEST(Mat4_CreateIdentityMatrix)
            {

                Maths::Mat4 MM = Maths::Mat4::CreateIdentityMatrix();

                glm::mat4 MG = glm::identity<glm::mat4>();

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Mat4_CreateXRotationMatrix)
            {

                Maths::Mat4 MM = Maths::Mat4::CreateXRotationMatrix(80.f);

                glm::mat4 MG = glm::rotate(80.f, glm::vec3(1, 0, 0));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM.data_4_4[i][j], MG[i][j], 0.0000001);
                    }
                }
            }

            TEST(Mat4_CreateYRotationMatrix)
            {

                Maths::Mat4 MM = Maths::Mat4::CreateYRotationMatrix(80.f);

                glm::mat4 MG = glm::rotate(80.f, glm::vec3(0, 1, 0));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM.data_4_4[i][j], MG[i][j], 0.0000001);
                    }
                }
            }

            TEST(Mat4_CreateZRotationMatrix)
            {

                Maths::Mat4 MM = Maths::Mat4::CreateZRotationMatrix(80.f);

                glm::mat4 MG = glm::rotate(80.f, glm::vec3(0, 0, 1));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM.data_4_4[i][j], MG[i][j], 0.0000001);
                    }
                }
            }

            TEST(Mat4_CreateRotationMatrix)
            {

                Maths::Mat4 MM = Maths::Mat4::CreateRotationMatrix(Maths::Vec3(30,50,80));

                glm::mat4 MG = glm::rotate(30.f, glm::vec3(1, 0, 0)) * glm::rotate(50.f, glm::vec3(0, 1, 0)) * glm::rotate(80.f, glm::vec3(0, 0, 1));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM.data_4_4[i][j], MG[i][j], 0.0000001);
                    }
                }
            }

            TEST(Mat4_CreateTranslationMatrix)
            {

                Maths::Mat4 MM = Maths::Mat4::CreateTranslationMatrix(Maths::Vec3(85.f, 963.f, 74.f));

                glm::mat4 MG = glm::translate(glm::vec3(85.f, 963.f, 74.f));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j], 0.0000001);
                    }
                }
            }

            TEST(Mat4_CreateScaleMatrix)
            {

                Maths::Mat4 MM = Maths::Mat4::CreateScaleMatrix(Maths::Vec3(3.f, 3.f, 3.f));

                glm::mat4 MG = glm::scale(glm::vec3(3.f, 3.f, 3.f));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Mat4_CreateTransformMatrix)
            {
                Maths::Mat4 MM = Maths::Mat4::CreateTransformMatrix(Maths::Vec3(85.f, 963.f, 74.f), Maths::Vec3(85.f, 74.f, 96.f), Maths::Vec3(5.f, 4.f, 87.f));

                glm::mat4 MG = glm::translate(glm::vec3(85.f, 963.f, 74.f));
                MG *= glm::rotate(85.f, glm::vec3(1, 0, 0)) * glm::rotate(74.f, glm::vec3(0, 1, 0)) * glm::rotate(96.f, glm::vec3(0, 0, 1));
                MG *= glm::scale(glm::vec3(5.f, 4.f, 87.f));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Matrix_4x4_Assignment_and_Equality_operations)
        {

            TEST(Mat4_Operator_equal_data)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };


                Maths::Mat4 MM;
                MM = data;

                for (int i = 0; i < 16; i++)
                {
                    COMPARE(MM.data[i], data[i]);
                }
            }

        }

        NAMESPACE(Matrix_4x4_Mat3_to_Mat3_operations)
        {

            TEST(Mat4_Operator_Plus_Mat)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };
                float data2[16] =
                {
                    52,  1, 45, 12,
                    68, 85, 89, 77,
                    55, 41, 10, 81,
                    12,  3, 14,  5
                };

                Maths::Mat4 MM1(data);
                Maths::Mat4 MM2(data2);

                glm::mat4 MG1(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                glm::mat4 MG2(data2[0], data2[1], data2[2], data2[3],
                    data2[4], data2[5], data2[6], data2[7],
                    data2[8], data2[9], data2[10], data2[11],
                    data2[12], data2[13], data2[14], data2[15]);

                Maths::Mat4 MM3 = MM1 + MM2;
                glm::mat4 MG3 = MG1 + MG2;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM3.data_4_4[i][j], MG3[i][j]);
                    }
                }

            }

            TEST(Mat4_Operator_Minus_Mat)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };
                float data2[16] =
                {
                    52,  1, 45, 12,
                    68, 85, 89, 77,
                    55, 41, 10, 81,
                    12,  3, 14,  5
                };

                Maths::Mat4 MM1(data);
                Maths::Mat4 MM2(data2);

                glm::mat4 MG1(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                glm::mat4 MG2(data2[0], data2[1], data2[2], data2[3],
                    data2[4], data2[5], data2[6], data2[7],
                    data2[8], data2[9], data2[10], data2[11],
                    data2[12], data2[13], data2[14], data2[15]);

                Maths::Mat4 MM3 = MM1 - MM2;
                glm::mat4 MG3 = MG1 - MG2;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM3.data_4_4[i][j], MG3[i][j]);
                    }
                }
            }

            TEST(Mat4_Operator_Multiply_Mat)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };
                float data2[16] =
                {
                    52,  1, 45, 12,
                    68, 85, 89, 77,
                    55, 41, 10, 81,
                    12,  3, 14,  5
                };

                Maths::Mat4 MM1(data);
                Maths::Mat4 MM2(data2);

                glm::mat4 MG1(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                glm::mat4 MG2(data2[0], data2[1], data2[2], data2[3],
                    data2[4], data2[5], data2[6], data2[7],
                    data2[8], data2[9], data2[10], data2[11],
                    data2[12], data2[13], data2[14], data2[15]);

                Maths::Mat4 MM3 = MM1 * MM2;
                glm::mat4 MG3 = MG1 * MG2;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM3.data_4_4[i][j], MG3[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Matrix_4x4_Mat3_to_This_operations)
        {

            TEST(Mat4_Operator_PlusEqual_Mat)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };
                float data2[16] =
                {
                    52,  1, 45, 12,
                    68, 85, 89, 77,
                    55, 41, 10, 81,
                    12,  3, 14,  5
                };

                Maths::Mat4 MM1(data);
                Maths::Mat4 MM2(data2);

                glm::mat4 MG1(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                glm::mat4 MG2(data2[0], data2[1], data2[2], data2[3],
                    data2[4], data2[5], data2[6], data2[7],
                    data2[8], data2[9], data2[10], data2[11],
                    data2[12], data2[13], data2[14], data2[15]);

                MM1 += MM2;
                MG1 += MG2;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM1.data_4_4[i][j], MG1[i][j]);
                    }
                }

            }

            TEST(Mat4_Operator_MinusEqual_Mat)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };
                float data2[16] =
                {
                    52,  1, 45, 12,
                    68, 85, 89, 77,
                    55, 41, 10, 81,
                    12,  3, 14,  5
                };

                Maths::Mat4 MM1(data);
                Maths::Mat4 MM2(data2);

                glm::mat4 MG1(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                glm::mat4 MG2(data2[0], data2[1], data2[2], data2[3],
                    data2[4], data2[5], data2[6], data2[7],
                    data2[8], data2[9], data2[10], data2[11],
                    data2[12], data2[13], data2[14], data2[15]);

                MM1 -= MM2;
                MG1 -= MG2;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM1.data_4_4[i][j], MG1[i][j]);
                    }
                }
            }

            TEST(Mat4_Operator_MultiplyEqual_Mat)
            {
                float data[16] =
                {
                     0,  1,  2,  3,
                     4,  5,  6,  7,
                     8,  9, 10, 11,
                    12, 13, 14, 15
                };
                float data2[16] =
                {
                    52,  1, 45, 12,
                    68, 85, 89, 77,
                    55, 41, 10, 81,
                    12,  3, 14,  5
                };

                Maths::Mat4 MM1(data);
                Maths::Mat4 MM2(data2);

                glm::mat4 MG1(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                glm::mat4 MG2(data2[0], data2[1], data2[2], data2[3],
                    data2[4], data2[5], data2[6], data2[7],
                    data2[8], data2[9], data2[10], data2[11],
                    data2[12], data2[13], data2[14], data2[15]);

                MM1 *= MM2;
                MG1 *= MG2;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM1.data_4_4[i][j], MG1[i][j]);
                    }
                }
            }

        }

    }
*/
}

int main()
{
    system("cls");
    std::cout << "Library used for the tests : glm\n";
    // IterationValue(1000000);
    runTests();
    system("pause");
    return 0;
}