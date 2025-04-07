#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	int GetCapacity() const override;
	int GetConsumption() const override;
	int GetSpeed(Weather weather) const override;
	const char* GetName() const override;
	virtual double GetTime(int distance, Weather weather) const override;
	//~Seat();
};

