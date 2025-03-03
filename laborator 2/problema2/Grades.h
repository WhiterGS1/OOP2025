#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Grades
{
	char nume[20];
	int math, eng, hist;
public:
	void setMath(int nr);
	void setEng(int nr);
	void setHist(int nr);
	void setNume(char* sir);

	int getMath();
	int getEng();
	int getHist();
	
	char* getNume();

	float getAvg();
};

