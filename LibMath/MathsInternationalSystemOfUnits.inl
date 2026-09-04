/***********************************************\
* Made by : Motisma479                          *
* GitHub : https://github.com/Motisma479        *
* License : MIT license                         *
* Last Update : 01/09/2026                      *
\***********************************************/
#include "MathsInternationalSystemOfUnits.hpp"

#define METRIC_PREFIX_DEFINITION(namespace, unit) \
inline constexpr long double namespace##::operator""_Q##unit##(long double value) {return Maths::SI::FromQuetta(value);} \
inline constexpr long double namespace##::operator""_R##unit##(long double value) {return Maths::SI::FromRonna(value);} \
inline constexpr long double namespace##::operator""_Y##unit##(long double value) {return Maths::SI::FromYota(value);} \
inline constexpr long double namespace##::operator""_Z##unit##(long double value) {return Maths::SI::FromZetta(value);} \
inline constexpr long double namespace##::operator""_E##unit##(long double value) {return Maths::SI::FromExa(value);} \
inline constexpr long double namespace##::operator""_P##unit##(long double value) {return Maths::SI::FromPeta(value);} \
inline constexpr long double namespace##::operator""_T##unit##(long double value) {return Maths::SI::FromTera(value);} \
inline constexpr long double namespace##::operator""_G##unit##(long double value) {return Maths::SI::FromGiga(value);} \
inline constexpr long double namespace##::operator""_M##unit##(long double value) {return Maths::SI::FromMega(value);} \
inline constexpr long double namespace##::operator""_k##unit##(long double value) {return Maths::SI::FromKilo(value);} \
inline constexpr long double namespace##::operator""_h##unit##(long double value) {return Maths::SI::FromHecto(value);} \
inline constexpr long double namespace##::operator""_da##unit##(long double value) {return Maths::SI::FromDeca(value);} \
inline constexpr long double namespace##::operator""_##unit##(long double value) {return value;} \
inline constexpr long double namespace##::operator""_d##unit##(long double value) {return Maths::SI::FromDeci(value);} \
inline constexpr long double namespace##::operator""_c##unit##(long double value) {return Maths::SI::FromCenti(value);} \
inline constexpr long double namespace##::operator""_m##unit##(long double value) {return Maths::SI::FromMilli(value);} \
inline constexpr long double namespace##::operator""_u##unit##(long double value) {return Maths::SI::FromMicro(value);} \
inline constexpr long double namespace##::operator""_n##unit##(long double value) {return Maths::SI::FromNano(value);} \
inline constexpr long double namespace##::operator""_p##unit##(long double value) {return Maths::SI::FromPico(value);} \
inline constexpr long double namespace##::operator""_f##unit##(long double value) {return Maths::SI::FromFemto(value);} \
inline constexpr long double namespace##::operator""_a##unit##(long double value) {return Maths::SI::FromAtto(value);} \
inline constexpr long double namespace##::operator""_z##unit##(long double value) {return Maths::SI::FromZepto(value);} \
inline constexpr long double namespace##::operator""_y##unit##(long double value) {return Maths::SI::FromYocto(value);} \
inline constexpr long double namespace##::operator""_r##unit##(long double value) {return Maths::SI::FromRonto(value);} \
inline constexpr long double namespace##::operator""_q##unit##(long double value) {return Maths::SI::FromQuecto(value);}

//from base to (sub)multiple
    
//Submuliples
inline constexpr long double ToDeci(long double value)  {return value * 10;}
inline constexpr long double ToCenti(long double value) {return value * 100;}
inline constexpr long double ToMilli(long double value) {return value * 1000;}
inline constexpr long double ToMicro(long double value) {return value * 10000;}
inline constexpr long double ToNano(long double value)  {return value * 100000;}
inline constexpr long double ToPico(long double value)  {return value * 1000000;}
inline constexpr long double ToFemto(long double value) {return value * 10000000;}
inline constexpr long double ToAtto(long double value)  {return value * 100000000;}
inline constexpr long double ToZepto(long double value) {return value * 1000000000;}
inline constexpr long double ToYocto(long double value) {return value * 10000000000;}
inline constexpr long double ToRonto(long double value) {return value * 100000000000;}
inline constexpr long double ToQuecto(long double value){return value * 1000000000000;}

//Multiples
inline constexpr long double ToDeca(long double value)  {return value / 10;}
inline constexpr long double ToHecto(long double value) {return value / 100;}
inline constexpr long double ToKilo(long double value)  {return value / 1000;}
inline constexpr long double ToMega(long double value)  {return value / 10000;}
inline constexpr long double ToGiga(long double value)  {return value / 100000;}
inline constexpr long double ToTera(long double value)  {return value / 1000000;}
inline constexpr long double ToPeta(long double value)  {return value / 10000000;}
inline constexpr long double ToExa(long double value)   {return value / 100000000;}
inline constexpr long double ToZetta(long double value) {return value / 1000000000;}
inline constexpr long double ToYota(long double value)  {return value / 10000000000;}
inline constexpr long double ToRonna(long double value) {return value / 100000000000;}
inline constexpr long double ToQuetta(long double value){return value / 1000000000000;}

//from (sub)multiple to base

//Submuliples
inline constexpr long double Maths::SI::FromDeci(long double value)  {return value / 10;}
inline constexpr long double Maths::SI::FromCenti(long double value) {return value / 100;}
inline constexpr long double Maths::SI::FromMilli(long double value) {return value / 1000;}
inline constexpr long double Maths::SI::FromMicro(long double value) {return value / 10000;}
inline constexpr long double Maths::SI::FromNano(long double value)  {return value / 100000;}
inline constexpr long double Maths::SI::FromPico(long double value)  {return value / 1000000;}
inline constexpr long double Maths::SI::FromFemto(long double value) {return value / 10000000;}
inline constexpr long double Maths::SI::FromAtto(long double value)  {return value / 100000000;}
inline constexpr long double Maths::SI::FromZepto(long double value) {return value / 1000000000;}
inline constexpr long double Maths::SI::FromYocto(long double value) {return value / 10000000000;}
inline constexpr long double Maths::SI::FromRonto(long double value) {return value / 100000000000;}
inline constexpr long double Maths::SI::FromQuecto(long double value){return value / 1000000000000;}

//Multiples
inline constexpr long double Maths::SI::FromDeca(long double value)  {return value * 10;}
inline constexpr long double Maths::SI::FromHecto(long double value) {return value * 100;}
inline constexpr long double Maths::SI::FromKilo(long double value)  {return value * 1000;}
inline constexpr long double Maths::SI::FromMega(long double value)  {return value * 10000;}
inline constexpr long double Maths::SI::FromGiga(long double value)  {return value * 100000;}
inline constexpr long double Maths::SI::FromTera(long double value)  {return value * 1000000;}
inline constexpr long double Maths::SI::FromPeta(long double value)  {return value * 10000000;}
inline constexpr long double Maths::SI::FromExa(long double value)   {return value * 100000000;}
inline constexpr long double Maths::SI::FromZetta(long double value) {return value * 1000000000;}
inline constexpr long double Maths::SI::FromYota(long double value)  {return value * 10000000000;}
inline constexpr long double Maths::SI::FromRonna(long double value) {return value * 100000000000;}
inline constexpr long double Maths::SI::FromQuetta(long double value){return value * 1000000000000;}


#pragma region Length

inline constexpr long double Maths::SI::Length::ToAstronomicalUnit(long double valueMetre) {return valueMetre / 149597870700;}

inline constexpr long double Maths::SI::Length::FromAstronomicalUnit(long double valueAstronomicalUnit) {return valueAstronomicalUnit * 149597870700;}

inline constexpr long double Maths::SI::Length::ToInch(long double valueMetre) {return valueMetre * (5000.0 / 127.0);}
inline constexpr long double Maths::SI::Length::ToFoot(long double valueMetre) {return valueMetre * (5000.0 / 1524.0);}
inline constexpr long double Maths::SI::Length::ToYard(long double valueMetre) {return valueMetre * (1250.0 / 1143.0);}
inline constexpr long double Maths::SI::Length::ToMile(long double valueMetre) {return valueMetre * (201168.0 / 125.0);}

inline constexpr long double Maths::SI::Length::FromInch(long double valueInch) {return valueInch * (127.0 / 5000.0);}
inline constexpr long double Maths::SI::Length::FromFoot(long double valueFoot) {return valueFoot * (1524.0 / 5000.0);}
inline constexpr long double Maths::SI::Length::FromYard(long double valueYard) {return valueYard * (1143.0 / 1250.0);}
inline constexpr long double Maths::SI::Length::FromMile(long double valueMile) {return valueMile * (125.0 / 201168.0);}

#pragma region Length_Literals

METRIC_PREFIX_DEFINITION(Maths::SI::Length::Literals,m)

inline constexpr long double Maths::SI::Length::Literals::operator""_au(long double value) {return FromAstronomicalUnit(value);}

inline constexpr long double Maths::SI::Length::Literals::operator""_in(long double value) {return FromInch(value);}
inline constexpr long double Maths::SI::Length::Literals::operator""_ft(long double value) {return FromFoot(value);}
inline constexpr long double Maths::SI::Length::Literals::operator""_yd(long double value) {return FromYard(value);}
inline constexpr long double Maths::SI::Length::Literals::operator""_mi(long double value) {return FromMile(value);}
     
#pragma endregion Length_Literals

#pragma endregion Length

//------------------------------------------------------------------

#pragma region Mass

inline constexpr long double Maths::SI::Mass::ToPound(long double valueKilogram)
{
    return valueKilogram / 0.45359237;
}
inline constexpr long double Maths::SI::Mass::ToOunce(long double valueKilogram)
{
    return valueKilogram / 0.028349523125;
}

inline constexpr long double Maths::SI::Mass::FromPound(long double valuePound)
{
    return valuePound * 0.45359237;
}
inline constexpr long double Maths::SI::Mass::FromOunce(long double valueOunce)
{
    return valueOunce * 0.028349523125;
}

#pragma region Mass_Literals

inline constexpr long double Maths::SI::Mass::Literals::operator""_Qg(long double value) {return Maths::SI::FromZetta(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Rg(long double value) {return Maths::SI::FromExa(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Yg(long double value) {return Maths::SI::FromPeta(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Zg(long double value) {return Maths::SI::FromTera(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Eg(long double value) {return Maths::SI::FromGiga(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Pg(long double value) {return Maths::SI::FromMega(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Tg(long double value) {return Maths::SI::FromKilo(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Gg(long double value) {return Maths::SI::FromHecto(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_Mg(long double value) {return Maths::SI::FromDeca(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_kg(long double value) {return value;}//<-- Base Unit
inline constexpr long double Maths::SI::Mass::Literals::operator""_hg(long double value) {return Maths::SI::FromDeci(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_dag(long double value) {return Maths::SI::FromCenti(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_g(long double value) {return Maths::SI::FromMilli(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_dg(long double value) {return Maths::SI::FromMicro(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_cg(long double value) {return Maths::SI::FromNano(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_mg(long double value) {return Maths::SI::FromPico(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_ug(long double value) {return Maths::SI::FromFemto(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_ng(long double value) {return Maths::SI::FromAtto(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_pg(long double value) {return Maths::SI::FromZepto(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_fg(long double value) {return Maths::SI::FromYocto(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_ag(long double value) {return Maths::SI::FromRonto(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_zg(long double value) {return Maths::SI::FromQuecto(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_yg(long double value) {return value / 10000000000000;}
inline constexpr long double Maths::SI::Mass::Literals::operator""_rg(long double value) {return value / 100000000000000;}
inline constexpr long double Maths::SI::Mass::Literals::operator""_qg(long double value) {return value / 1000000000000000;}

inline constexpr long double Maths::SI::Mass::Literals::operator""_lb(long double value) {return FromPound(value);}
inline constexpr long double Maths::SI::Mass::Literals::operator""_oz(long double value) {return FromOunce(value);}

#pragma endregion Mass_Literals

#pragma endregion Mass

//------------------------------------------------------------------

#pragma region Temperature

inline constexpr long double Maths::SI::Temperature::ToCelsius(long double valueKelvin) {return valueKelvin - 273.15;}
inline constexpr long double Maths::SI::Temperature::ToFahrenheit(long double valueKelvin) {return (valueKelvin - 273.15) * 9/5 + 32;}

inline constexpr long double Maths::SI::Temperature::FromCelsius(long double valueCelsius) {return valueCelsius + 273.15; }
inline constexpr long double Maths::SI::Temperature::FromFahrenheit(long double valueFahrenheit) {return (valueFahrenheit - 32) * 5/9 + 273.15;}

#pragma region Temperature_Literals

METRIC_PREFIX_DEFINITION(Maths::SI::Temperature::Literals,K)

inline constexpr long double Maths::SI::Temperature::Literals::operator""_C(long double value) {return FromCelsius(value);}

inline constexpr long double Maths::SI::Temperature::Literals::operator""_F(long double value) {return ToFahrenheit(value);}
     
#pragma endregion Literals

#pragma endregion Temperature