#include "Math.h"
#include <cstdarg>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a , int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...) // sums up a list of integers
{
	int val, sum = 0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		val = va_arg(vl, int);
		sum += val;
	}
	va_end(vl);
	return sum;
}
char* Math::Add(const char* sir1, const char* sir2)
{
	if (sir1 == nullptr || sir2 == nullptr) return nullptr;
	char* sir3 = new char[128];
	strcpy_s(sir3, 128, sir1);
	int i = 0;
	int j = strlen(sir1);
	while (sir2[i] != NULL)
		sir3[j++] = sir2[i++];
	sir3[j] = NULL;
	return sir3;
}
