#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Movie
{
	char name[257];
	float score;
	int year;
	int length;
public:
	void set_name(const char* sir);
	void set_score(float nr);
	void set_year(int nr);
	void set_length(int nr);

	char* get_name();
	float get_score();
	int get_year();
	int get_length();

	int get_passed_years();
};

