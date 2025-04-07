#include "Circuit.h"
#include "Car.h"
#include "Seat.h"
#include "Weather.h"




void Circuit::AddCar(Car* car)
{
	this->cars[this->count++] = car;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::SetLength(int ln)
{
	this->length = ln;
}

void Circuit::Race()
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->cars[i]->GetCapacity() < this->cars[i]->GetConsumption() * this->length / 100)
		{
			this->DNF[this->countDNF++] = this->cars[i];
		}
		else
		{
			int ok = 0;
			for (int j = 0; j < this->countFinish; j++)
			{
				if (this->cars[i]->GetTime(this->length, this->weather) < this->cars[j]->GetTime(this->length, this->weather))
				{
					this->countFinish++;
					for (int k = this->countFinish - 1; k > j; k--)
					{
						this->FinishOrder[k] = this->FinishOrder[k - 1];
					}
					this->FinishOrder[j] = this->cars[i];
					ok = 1;
					break;
				}
			}
			if (!ok)
			{
				this->FinishOrder[this->countFinish++] = this->cars[i];
			}
		}
	}
}

void Circuit::PrintDNF() const
{
	for (int i = 0; i < this->countFinish; i++)
	{
		printf("%d. %s\n", i + 1, this->FinishOrder[i]->GetName());
	}
}

void Circuit::PrintOrder() const
{
	for (int i = 0; i < this->countDNF; i++)
	{
		printf("%d. %s\n", i + 1, this->DNF[i]->GetName());
	}
}
