#pragma once
#include "Movie.h"

class MovieSeries
{
	Movie* series[16];
	int count;
public:
	void init();
	void add(Movie* m);
	void print();
	void sort();
};

