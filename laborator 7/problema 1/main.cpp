#include <cstdio>
#include <stdio.h>


using namespace std;

float operator"" _Kelvin(unsigned long long int val)
{
    return val + 273.15;
}

float operator"" _Fahrenheit(unsigned long long int val)
{
    return val*9/5+32;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("%g %g", a, b);
    return 0;
}