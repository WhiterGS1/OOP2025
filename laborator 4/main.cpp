#include <stdlib.H>
#include <time.h>
#include <stdio.h>
#include "Sort.h"

using namespace std;

int main()
{
	bool ascendent=false;
	char string[] = "1,8,2,3,9,0";
	Sort list(string);
	list.QuickSort(false);
	list.Print();
	
}
