#pragma once
#include <iostream>
#include <stdio.h>
class Number
{
	int base;
	int digits;
	char* value;
public:
	Number() { this->value = new char[32]; this->digits = 0; };
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& number);
	Number(const Number&& number);
	// add operators and copy/move constructor
	bool operator>(Number& n1);
	bool operator<(Number& n1);
	bool operator>=(Number& n1);
	bool operator<=(Number& n1);
	bool operator==(Number& n1);

	friend int operator+(Number& n1,Number& n2);
	friend int operator-(Number& n1,Number& n2);

	Number& operator--();
	Number operator--(int);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};