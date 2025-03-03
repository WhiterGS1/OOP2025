#include "NumberList.h"


void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	this->numbers[this->count] = x;
	this->count++;
	return false;
}

void NumberList::Sort()
{
	int k = 0;
	for (int i = 0; i < this->count-1; i++)
	{
		k = 0;
		for (int j = i + 1; j < this->count; j++)
		{
			if (this->numbers[i] > this->numbers[j])
			{
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
				k = 1;
			}
		}
		if (!k) return;
	}
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
	{
		printf("%d ", this->numbers[i]);
	}
	printf("\n");
}
