#include "Car.h"
#include "Circuit.h"
#include "Seat.h"
#include <stdio.h>
#include <cstdio>

using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Seat());
	c.Race();
	c.PrintOrder(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.PrintDNF(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}