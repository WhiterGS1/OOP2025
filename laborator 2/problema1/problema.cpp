#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NumberList.h"


using namespace std;

int main()
{
	NumberList lista;
	lista.Init();
	lista.Add(10);
	lista.Add(11);
	lista.Add(9);
	lista.Print();
	lista.Sort();
	lista.Print();
}