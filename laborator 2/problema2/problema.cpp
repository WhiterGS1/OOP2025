#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grades.h"


using namespace std;

int main()
{
	Grades elev;
	elev.setEng(10);
	elev.setHist(10);
	elev.setMath(6);

	printf("%f \n", elev.getAvg());
}