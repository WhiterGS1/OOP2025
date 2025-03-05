#include "MovieSeries.h"

void MovieSeries::init() {
	this->count = 0;
}
void MovieSeries::print() {
	for (int i = 0; i < this->count; i++)
		printf("%s\n%g\n%d\n%d\n", this->series[i]->get_name(), this->series[i]->get_score(), this->series[i]->get_length(), this->series[i]->get_year(), this->series[i]->get_passed_years());
}
void MovieSeries::add(Movie* m) {
	this->series[this->count++] = m;
}
void MovieSeries::sort() {
	int k = 0;
	for (int i = 0; i < this->count-1; i++)
	{
		for (int j = i+1; j < this->count; j++)
		{
			if (this->series[i]->get_passed_years() < this->series[j]->get_passed_years())
			{
				Movie* aux = new Movie;
				aux = this->series[i];
				this->series[i] = this->series[j];
				this->series[j] = aux;
				//delete aux;
				k = 1;
			}
		}
		if (!k) return;
	}
}
