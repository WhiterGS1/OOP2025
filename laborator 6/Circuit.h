#pragma once
#include "Car.h"
#include "Seat.h"
class Circuit
{
	int length;
	Weather weather;
	Car* cars[20];
	Car* FinishOrder[20];
	Car* DNF[20];
	int count,countFinish,countDNF;
public:
	Circuit() { this->count = 0; this->countFinish = 0; this->countDNF = 0; };
	//~Circuit();
	void AddCar(Car* car);
	void SetWeather(Weather weather);
	void SetLength(int ln);
	void Race();
	void PrintDNF() const;
	void PrintOrder() const;
};

