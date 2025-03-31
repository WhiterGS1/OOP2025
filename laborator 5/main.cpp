#include "Number.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FF", 16);
	n1--;
	n1.Print();
}