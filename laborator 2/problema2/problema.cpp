#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grades.h"
#include "Globals.h"


using namespace std;

int main()
{
	Grades elev,elev2;
	elev.setEng(10);
	elev.setHist(10);
	elev.setMath(6);
	
	elev2.setEng(10);
	elev2.setHist(10);
	elev2.setMath(9);

	printf("%d", CompHist(elev, elev2));
}