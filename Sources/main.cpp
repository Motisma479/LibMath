#include <iostream>
#include <algorithm>

#include "LibMath/Maths.hpp"
#include "LibMath/MathsStreams.hpp"

#include "glm/glm.hpp"
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VTest/VTest.hpp"

#define RAND_FLOAT (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) 
//#define RAND_FLOAT  *((float*)(void*)(rand()))
//#define RAND_DOUBLE static_cast <double> (rand())
#define RAND_DOUBLE (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) 


VTEST(Maths)
{

    NAMESPACE(Maths Constants)
    {
        NAMESPACE(PI Float)
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
        NAMESPACE(PI Double)
        {
            TEST(PI)
            {
                COMPARE(Maths::Constants::PI_PRECISE, glm::pi<double>());
            }
        }
    }
    NAMESPACE(Maths Functions)
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

        NAMESPACE(Constructors)
        {

            TEST(default)
            {
                Maths::Vec2 VM; glm::vec2 VG(0); // test default constructor

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(Scalar)
            {
                float value = RAND_FLOAT;
                Maths::Vec2 VM(value); glm::vec2 VG(value); // test one scalar constructor

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(x_y)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]); // test constructor with x , y parameter

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(Vec3)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 TMP_1(value[0], value[1], value[2]); glm::vec3 TMP_2(value[0], value[1], value[2]);
                Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec3

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }

            TEST(Vec4)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec4 TMP_1(value[0], value[1], value[2], value[3]); glm::vec4 TMP_2(value[0], value[1], value[2], value[3]);
                Maths::Vec2 VM(TMP_1); glm::vec2 VG(TMP_2); // test constructor from a Vec4

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
            }
        
        }

        NAMESPACE(Utils)
        {

            TEST(GetMagnitude)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);
                
                COMPARE(VM.GetMagnitude(), glm::length(VG));
            }

            TEST(GetMagnitudeSquared)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);

                COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
            }

            TEST(GetNormalized)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);

                Maths::Vec2 tempM = VM.GetNormalized();
                glm::vec2 tempG = glm::normalize(VG);

                COMPARE(tempM.x, tempG.x);
                COMPARE(tempM.y, tempG.y);
            }

            TEST(GetPerpendicular)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 VM(value[0], value[1]); glm::vec2 VG(value[0], value[1]);

                Maths::Vec2 tempM = VM.GetPerpendicular();
                glm::vec2 tempG(VG.y, -VG.x);
                
                COMPARE(tempM.x, tempG.x);
                COMPARE(tempM.y, tempG.y);
            }
        
        }

        NAMESPACE(Assignment and Equality operators)
        {

            TEST(Operator = Vec3)
            {
                Maths::Vec3 VMA(RAND_FLOAT, RAND_FLOAT, RAND_FLOAT);

                Maths::Vec2 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
            }

            TEST(Operator = Vec4)
            {
                Maths::Vec4 VMA(RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT);

                Maths::Vec2 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
            }

            TEST(Operator = Sca)
            {
                Maths::Vec2 VM;
                float value = RAND_FLOAT;

                VM = value;

                COMPARE(VM.x, value);
                COMPARE(VM.y, value);
            }

            TEST(Operator negate)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(-value[0], -value[1]);

                COMPARE((-VMA).x, VMB.x);
                COMPARE((-VMA).y, VMB.y);
            }

            TEST(Operator ==)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[0], value[1]);
                Maths::Vec2 VMC(RAND_FLOAT, RAND_FLOAT);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(Operator !=)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 VMA(value[0], value[1]);
                Maths::Vec2 VMB(value[0], value[1]);
                Maths::Vec2 VMC(RAND_FLOAT, RAND_FLOAT);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

            TEST(Operator [])
            {
                Maths::Vec2 VM(RAND_FLOAT, RAND_FLOAT);
                COMPARE(VM[0], VM.x);
                COMPARE(VM[1], VM.y);
            }
        }
        
        NAMESPACE(Vec2 to Vec2 operators)
        {

            TEST(Operator +)
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

            TEST(Operator -)
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

        NAMESPACE(Vec2 to This operators)
        {

            TEST(Operator +=)
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

            TEST(Operator -=)
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

        NAMESPACE(Scaler to Vec2 operators)
        {

            TEST(Operator +)
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

            TEST(Operator -)
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

            TEST(Operator *)
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

            TEST(Operator /)
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

        NAMESPACE(Scaler to This operators)
        {

            TEST(Operator +=)
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

            TEST(Operator -=)
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

            TEST(Operator *=)
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

            TEST(Operator /=)
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
        NAMESPACE(Constructors)
        {

            TEST(default)
            {
                Maths::Vec3 VM; glm::vec3 VG(0);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(Scalar)
            {
                float value = RAND_FLOAT;
                Maths::Vec3 VM(value); glm::vec3 VG(value);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(x_y_z)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 VM(value[0], value[1], value[2]); glm::vec3 VG(value[0], value[1], value[2]);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(Vec2)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 TMP_1(value[0], value[1]);
                Maths::Vec3 VM(TMP_1); glm::vec3 VG(value[0], value[1], 0);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(Vec2_z)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec2 TMP_1(value[0], value[1]);
                Maths::Vec3 VM(TMP_1, value[2]); glm::vec3 VG(value[0], value[1], value[2]);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

            TEST(Vec4)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Vec4 TMP_1(value[0], value[1], value[2], value[3]); glm::vec4 TMP_2(value[0], value[1], value[2], value[3]);
                Maths::Vec3 VM(TMP_1); glm::vec3 VG(TMP_2);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
            }

        }

        NAMESPACE(Utils)
        {
            TEST(GetMagnitude)
            {
                float value[3] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT };

                Maths::Vec3 VM(value[0], value[1], value[2]); glm::vec3 VG(value[0], value[1], value[2]);

                COMPARE(VM.GetMagnitude(), glm::length(VG));
            }

            TEST(GetMagnitudeSquared)
            {
                float value[3] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT };

                Maths::Vec3 VM(value[0], value[1], value[2]); glm::vec3 VG(value[0], value[1], value[2]);

                COMPARE(VM.GetMagnitudeSquared(), glm::length2(VG));
            }

            TEST(GetNormalized)
            {
                float value[3] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT };

                Maths::Vec3 VM(value[0], value[1], value[2]); glm::vec3 VG(value[0], value[1], value[2]);

                Maths::Vec3 tempM = VM.GetNormalized();
                glm::vec3 tempG = glm::normalize(VG);

                COMPARE(tempM.x, tempG.x);
                COMPARE(tempM.y, tempG.y);
                COMPARE(tempM.z, tempG.z);
            }

        }

        NAMESPACE(Assignment and Equality operators)
        {

            TEST(Operator = Vec2)
            {
                float value[2] = { RAND_FLOAT ,RAND_FLOAT};

                Maths::Vec2 VMA(value[0], value[1]);

                Maths::Vec3 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(0, VMB.z);
            }

            TEST(Operator = Vec4)
            {
                float value[4] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT, RAND_FLOAT };

                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                Maths::Vec3 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(VMA.z, VMB.z);
            }

            TEST(Operator = Sca)
            {
                float value = RAND_FLOAT;
                Maths::Vec3 VM;

                VM = value;

                COMPARE(VM.y, value);
                COMPARE(VM.x, value);
                COMPARE(VM.z, value);
            }

            TEST(Operator negate)
            {
                float value[3] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);
                Maths::Vec3 VMB(-value[0], -value[1], -value[2]);

                COMPARE((-VMA).x, VMB.x);
                COMPARE((-VMA).y, VMB.y);
                COMPARE((-VMA).z, VMB.z);
            }

            TEST(Operator ==)
            {
                float value[3] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);
                Maths::Vec3 VMB(value[0], value[1], value[2]);
                Maths::Vec3 VMC(value[2], value[1], value[0]);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(Operator !=)
            {
                float value[3] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);
                Maths::Vec3 VMB(value[0], value[1], value[2]);
                Maths::Vec3 VMC(value[2], value[1], value[0]);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

            TEST(Operator [])
            {
                float value[3] = { RAND_FLOAT ,RAND_FLOAT ,RAND_FLOAT };

                Maths::Vec3 VM(value[0], value[1], value[2]);
                COMPARE(VM[0], VM.x);
                COMPARE(VM[1], VM.y);
                COMPARE(VM[2], VM.z);
            }

        }
        
        NAMESPACE(Vec3 to Vec3 operators)
        {

            TEST(Operator +)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);
                Maths::Vec3 VMB(value[2], value[1], value[0]);

                Maths::Vec3 VMC = VMA + VMB;

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[2], value[1], value[0]);

                glm::vec3 VGC = VGA + VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
            }

            TEST(Operator -)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);
                Maths::Vec3 VMB(value[2], value[1], value[0]);

                Maths::Vec3 VMC = VMA - VMB;

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[2], value[1], value[0]);

                glm::vec3 VGC = VGA - VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
            }

        }

        NAMESPACE(Vec3 to This operators)
        {

            TEST(Operator +=)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);
                Maths::Vec3 VMB(value[2], value[1], value[0]);

                VMA += VMB;

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[2], value[1], value[0]);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Operator -=)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);
                Maths::Vec3 VMB(value[2], value[1], value[0]);

                VMA -= VMB;

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[2], value[1], value[0]);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

        }

        NAMESPACE(Scaler to Vec3 operators)
        {

            TEST(Operator +)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                Maths::Vec3 VMB = VMA + value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                glm::vec3 VGC = VGA + VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Operator -)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                Maths::Vec3 VMB = VMA - value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                glm::vec3 VGC = VGA - VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Operator *)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                Maths::Vec3 VMB = VMA * value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                glm::vec3 VGC = VGA * VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Operator /)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                Maths::Vec3 VMB = VMA / value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                glm::vec3 VGC = VGA / VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

        }

        NAMESPACE(Scaler to This operators)
        {

            TEST(Operator +=)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                VMA += value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Operator -=)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                VMA -= value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Operator *=)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                VMA *= value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Operator /=)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec3 VMA(value[0], value[1], value[2]);

                VMA /= value[0];

                glm::vec3 VGA(value[0], value[1], value[2]);
                glm::vec3 VGB(value[0], value[0], value[0]);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

        }
    }

    NAMESPACE(Vector4)
    {

        NAMESPACE(Constructors)
        {

            TEST(default)
            {
                Maths::Vec4 VM; glm::vec4 VG(0);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Scalar)
            {
                float value = RAND_FLOAT;
                Maths::Vec4 VM(value); glm::vec4 VG(value);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(x_y_z_w)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VM(value[0], value[1], value[2], value[3]);
                glm::vec4 VG(value[0], value[1], value[2], value[3]);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec2)
            {
                float value[2] = { RAND_FLOAT,RAND_FLOAT };

                Maths::Vec2 TMP_1(value[0], value[1]);
                Maths::Vec4 VM(TMP_1);
                
                glm::vec4 VG(value[0], value[1], 0, 1);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec2_z)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec2 TMP_1(value[0], value[1]);
                Maths::Vec4 VM(TMP_1, value[2]);
                
                glm::vec4 VG(value[0], value[1], value[2], 1);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec2_z_w)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec2 TMP_1(value[0], value[1]);
                Maths::Vec4 VM(TMP_1, value[2], value[3]);
                
                glm::vec4 VG(value[0], value[1], value[2], value[3]);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec3)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec3 TMP_1(value[0], value[1], value[2]);
                Maths::Vec4 VM(TMP_1);
                
                glm::vec4 VG(value[0], value[1], value[2], 1); // test constructor from a Vec4

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

            TEST(Vec3_w)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec3 TMP_1(value[0], value[1], value[2]);
                Maths::Vec4 VM(TMP_1, value[3]);

                glm::vec4 VG(value[0], value[1], value[2], value[3]);

                COMPARE(VM.x, VG.x);
                COMPARE(VM.y, VG.y);
                COMPARE(VM.z, VG.z);
                COMPARE(VM.w, VG.w);
            }

        }

        NAMESPACE(Utils)
        {
            TEST(GetMagnitude)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VM(value[0], value[1], value[2], value[3]);
                glm::vec4 VG(value[0], value[1], value[2], value[3]);

                COMPARE(VM.GetMagnitude(), glm::length(VG));
            }

            TEST(GetMagnitudeSquared)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VM(value[0], value[1], value[2], value[3]);
                glm::vec4 VG(value[0], value[1], value[2], value[3]);

                COMPARE_WITH_PRECISION(VM.GetMagnitudeSquared(), glm::length2(VG), Maths::Constants::TOLERANCE);
            }

            TEST(GetNormalized)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VM(value[0], value[1], value[2], value[3]);
                glm::vec4 VG(value[0], value[1], value[2], value[3]);

                Maths::Vec4 tempM = VM.GetNormalized();
                glm::vec4 tempG = glm::normalize(VG);

                COMPARE_WITH_PRECISION(tempM.x, tempG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(tempM.y, tempG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(tempM.z, tempG.z, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(tempM.w, tempG.w, Maths::Constants::TOLERANCE);
            }

            TEST(GetHomogenized)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VM(value[0], value[1], value[2], value[3]);
                glm::vec4 VG(value[0], value[1], value[2], value[3]);

                Maths::Vec4 ResultM = VM.GetHomogenized();
                glm::vec4 ResultG = VG / VG.w;

                COMPARE(ResultM.x, ResultG.x);
                COMPARE(ResultM.y, ResultG.y);
                COMPARE(ResultM.z, ResultG.z);
                COMPARE(ResultM.w, ResultG.w);
            }

        }

        NAMESPACE(Assignment and Equality operators)
        {

            TEST(Operator = Vec2)
            {
                Maths::Vec2 VMA(RAND_FLOAT, RAND_FLOAT);

                Maths::Vec4 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(0, VMB.z);
                COMPARE(1, VMB.w);
            }

            TEST(Operator = Vec3)
            {
                Maths::Vec3 VMA(RAND_FLOAT, RAND_FLOAT, RAND_FLOAT);

                Maths::Vec4 VMB;

                VMB = VMA;

                COMPARE(VMA.x, VMB.x);
                COMPARE(VMA.y, VMB.y);
                COMPARE(VMA.z, VMB.z);
                COMPARE(1, VMB.w);
            }

            TEST(Operator = Sca)
            {
                float value = RAND_FLOAT;
                Maths::Vec4 VMA;

                VMA = value;

                COMPARE(VMA.x, value);
                COMPARE(VMA.y, value);
                COMPARE(VMA.z, value);
                COMPARE(VMA.w, value);
            }

            TEST(Operator negate)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                COMPARE((-VMA).x, -value[0]);
                COMPARE((-VMA).y, -value[1]);
                COMPARE((-VMA).z, -value[2]);
                COMPARE((-VMA).w, -value[3]);
            }

            TEST(Operator ==)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMB(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMC(value[2], value[1], value[3], value[0]);

                COMPARE(VMA == VMB, true);
                COMPARE(VMA == VMC, false);
            }

            TEST(Operator !=)
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMB(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMC(value[2], value[1], value[3], value[0]);

                COMPARE(VMA != VMB, false);
                COMPARE(VMA != VMC, true);
            }

            TEST(Operator [])
            {
                float value[4] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VM(value[0], value[1], value[2], value[3]);
                COMPARE(VM[0], VM.x);
                COMPARE(VM[1], VM.y);
                COMPARE(VM[2], VM.z);
                COMPARE(VM[3], VM.w);
            }

        }

        NAMESPACE(Vec4 to Vec4 operators)
        {

            TEST(Operator +)
            {
                float value[8] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMB(value[4], value[5], value[6], value[7]);

                Maths::Vec4 VMC = VMA + VMB;

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[5], value[6], value[7]);

                glm::vec4 VGC = VGA + VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
                COMPARE(VMC.w, VGC.w);
            }

            TEST(Operator -)
            {
                float value[8] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMB(value[4], value[5], value[6], value[7]);

                Maths::Vec4 VMC = VMA - VMB;

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[5], value[6], value[7]);

                glm::vec4 VGC = VGA - VGB;

                COMPARE(VMC.x, VGC.x);
                COMPARE(VMC.y, VGC.y);
                COMPARE(VMC.z, VGC.z);
                COMPARE(VMC.w, VGC.w);
            }

        }

        NAMESPACE(Vec4 to This operators)
        {

            TEST(Operator +=)
            {
                float value[8] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMB(value[4], value[5], value[6], value[7]);

                VMA += VMB;

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[5], value[6], value[7]);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
                COMPARE(VMA.w, VGA.w);
            }

            TEST(Operator -=)
            {
                float value[8] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };

                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);
                Maths::Vec4 VMB(value[4], value[5], value[6], value[7]);

                VMA -= VMB;

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[5], value[6], value[7]);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
                COMPARE(VMA.w, VGA.w);
            }

        }

        NAMESPACE(Scaler to Vec4 operators)
        {

            TEST(Operator +)
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                Maths::Vec4 VMB = VMA + value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                glm::vec4 VGC = VGA + VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Operator - )
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                Maths::Vec4 VMB = VMA - value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                glm::vec4 VGC = VGA - VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Operator *)
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                Maths::Vec4 VMB = VMA * value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                glm::vec4 VGC = VGA * VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }

            TEST(Operator /)
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                Maths::Vec4 VMB = VMA / value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                glm::vec4 VGC = VGA / VGB;

                COMPARE(VMB.x, VGC.x);
                COMPARE(VMB.y, VGC.y);
                COMPARE(VMB.z, VGC.z);
            }
        
        }

        NAMESPACE(Scale to This operators)
        {

            TEST(Operator +=)
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                VMA += value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                VGA += VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Operator -= )
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                VMA -= value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                VGA -= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Operator *= )
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                VMA *= value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                VGA *= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }

            TEST(Operator /= )
            {
                float value[5] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Vec4 VMA(value[0], value[1], value[2], value[3]);

                VMA /= value[4];

                glm::vec4 VGA(value[0], value[1], value[2], value[3]);
                glm::vec4 VGB(value[4], value[4], value[4], value[4]);

                VGA /= VGB;

                COMPARE(VMA.x, VGA.x);
                COMPARE(VMA.y, VGA.y);
                COMPARE(VMA.z, VGA.z);
            }
        
        }

    }

    NAMESPACE(Vector functions)
    {
        NAMESPACE(Normalize)
        {
            TEST(Vec2)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 MV(value[0], value[1]); glm::vec2 GV(value[0], value[1]);

                Maths::Vectors::Normalize(MV); GV = glm::normalize(GV);

                COMPARE(MV.x, GV.x);
                COMPARE(MV.x, GV.x);
            }

            TEST(Vec3)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 MV(value[0], value[1], value[2]); glm::vec3 GV(value[0], value[1], value[2]);

                Maths::Vectors::Normalize(MV); GV = glm::normalize(GV);

                COMPARE(MV.x, GV.x);
                COMPARE(MV.x, GV.x);
                COMPARE(MV.z, GV.z);
            }

            TEST(Vec4)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec4 MV(value[0], value[1], value[2], value[3]); glm::vec4 GV(value[0], value[1], value[2], value[3]);

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
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 MVA(value[0], value[1]); Maths::Vec2 MVB(value[2], value[3]);
                glm::vec2 GVA(value[0], value[1]); glm::vec2 GVB(value[2], value[3]);

                COMPARE(Maths::Vectors::DotProduct(MVA, MVB), glm::dot(GVA, GVB));
            }

            TEST(Vec3)
            {
                float value[6] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 MVA(value[0], value[1], value[2]); Maths::Vec3 MVB(value[3], value[4], value[5]);
                glm::vec3 GVA(value[0], value[1], value[2]); glm::vec3 GVB(value[3], value[4], value[5]);

                COMPARE(Maths::Vectors::DotProduct(MVA, MVB), glm::dot(GVA, GVB));
            }

            TEST(Vec4)
            {
                float value[8] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec4 MVA(value[0], value[1], value[2], value[3]); Maths::Vec4 MVB(value[4], value[5], value[6], value[7]);
                glm::vec4 GVA(value[0], value[1], value[2], value[3]); glm::vec4 GVB(value[4], value[5], value[6], value[7]);

                COMPARE(Maths::Vectors::DotProduct(MVA, MVB), glm::dot(GVA, GVB));
            }
        }

        NAMESPACE(DistanceBetween)
        {
            TEST(Vec2)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 MVA(value[0], value[1]); Maths::Vec2 MVB(value[2], value[3]);
                glm::vec2 GVA(value[0], value[1]); glm::vec2 GVB(value[2], value[3]);

                COMPARE(Maths::Vectors::DistanceBetween(MVA, MVB), glm::distance(GVA, GVB));
            }

            TEST(Vec3)
            {
                float value[6] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 MVA(value[0], value[1], value[2]); Maths::Vec3 MVB(value[3], value[4], value[5]);
                glm::vec3 GVA(value[0], value[1], value[2]); glm::vec3 GVB(value[3], value[4], value[5]);

                COMPARE(Maths::Vectors::DistanceBetween(MVA, MVB), glm::distance(GVA, GVB));
            }

            TEST(Vec4)
            {
                float value[8] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec4 MVA(value[0], value[1], value[2], value[3]); Maths::Vec4 MVB(value[4], value[5], value[6], value[7]);
                glm::vec4 GVA(value[0], value[1], value[2], value[3]); glm::vec4 GVB(value[4], value[5], value[6], value[7]);

                COMPARE(Maths::Vectors::DistanceBetween(MVA, MVB), glm::distance(GVA, GVB));
            }
        }

        NAMESPACE(AngleBetween)
        {
            TEST(Vec2)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 MVA(value[0], value[1]); Maths::Vec2 MVB(value[2], value[3]);
                glm::vec2 GVA(value[0], value[1]); glm::vec2 GVB(value[2], value[3]);

                GVA = glm::normalize(GVA);
                GVB = glm::normalize(GVB);

                COMPARE_WITH_PRECISION(Maths::Vectors::AngleBetween(MVA, MVB), glm::orientedAngle(GVA, GVB), Maths::Constants::TOLERANCE);
            }

            TEST(Vec3)
            {
                float value[6] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 MVA(value[0], value[1], value[2]); Maths::Vec3 MVB(value[3], value[4], value[5]);

                glm::vec3 GVA(value[0], value[1], value[2]); glm::vec3 GVB(value[3], value[4], value[5]);
                GVA = glm::normalize(GVA);
                GVB = glm::normalize(GVB);
                glm::vec3 normal(0.0f, 0.0f, -1.0f);

                COMPARE_WITH_PRECISION(Maths::Vectors::AngleBetween(MVA, MVB), glm::orientedAngle(GVA, GVB, normal), 0.000001f);
                std::cout << "a normal variable added to work with glm" << std::endl;
            }

            TEST(Vec4)
            {
                float value[8] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec4 MVA(value[0], value[1], value[2], value[3]); Maths::Vec4 MVB(value[4], value[5], value[6], value[7]);
                glm::vec4 GVA(value[0], value[1], value[2], value[3]); glm::vec4 GVB(value[4], value[5], value[6], value[7]);
                
                float anglebetweenGLM = acos(std::clamp(glm::dot(GVA, GVB) / ( glm::length(GVA) * glm::length(GVB)), -1.0f, 1.0f));

                COMPARE_WITH_PRECISION(Maths::Vectors::AngleBetween(MVA, MVB), anglebetweenGLM, Maths::Constants::TOLERANCE);
                std::cout << "since glm does not have an angle bewteen two vector 4 I implemented it using glm functions." <<std::endl;
            }
        }

        NAMESPACE(CrossProduct)
        {
            TEST(Vec2)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec2 MVA(value[0], value[1]); Maths::Vec2 MVB(value[2], value[3]);
                glm::vec2 GVA(value[0], value[1]); glm::vec2 GVB(value[2], value[3]);
                float crossForGLM = GVA.x * GVB.y - GVA.y * GVB.x;

                COMPARE(Maths::Vectors::CrossProduct(MVA, MVB), crossForGLM);
                std::cout << "glm does not have a cross for vec2 so i manually caculate here." <<std::endl;
            }

            TEST(Vec3)
            {
                float value[6] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 MVA(value[0], value[1], value[2]); Maths::Vec3 MVB(value[3], value[4], value[5]);
                glm::vec3 GVA(value[0], value[1], value[2]); glm::vec3 GVB(value[3], value[4], value[5]);

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
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 MV(value[0], value[1], value[2]);
                glm::vec3 GV(value[0], value[1], value[2]);

                float angle = 90.f;

                float x = 0.f;
                float y = 0.f;
                float z = 1.f;

                Maths::Vec3 resultM = Maths::Vectors::Rotate(MV, angle, Maths::Vec3(x,y,z));
                glm::vec3 resultG = glm::angleAxis(angle, glm::vec3(x,y,z)) * GV;

                COMPARE_WITH_PRECISION(resultM.x, resultG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(resultM.y, resultG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(resultM.z, resultG.z, Maths::Constants::TOLERANCE);
            }
        }
    }

    NAMESPACE(Matrix 3x3)
    {

        NAMESPACE(Constructors)
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

            TEST(data[9])
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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

            TEST(indentity value)
            {
                float value = RAND_FLOAT;
                Maths::Mat3 MM(value);

                glm::mat3 MG(value);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(9 value)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
        
            TEST(Mat4)
            {
                float data[16] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MTemp(data[0], data[1], data[2], data[3],
                                  data[4], data[5], data[6], data[7],
                                  data[8], data[9], data[10], data[11],
                                  data[12], data[13], data[14], data[15]);

                Maths::Mat3 MM(MTemp);

                glm::mat3 MG(data[0], data[1], data[2],
                             data[4], data[5], data[6],
                             data[8], data[9], data[10]);

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
                float value = RAND_FLOAT;
                Maths::Mat3 MM = Maths::Mat3::Rotate2D(value);

                glm::mat4 MG = glm::rotate(value, glm::vec3(0, 0, 1));

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE_WITH_PRECISION(MM[i][j], MG[i][j], Maths::Constants::TOLERANCE);
                    }
                }
            }

            TEST(Translate2D)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Mat3 MM = Maths::Mat3::Translate2D(Maths::Vec2(value[0], value[1]));

                glm::mat4 MG = glm::translate(glm::vec3(value[0], value[1], 0.f));

                COMPARE(MM[2][0], MG[3][0]);
                COMPARE(MM[2][1], MG[3][1]);

            }

            TEST(Scale2D)
            {
                float value[2] = { RAND_FLOAT, RAND_FLOAT };
                Maths::Mat3 MM = Maths::Mat3::Scale2D(Maths::Vec2(value[0], value[1]));

                glm::mat4 MG = glm::scale(glm::vec3(value[0], value[1], 1.f));

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
                float value[5] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,RAND_FLOAT ,RAND_FLOAT };

                Maths::Mat3 MM = Maths::Mat3::Transform(Maths::Vec2(value[0], value[1]), value[2], Maths::Vec2(value[3], value[4]));

                glm::mat4 MG = glm::identity<glm::mat4>();
                MG[2][0] = value[0];
                MG[2][1] = value[1];
                MG *= glm::rotate(value[2], glm::vec3(0.f, 0.f, 1.f)) * glm::scale(glm::vec3(value[3], value[4], 1.f));

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM.data_3_3[i][j], MG[i][j]);
                    }
                }
            }

            TEST(GetTranspose)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM = MM.GetTranspose();
                MG = glm::transpose(MG);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(GetInverse)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM = MM.GetInverse();
                MG = glm::inverse(MG);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE_WITH_PRECISION(MM[i][j], MG[i][j], 3e-5);
                    }
                }
            }

            TEST(GetDeterminant)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                COMPARE_WITH_PRECISION(MM.GetDeterminant(), glm::determinant(MG), Maths::Constants::TOLERANCE);
            }
   
            TEST(GetTrace)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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

            TEST(operator = data[9])
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };


                Maths::Mat3 MM;
                MM = data;

                for (int i = 0; i < 9; i++)
                {
                    COMPARE(MM.data[i], data[i]);
                }
            }

            TEST(operator = Mat4)
            {
                float data[16] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    {RAND_FLOAT, RAND_FLOAT, RAND_FLOAT},
                    {RAND_FLOAT, RAND_FLOAT, RAND_FLOAT},
                    {RAND_FLOAT, RAND_FLOAT, RAND_FLOAT}
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);


                Maths::Mat3 MM2 = MM * value;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM2[i][j], MG[i][j]* value);
                    }
                }
            }

            TEST(operator /)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);


                Maths::Mat3 MM2 = MM / value;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM2[i][j], MG[i][j] / value);
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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM *= value;
                MG *= value;

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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                MM /= value;
                MG /= value;

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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[2] = { RAND_FLOAT, RAND_FLOAT };

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
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

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

    NAMESPACE(Matrix 4x4)
    {

        NAMESPACE(Constructors)
        {
            TEST(default)
            {
                Maths::Mat4 MM; glm::mat4 MG(0);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }

            }

            TEST(data[16])
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }

            }

            TEST(indentity value)
            {
                float value = RAND_FLOAT;
                Maths::Mat4 MM(value);

                glm::mat4 MG(value);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(16 value)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM(data[0], data[1], data[2], data[3],
                               data[4], data[5], data[6], data[7],
                               data[8], data[9], data[10], data[11],
                               data[12], data[13], data[14], data[15]);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                             data[4], data[5], data[6], data[7],
                             data[8], data[9], data[10], data[11],
                             data[12], data[13], data[14], data[15]);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Mat3)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat3 MTemp(data[0], data[1], data[2],
                                  data[3], data[4], data[5],
                                  data[6], data[7], data[8]);

                Maths::Mat4 MM(MTemp);

                glm::mat4 MG(data[0], data[1], data[2], 0,
                             data[3], data[4], data[5], 0,
                             data[6], data[7], data[8], 0,
                             0,       0,       0,       1);

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
            TEST(Translate)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Mat4 MM = Maths::Mat4::Translate(Maths::Vec3(value[0], value[1], value[2]));

                glm::mat4 MG = glm::translate(glm::vec3(value[0], value[1], value[2]));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Rotate)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Mat4 MM = Maths::Mat4::Rotate(Maths::Vec3(value[0], value[1], value[2]));

                glm::mat4 MG = glm::rotate(value[0], glm::vec3(1, 0, 0)) * glm::rotate(value[1], glm::vec3(0, 1, 0)) * glm::rotate(value[2], glm::vec3(0, 0, 1));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(RotateX)
            {
                float value = RAND_FLOAT;
                Maths::Mat4 MM = Maths::Mat4::RotateX(value);

                glm::mat4 MG = glm::rotate(value, glm::vec3(1, 0, 0));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(RotateY)
            {
                float value = RAND_FLOAT;
                Maths::Mat4 MM = Maths::Mat4::RotateY(value);

                glm::mat4 MG = glm::rotate(value, glm::vec3(0, 1, 0));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(RotateZ)
            {
                float value = RAND_FLOAT;
                Maths::Mat4 MM = Maths::Mat4::RotateZ(value);

                glm::mat4 MG = glm::rotate(value, glm::vec3(0, 0, 1));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Scale)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Mat4 MM = Maths::Mat4::Scale(Maths::Vec3(value[0], value[1], value[2]));

                glm::mat4 MG = glm::scale(glm::vec3(value[0], value[1], value[2]));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Transform Rotation as Vec3)
            {
                float value[9] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Mat4 MM = Maths::Mat4::Transform(Maths::Vec3(value[0], value[1], value[2]), Maths::Vec3(value[3], value[4], value[5]), Maths::Vec3(value[6], value[7], value[8]));

                glm::mat4 MG = glm::translate(glm::vec3(value[0], value[1], value[2]));
                MG *= glm::rotate(value[3], glm::vec3(1, 0, 0)) * glm::rotate(value[4], glm::vec3(0, 1, 0)) * glm::rotate(value[5], glm::vec3(0, 0, 1));
                MG *= glm::scale(glm::vec3(value[6], value[7], value[8]));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM.data_4_4[i][j], MG[i][j]);
                    }
                }
            }

            TEST(Transform Rotation as Quat)
            {
                float value[9] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat rotation(Maths::Vec3(value[3], value[4], value[5]));
                Maths::Mat4 MM = Maths::Mat4::Transform(Maths::Vec3(value[0], value[1], value[2]), rotation, Maths::Vec3(value[6], value[7], value[8]));
                
                glm::mat4 MG = glm::translate(glm::vec3(value[0], value[1], value[2]));
                MG *= glm::toMat4(glm::quat(glm::vec3(value[3], value[4], value[5])));
                MG *= glm::scale(glm::vec3(value[6], value[7], value[8]));

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM[i][j], MG[i][j], Maths::Constants::TOLERANCE);
                    }
                }
            }

            TEST(GetTranspose)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                Maths::Mat4 MM2 = MM.GetTranspose();
                glm::mat4 MG2 = glm::transpose(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM2[i][j], MG2[i][j]);
                    }
                }
            }

            TEST(GetInverse)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                             data[4], data[5], data[6], data[7],
                             data[8], data[9], data[10], data[11],
                             data[12], data[13], data[14], data[15]);

                Maths::Mat4 MM2 = MM.GetInverse();
                glm::mat4 MG2 = glm::inverse(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM2[i][j], MG2[i][j], 3e-5);
                    }
                }
            }

            TEST(Determinant)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                             data[4], data[5], data[6], data[7],
                             data[8], data[9], data[10], data[11],
                             data[12], data[13], data[14], data[15]);

                COMPARE(MM.GetDeterminant(), glm::determinant(MG));
            }

            TEST(Trace)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                COMPARE(MM.GetTrace(), (MG[0][0] + MG[1][1] + MG[2][2] + MG[3][3]));
            }
        }

        NAMESPACE(Assignment and Equality operators)
        {
            TEST(operator = data[16])
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };


                Maths::Mat4 MM;
                MM = data;

                for (int i = 0; i < 16; i++)
                {
                    COMPARE(MM.data[i], data[i]);
                }
            }
            
            TEST(operator = Mat3)
            {
                float data[9] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                Maths::Mat3 M3(data);

                Maths::Mat4 M4;
                M4 = M3;

                Maths::Mat4 check(data[0], data[1], data[2], 0,
                                  data[3], data[4], data[5], 0,
                                  data[6], data[7], data[8], 0,
                                  0,       0,       0,       1);

                for (int i = 0; i < 16; i++)
                {
                    COMPARE(M4.data[i], check.data[i]);
                }
            }

            TEST(operator negate)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                glm::mat4 GM(data[0], data[1], data[2], data[3],
                             data[4], data[5], data[6], data[7],
                             data[8], data[9], data[10], data[11],
                             data[12], data[13], data[14], data[15]);

                Maths::Mat4 MM(data);

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
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM_A(data);
                Maths::Mat4 MM_B(data);
                Maths::Mat4 MM_C(data2);

                COMPARE(MM_A == MM_B, true);
                COMPARE(MM_A == MM_C, false);

            }

            TEST(operator !=)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM_A(data);
                Maths::Mat4 MM_B(data);
                Maths::Mat4 MM_C(data2);

                COMPARE(MM_A != MM_B, false);
                COMPARE(MM_A != MM_C, true);

            }

            TEST(operator [])
            {
                Maths::Vec4 data[4] =
                {
                    {RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT},
                    {RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT},
                    {RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT},
                    {RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT}
                };

                Maths::Mat4 MM(data[0][0], data[0][1], data[0][2], data[0][3],
                               data[1][0], data[1][1], data[1][2], data[1][3],
                               data[2][0], data[2][1], data[2][2], data[2][3],
                               data[3][0], data[3][1], data[3][2], data[3][3]);

                for (int i = 0; i < 4; i++)
                {
                    COMPARE(MM[i].x, data[i].x);
                    COMPARE(MM[i].y, data[i].y);
                    COMPARE(MM[i].z, data[i].z);
                    COMPARE(MM[i].w, data[i].w);
                }
            }

        }

        NAMESPACE(Mat4 to Mat4 operators)
        {

            TEST(operator +)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                        COMPARE(MM3[i][j], MG3[i][j]);
                    }
                }

            }

            TEST(operator -)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                        COMPARE(MM3[i][j], MG3[i][j]);
                    }
                }
            }

            TEST(operator *)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                        COMPARE(MM3[i][j], MG3[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Mat4 to This operators)
        {

            TEST(operator +=)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                        COMPARE(MM1[i][j], MG1[i][j]);
                    }
                }

            }

            TEST(operator -=)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                        COMPARE(MM1[i][j], MG1[i][j]);
                    }
                }
            }

            TEST(operator *=)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float data2[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
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
                        COMPARE(MM1[i][j], MG1[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Scalar to Mat4 operators)
        {

            TEST(operator *)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);


                MM = MM * value;
                MG = MG * value;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(operator /)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);


                MM = MM / value;
                MG = MG / value;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Scalar to this operators)
        {

            TEST(operator *=)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                MM *= value;
                MG *= value;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

            TEST(operator /=)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };
                float value = RAND_FLOAT;

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                MM /= value;
                MG /= value;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

        }
        
        NAMESPACE(Mat4 to Vec3 operators)
        {
            TEST(operator *)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Mat4 MM(data);
                Maths::Vec3 MV(data2[0], data2[1], data2[2]);

                glm::mat4 GM(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);
                glm::vec3 GV(data2[0], data2[1], data2[2]);

                Maths::Vec3 MR = MM * MV;
                glm::vec3 GR = { GM[0][0] * GV.x + GM[0][1] * GV.y + GM[0][2] * GV.z + GM[0][3],
                    GM[1][0] * GV.x + GM[1][1] * GV.y + GM[1][2] * GV.z + GM[1][3],
                    GM[2][0] * GV.x + GM[2][1] * GV.y + GM[2][2] * GV.z + GM[2][3] };

                COMPARE(MR.x, GR.x);
                COMPARE(MR.y, GR.y);
                COMPARE(MR.z, GR.z);
            }
        }
        
        NAMESPACE(Mat4 to Vec4 operators)
        {
            TEST(operator *)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                float data2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Mat4 MM(data);
                Maths::Vec4 MV(data2[0], data2[1], data2[2], data2[3]);

                glm::mat4 GM(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);
                glm::vec4 GV(data2[0], data2[1], data2[2], data2[3]);//vec2 extended to a vec3 due to lack of operator.

                Maths::Vec4 MR = MM * MV;
                glm::vec4 GR = GV * GM;

                COMPARE(MR.x, GR.x);
                COMPARE(MR.y, GR.y);
                COMPARE(MR.z, GR.z);
                COMPARE(MR.w, GR.w);
            }
            
        }
        
    }

    NAMESPACE(Matrix functions)
    {

        NAMESPACE(Transpose)
        {
            TEST(Mat3)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                Maths::matrixes::Transpose(MM);
                MG = glm::transpose(MG);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }
            
            TEST(Mat4)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                Maths::matrixes::Transpose(MM);
                MG = glm::transpose(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE(MM[i][j], MG[i][j]);
                    }
                }
            }

        }

        NAMESPACE(Inverse)
        {
            TEST(Mat3)
            {
                float data[9] =
                {
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                    RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };


                Maths::Mat3 MM(data);

                glm::mat3 MG(data[0], data[1], data[2],
                    data[3], data[4], data[5],
                    data[6], data[7], data[8]);

                Maths::matrixes::Inverse(MM);
                MG = glm::inverse(MG);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE_WITH_PRECISION(MM[i][j], MG[i][j], 3e-6);
                    }
                }
            }
            
            TEST(Mat4)
            {
                float data[16] =
                {
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT,
                     RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT
                };

                Maths::Mat4 MM(data);

                glm::mat4 MG(data[0], data[1], data[2], data[3],
                    data[4], data[5], data[6], data[7],
                    data[8], data[9], data[10], data[11],
                    data[12], data[13], data[14], data[15]);

                Maths::matrixes::Inverse(MM);
                MG = glm::inverse(MG);

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        COMPARE_WITH_PRECISION(MM[i][j], MG[i][j], 3e-6);
                    }
                }
            }

        }

    }

    NAMESPACE(Quaternion)
    {
        NAMESPACE(Constructor)
        {
            TEST(default)
            {
                Maths::Quat QM;
                glm::quat QG(1,0,0,0);

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(w_x_y_z)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);

                glm::quat QG(value[0], value[1], value[2], value[3]);

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(Vec4)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec4 VM(value[1], value[2], value[3], value[0]);
                Maths::Quat QM(VM);
                
                //no equivalent for glm;
                glm::quat QG(value[0], value[1], value[2], value[3]);

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(w and Vec3 as imaginary)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 VM(value[1], value[2], value[3]);
                Maths::Quat QM(value[0], VM);

                glm::vec3 VG(value[1], value[2], value[3]);
                glm::quat QG(value[0], VG);

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(Vec3 as euler angles)
            {
                float value[3] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Vec3 VM(value[0], value[1], value[2]);
                Maths::Quat QM(VM);

                glm::vec3 VG(value[0], value[1], value[2]);
                glm::quat QG(VG);

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }
        }

        NAMESPACE(Utils)
        {
            TEST(Identity)
            {
                Maths::Quat QM;
                glm::quat QG = glm::quat_identity<float, glm::packed_highp>();
                    
                std::cout << "maybe make a function\n";
                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(FromAngleAxis)
            {
                float value = Maths::ToRadians(RAND_FLOAT);
                Maths::Quat QM = Maths::Quat::FromAngleAxis(value, Maths::Vec3::UP);
                glm::quat QG = glm::angleAxis(value, glm::vec3(0, 1, 0));

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);

                QM = Maths::Quat::FromAngleAxis(value, Maths::Vec3::DOWN);
                QG = glm::angleAxis(value, glm::vec3(0, -1, 0));

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);

                QM = Maths::Quat::FromAngleAxis(value, Maths::Vec3::RIGHT);
                QG = glm::angleAxis(value, glm::vec3(1, 0, 0));

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);

                QM = Maths::Quat::FromAngleAxis(value, Maths::Vec3::LEFT);
                QG = glm::angleAxis(value, glm::vec3(-1, 0, 0));

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);

                QM = Maths::Quat::FromAngleAxis(value, Maths::Vec3::FORWARD);
                QG = glm::angleAxis(value, glm::vec3(0, 0, 1));

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);

                QM = Maths::Quat::FromAngleAxis(value, Maths::Vec3::BACKWARD);
                QG = glm::angleAxis(value, glm::vec3(0, 0, -1));

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }
        
            TEST(LookAt)
            {
                float valueFrom[3] = {0,0,0};
                float valueTo[3] = {10,1,30};
                Maths::Quat QM = Maths::Quat::LookAt(Maths::Vec3(valueFrom[0], valueFrom[1], valueFrom[2]), Maths::Vec3(valueTo[0], valueTo[1], valueTo[2]));

                glm::vec3 dir = glm::normalize(glm::vec3(valueTo[0], valueTo[1], valueTo[2]) - glm::vec3(valueFrom[0], valueFrom[1], valueFrom[2]));
                glm::quat QG = glm::rotation(glm::vec3(0, 0, 1), dir);

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(FromEulerAngle)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Quat QM = Maths::Quat::FromEulerAngles(Maths::Vec3(value[0], value[1], value[2]));
                glm::quat QG(glm::vec3(value[0], value[1], value[2]));

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(FromMatrix Mat3)
            {
                float value = RAND_FLOAT;
                Maths::Quat QM = Maths::Quat::FromMatrix(Maths::Mat3::Rotate2D(value));
                glm::quat QG(glm::vec3(0, 0, value));

                COMPARE_WITH_PRECISION(QM.w, QG.w, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.x, QG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.y, QG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.z, QG.z, Maths::Constants::TOLERANCE);
            }

            TEST(FromMatrix Mat4)
            {
                float value[3] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT };
                Maths::Mat4 rotm = Maths::Mat4::Rotate(Maths::Vec3(value[0], value[1], value[2]));
                Maths::Quat QM = Maths::Quat::FromMatrix(rotm);

                glm::mat4 rotg = glm::rotate(value[0], glm::vec3(1, 0, 0));
                rotg *= glm::rotate(value[1], glm::vec3(0, 1, 0));
                rotg *= glm::rotate(value[2], glm::vec3(0, 0, 1));

                glm::quat QG = glm::toQuat(rotg);


                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(GetMagnitudeSquared)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);

                glm::quat QG(value[0], value[1], value[2], value[3]);

                COMPARE(QM.GetMagnitudeSquared(), glm::length2(QG));
            }

            TEST(GetMagnitude)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);

                glm::quat QG(value[0], value[1], value[2], value[3]);

                COMPARE_WITH_PRECISION(QM.GetMagnitude(), glm::length(QG),Maths::Constants::TOLERANCE);
            }

            TEST(GetNormalized)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                QM = QM.GetNormalized();
                glm::quat QG(value[0], value[1], value[2], value[3]);
                QG = glm::normalize(QG);


                COMPARE_WITH_PRECISION(QM.w, QG.w, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.x, QG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.y, QG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.z, QG.z, Maths::Constants::TOLERANCE);
            }

            TEST(GetConjugate)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                QM = QM.GetConjugate();
                glm::quat QG(value[0], value[1], value[2], value[3]);
                QG = glm::conjugate(QG);


                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }
        
            TEST(GetInverse)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                QM = QM.GetInverse();
                glm::quat QG(value[0], value[1], value[2], value[3]);
                QG = glm::inverse(QG);


                COMPARE_WITH_PRECISION(QM.w, QG.w, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.x, QG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.y, QG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.z, QG.z, Maths::Constants::TOLERANCE);
            }
        
            TEST(RotateVector)
            {
                float value[7] = { RAND_FLOAT,RAND_FLOAT,RAND_FLOAT,RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                Maths::Vec3 PosM(value[4], value[5], value[6]);

                PosM = QM.RotateVector(PosM);

                glm::quat QG(value[0], value[1], value[2], value[3]);
                glm::vec3 PosG(value[4], value[5], value[6]);

                PosG = glm::rotate(QG, PosG);


                COMPARE_WITH_PRECISION(PosM.x, PosG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(PosM.y, PosG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(PosM.z, PosG.z, Maths::Constants::TOLERANCE);
            }
            
            TEST(ToRotationMatrix)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                glm::quat QG(value[0], value[1], value[2], value[3]);

                Maths::Mat3 MM = QM.ToRotationMatrix();
                glm::mat3 MG = glm::toMat3(QG);

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        COMPARE_WITH_PRECISION(MM[i][j], MG[i][j], Maths::Constants::TOLERANCE);
                    }
                }
            }

            TEST(ToEulerAngles)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };

                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                glm::quat QG(value[0], value[1], value[2], value[3]);

                Maths::Vec3 AM = QM.ToEulerAngles();
                glm::vec3 AQ = glm::eulerAngles(QG);

                COMPARE(AM.x, AQ.x);
                COMPARE(AM.y, AQ.y);
                COMPARE(AM.z, AQ.z);
            }
        }

        NAMESPACE(Assignment and Equality operators)
        {
            TEST(operator negate)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                glm::quat QG(value[0], value[1], value[2], value[3]);

                QM = -QM;
                QG = -QG;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(operator ==)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QA(value[0], value[1], value[2], value[3]);
                Maths::Quat QB(value[0], value[1], value[2], value[3]);
                Maths::Quat QC(value2[0], value2[1], value2[2], value2[3]);
                

                COMPARE(QA == QB, true);
                COMPARE(QA == QC, false);
            }

            TEST(operator !=)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QA(value[0], value[1], value[2], value[3]);
                Maths::Quat QB(value[0], value[1], value[2], value[3]);
                Maths::Quat QC(value2[0], value2[1], value2[2], value2[3]);


                COMPARE(QA != QC, true);
                COMPARE(QA != QB, false);
            }

            TEST(operator [])
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat Q(value[0], value[1], value[2], value[3]);
                glm::quat Q2(value[0], value[1], value[2], value[3]);

                for (int i = 0; i < 4; i++)
                {
                    COMPARE(Q[i], Q2[i]);
                }
            }

        }

        NAMESPACE(Quat to Quat operators)
        {
            TEST(operator +)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                Maths::Quat QM2(value2[0], value2[1], value2[2], value2[3]);
                QM = QM + QM2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                glm::quat QG2(value2[0], value2[1], value2[2], value2[3]);
                QG = QG + QG2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);

            }

            TEST(operator -)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                Maths::Quat QM2(value2[0], value2[1], value2[2], value2[3]);
                QM = QM - QM2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                glm::quat QG2(value2[0], value2[1], value2[2], value2[3]);
                QG = QG - QG2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(operator *)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                Maths::Quat QM2(value2[0], value2[1], value2[2], value2[3]);
                QM = QM * QM2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                glm::quat QG2(value2[0], value2[1], value2[2], value2[3]);
                QG = QG * QG2;

                COMPARE_WITH_PRECISION(QM.w, QG.w, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.x, QG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.y, QG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.z, QG.z, Maths::Constants::TOLERANCE);
            }
        }

        NAMESPACE(Quat to This operators)
        {
            TEST(operator +=)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                Maths::Quat QM2(value2[0], value2[1], value2[2], value2[3]);
                QM += QM2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                glm::quat QG2(value2[0], value2[1], value2[2], value2[3]);
                QG += QG2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);

            }

            TEST(operator -)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                Maths::Quat QM2(value2[0], value2[1], value2[2], value2[3]);
                QM -= QM2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                glm::quat QG2(value2[0], value2[1], value2[2], value2[3]);
                QG -= QG2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(operator *)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                Maths::Quat QM2(value2[0], value2[1], value2[2], value2[3]);
                QM *= QM2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                glm::quat QG2(value2[0], value2[1], value2[2], value2[3]);
                QG *= QG2;

                COMPARE_WITH_PRECISION(QM.w, QG.w, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.x, QG.x, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.y, QG.y, Maths::Constants::TOLERANCE);
                COMPARE_WITH_PRECISION(QM.z, QG.z, Maths::Constants::TOLERANCE);
            }
        }

        NAMESPACE(Scaler to Quat operators)
        {
            TEST(operator *)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2 = RAND_FLOAT;
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                QM = QM * value2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                QG = QG * value2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(operator /)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2 = RAND_FLOAT;
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                QM = QM / value2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                QG = QG / value2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }
        }

        NAMESPACE(Scaler to This operators)
        {
            TEST(operator *=)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2 = RAND_FLOAT;
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                QM *= value2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                QG *= value2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }

            TEST(operator /=)
            {
                float value[4] = { RAND_FLOAT, RAND_FLOAT, RAND_FLOAT, RAND_FLOAT };
                float value2 = RAND_FLOAT;
                Maths::Quat QM(value[0], value[1], value[2], value[3]);
                QM /= value2;

                glm::quat QG(value[0], value[1], value[2], value[3]);
                QG /= value2;

                COMPARE(QM.w, QG.w);
                COMPARE(QM.x, QG.x);
                COMPARE(QM.y, QG.y);
                COMPARE(QM.z, QG.z);
            }
        }
    }
}

int main()
{
    system("cls");
    std::cout << "Library used for the tests : glm\n";
    // IterationValue(1000000);
    IterationValue(10000);
    runTests();
    system("pause");
    return 0;
}