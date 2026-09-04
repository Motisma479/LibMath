/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Last Update : 01/09/2026                      *
\***********************************************/
#pragma once

#define METRIC_PREFIX_DECLARATION(unit) \
inline constexpr long double operator""_Q##unit##(long double value);\
inline constexpr long double operator""_R##unit##(long double value);\
inline constexpr long double operator""_Y##unit##(long double value);\
inline constexpr long double operator""_Z##unit##(long double value);\
inline constexpr long double operator""_E##unit##(long double value);\
inline constexpr long double operator""_P##unit##(long double value);\
inline constexpr long double operator""_T##unit##(long double value);\
inline constexpr long double operator""_G##unit##(long double value);\
inline constexpr long double operator""_M##unit##(long double value);\
inline constexpr long double operator""_k##unit##(long double value);\
inline constexpr long double operator""_h##unit##(long double value);\
inline constexpr long double operator""_da##unit##(long double value);\
inline constexpr long double operator""_##unit##(long double value);\
inline constexpr long double operator""_d##unit##(long double value);\
inline constexpr long double operator""_c##unit##(long double value);\
inline constexpr long double operator""_m##unit##(long double value);\
inline constexpr long double operator""_u##unit##(long double value);\
inline constexpr long double operator""_n##unit##(long double value);\
inline constexpr long double operator""_p##unit##(long double value);\
inline constexpr long double operator""_f##unit##(long double value);\
inline constexpr long double operator""_a##unit##(long double value);\
inline constexpr long double operator""_z##unit##(long double value);\
inline constexpr long double operator""_y##unit##(long double value);\
inline constexpr long double operator""_r##unit##(long double value);\
inline constexpr long double operator""_q##unit##(long double value);


namespace Maths::SI
{
    //from base to (sub)multiple
    
    //Submuliples
    inline constexpr long double ToDeci(long double value);
    inline constexpr long double ToCenti(long double value);
    inline constexpr long double ToMilli(long double value);
    inline constexpr long double ToMicro(long double value);
    inline constexpr long double ToNano(long double value);
    inline constexpr long double ToPico(long double value);
    inline constexpr long double ToFemto(long double value);
    inline constexpr long double ToAtto(long double value);
    inline constexpr long double ToZepto(long double value);
    inline constexpr long double ToYocto(long double value);
    inline constexpr long double ToRonto(long double value);
    inline constexpr long double ToQuecto(long double value);
    
    //Multiples
    inline constexpr long double ToDeca(long double value);
    inline constexpr long double ToHecto(long double value);
    inline constexpr long double ToKilo(long double value);
    inline constexpr long double ToMega(long double value);
    inline constexpr long double ToGiga(long double value);
    inline constexpr long double ToTera(long double value);
    inline constexpr long double ToPeta(long double value);
    inline constexpr long double ToExa(long double value);
    inline constexpr long double ToZetta(long double value);
    inline constexpr long double ToYota(long double value);
    inline constexpr long double ToRonna(long double value);
    inline constexpr long double ToQuetta(long double value);
    
    //from (sub)multiple to base

    //Submuliples
    inline constexpr long double FromDeci(long double value);
    inline constexpr long double FromCenti(long double value);
    inline constexpr long double FromMilli(long double value);
    inline constexpr long double FromMicro(long double value);
    inline constexpr long double FromNano(long double value);
    inline constexpr long double FromPico(long double value);
    inline constexpr long double FromFemto(long double value);
    inline constexpr long double FromAtto(long double value);
    inline constexpr long double FromZepto(long double value);
    inline constexpr long double FromYocto(long double value);
    inline constexpr long double FromRonto(long double value);
    inline constexpr long double FromQuecto(long double value);
    
    //Multiples
    inline constexpr long double FromDeca(long double value);
    inline constexpr long double FromHecto(long double value);
    inline constexpr long double FromKilo(long double value);
    inline constexpr long double FromMega(long double value);
    inline constexpr long double FromGiga(long double value);
    inline constexpr long double FromTera(long double value);
    inline constexpr long double FromPeta(long double value);
    inline constexpr long double FromExa(long double value);
    inline constexpr long double FromZetta(long double value);
    inline constexpr long double FromYota(long double value);
    inline constexpr long double FromRonna(long double value);
    inline constexpr long double FromQuetta(long double value);

    //the base unit for length is the metre (m)
    namespace Length
    {

        inline constexpr long double ToAstronomicalUnit(long double valueMetre);

        inline constexpr long double FromAstronomicalUnit(long double valueAstronomicalUnit);

        //Imperial Conversion
        inline constexpr long double ToInch(long double valueMetre);
        inline constexpr long double ToFoot(long double valueMetre);
        inline constexpr long double ToYard(long double valueMetre);
        inline constexpr long double ToMile(long double valueMetre);

        inline constexpr long double FromInch(long double valueInch);
        inline constexpr long double FromFoot(long double valueFoot);
        inline constexpr long double FromYard(long double valueYard);
        inline constexpr long double FromMile(long double valueMile);

        namespace Literals
        {
            METRIC_PREFIX_DECLARATION(m)

            //Astronomical unit ( x * 149597870700)
            inline constexpr long double operator""_au(long double value);

            inline constexpr long double operator""_in(long double value);
            inline constexpr long double operator""_ft(long double value);
            inline constexpr long double operator""_yd(long double value);
            inline constexpr long double operator""_mi(long double value);
        }
    }

    //the base unit for mass is the kilogram (kg)
    namespace Mass
    {
        //Imperial Conversion
        inline constexpr long double ToPound(long double valueKilogram);
        inline constexpr long double ToOunce(long double valueKilogram);

        inline constexpr long double FromPound(long double valuePound);
        inline constexpr long double FromOunce(long double valueOunce);

        namespace Literals
        {
            // /!\ since the base unit is the kilogram, 1 gram == 0.yea001 

            METRIC_PREFIX_DECLARATION(g)

            inline constexpr long double operator""_lb(long double value);
            inline constexpr long double operator""_oz(long double value);
        }
    }

    //the base unit for electric current is the ampere (A)
    namespace ElectricCurrent
    {

    }

    //the base unit for temperature is the kelvin K
    namespace Temperature
    {

        inline constexpr long double ToCelsius(long double valueKelvin);
        inline constexpr long double ToFahrenheit(long double valueKelvin);

        inline constexpr long double FromCelsius(long double valueCelsius);
        inline constexpr long double FromFahrenheit(long double valueFahrenheit);
        
        namespace Literals
        {
            METRIC_PREFIX_DECLARATION(K)

            //Celsius ( x + 273.15)
            inline constexpr long double operator""_C(long double value);

            //Fahrenheit ( (x - 273.15) * 9/5 + 32 )
            inline constexpr long double operator""_F(long double value);
        }
    }

    //the base unit for amount of substance is the mole (mol)
    namespace AmountOfSubstance
    {

    }

    //the base unit for luminous intensity is the candela (cd)
    namespace LuminousItensity
    {

    }
}

#include "MathsInternationalSystemOfUnits.inl"