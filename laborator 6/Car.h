#pragma once
#include <cstdio>
#include <stdio.h>
#include "Weather.h"

class Car
{
	
protected:
	int Capacity;
	int Consumption;

	int SpeedRain;
	int SpeedSunny;
	int SpeedSnow;

	const char* name;
public:
	virtual ~Car() = default;
	virtual int GetCapacity() const = 0;
	virtual int GetConsumption() const = 0;
	virtual int GetSpeed(Weather weather) const = 0;
	virtual double GetTime(int distance, Weather weather) const = 0;
	virtual const char* GetName() const = 0;
};

