#include "Movie.h"

void Movie::set_name(const char* sir) {
	strcpy_s(this->name, 257, sir);
}
void Movie::set_score(float nr) {
	this->score = nr;
}
void Movie::set_year(int nr) {
	this->year = nr;
}
void Movie::set_length(int nr) {
	this->length = nr;
}



char* Movie::get_name(){
	return this->name;
}
float Movie::get_score(){
	return this->score;
}
int Movie::get_year(){
	return this->year;
}
int Movie::get_length(){
	return this->length;
}

int Movie::get_passed_years(){
	return 2026 - this->year;
}