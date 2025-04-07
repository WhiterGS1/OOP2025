#include "Seat.h"
#include "Car.h"
#include "Seat.h"

Seat::Seat()
{
	Capacity=100;
	Consumption=10;

	SpeedRain=40;
	SpeedSunny=60;
	SpeedSnow=30;

	name="Seat";
}

int Seat::GetCapacity() const
{
	return Capacity;
}

int Seat::GetConsumption() const
{
	return Consumption;
}

int Seat::GetSpeed(Weather weather) const
{
	switch (weather) {
	case Weather::Rain:{ return SpeedRain; }
	case Weather::Snow:{ return SpeedSnow; }
	case Weather::Sunny:{ return SpeedSunny; }
	};
}

const char* Seat::GetName() const
{
	return name;
}

double Seat::GetTime(int distance, Weather weather) const
{
	return distance/GetSpeed(weather);
}
