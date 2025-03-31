#include "Number.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int Cvt10(const char* value, int base, int digits)
{
	int number = 0;
	int power = 1;
	int digit;
	for (int i = digits - 1; i >= 0; i--)//baseX->base10
	{
		if (base > 10 && value[i] >= 'A')
		{
			digit = value[i] - 'A' + 10;
		}
		else
			digit = value[i] - '0';
		number += digit * power;
		power *= base;
	}
	return number;
}


Number::Number(const char* value, int base)
{
	this->value = new char[32];
	strcpy_s(this->value,32, value);
	this->base = base;
	this->digits = strlen(this->value);
}

Number::~Number()
{
	delete[] value;
}

Number::Number(const Number& number)
{
	this->digits = number.digits;
	this->base = number.base;
	strcpy_s(this->value, sizeof this->value, number.value);
}

Number::Number(const Number&& number)
{
	this->digits = number.digits;
	this->base = number.base;
	strcpy_s(this->value, sizeof this->value, number.value);
}

bool Number::operator>(Number& n1)
{
	int x, y;
	x = Cvt10(this->value,this->base,this->digits);
	y = Cvt10(n1.value, n1.base, n1.digits);
	return x > y;
}

bool Number::operator<(Number& n1)
{
	int x, y;
	x = Cvt10(this->value, this->base, this->digits);
	y = Cvt10(n1.value, n1.base, n1.digits);
	return x <= y;
}

bool Number::operator>=(Number& n1)
{
	int x, y;
	x = Cvt10(this->value, this->base, this->digits);
	y = Cvt10(n1.value, n1.base, n1.digits);
	return x >= y;
}

bool Number::operator<=(Number& n1)
{
	int x, y;
	x = Cvt10(this->value, this->base, this->digits);
	y = Cvt10(n1.value, n1.base, n1.digits);
	return x <= y;
}

bool Number::operator==(Number& n1)
{
	int x, y;
	x = Cvt10(this->value, this->base, this->digits);
	y = Cvt10(n1.value, n1.base, n1.digits);
	return x == y;
}

int operator+(Number& n1, Number& n2)
{
	int x, y;
	x = Cvt10(n2.value, n2.base, n2.digits);
	y = Cvt10(n1.value, n1.base, n1.digits);
	x += y;
	return x;
}

int operator-(Number& n1, Number& n2)
{
	int x, y;
	y = Cvt10(n2.value, n2.base, n2.digits);
	x = Cvt10(n1.value, n1.base, n1.digits);
	x -= y;
	return x;
}

Number& Number::operator--()
{
	int x = Cvt10(this->value, this->base, this->digits);
	x--;
	this->digits = 0;
	int base = this->base;
	this->base = 10;
	while (x != 0)
	{
		this->value[this->digits++] = x % 10 + '0';
		x = x / 10;
	}
	this->value[this->digits] = '\0';
	for (int i = 0; i < this->digits / 2; i++)
	{
		char aux;
		aux = this->value[i];
		this->value[i] = this->value[this->digits - 1 - i];
		this->value[this->digits - 1 - i] = aux;
	}
	this->SwitchBase(base);
	this->base = base;
	return *this;
}

Number Number::operator--(int)
{
	int x = Cvt10(this->value, this->base, this->digits);
	x--;
	this->digits = 0;
	int base = this->base;
	this->base = 10;
	while (x != 0)
	{
		this->value[this->digits++] = x % 10 + '0';
		x = x / 10;
	}
	this->value[this->digits] = '\0';
	for (int i = 0; i < this->digits / 2; i++)
	{
		char aux;
		aux = this->value[i];
		this->value[i] = this->value[this->digits - 1 - i];
		this->value[this->digits - 1 - i] = aux;
	}
	this->SwitchBase(base);
	this->base = base;
	return *this;
}

void Number::SwitchBase(int newBase)
{
	int number = 0;
	int power = 1;
	int digit;
	for (int i=this->digits-1; i>=0; i--)//baseX->base10
	{
		if (this->base > 10 && this->value[i]>='A')
		{
			digit = this->value[i] - 'A' + 10;
		}
		else
			digit = this->value[i] - '0';
		number += digit * power;
		power *= this->base;
	}
	
	this->digits = 0;
	this->base = newBase;
	while (number != 0)
	{
		digit = number % newBase;
		if (digit >= 10)
		{
			this->value[this->digits++] = digit - 10 + 'A';
		}
		else
		{
			this->value[this->digits++] = digit + '0';
		}
		number = number / newBase;
	}
	this->value[this->digits] = '\0';
	for (int i = 0; i < this->digits/2; i++)
	{
		char aux;
		aux = this->value[i];
		this->value[i] = this->value[this->digits - 1 - i];
		this->value[this->digits - 1 - i] = aux;
	}
}

void Number::Print()
{
	printf("%s ", this->value);
}

int Number::GetDigitsCount()
{
	return this->digits;
}

int Number::GetBase()
{
	return this->base;
}

int operator+(Number& n1)
{
	return 0;
}

int operator-(Number& n1)
{
	return 0;
}
