#include "Grades.h"

void Grades::setMath(int nr)
{
	this->math = nr;
}
void Grades::setEng(int nr)
{
	this->eng = nr;
}
void Grades::setHist(int nr)
{
	this->hist = nr;
}
void Grades::setNume(char* sir)
{
	strcpy_s(this->nume, 20, sir);
}


int Grades::getMath()
{
	return this->math;
}
int Grades::getEng()
{
	return this->eng;
}
int Grades::getHist()
{
	return this->hist;
}


float Grades::getAvg()
{
	return (float)(this->math + this->eng + this->hist) / 3;
}
