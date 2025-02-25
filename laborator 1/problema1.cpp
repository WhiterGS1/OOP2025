#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	FILE* input;
	if (fopen_s(&input, "in.txt", "r") != 0) {
		printf("nu exista fisierul\n");
		return 0;
	}
	char sir[200];
	int sum = 0;
	while (fgets(sir, 100, input))
	{
		int nr_cif = 0;
		int x=0;
		for (int i = 0; i < strlen(sir)-1; i++)
		{
			x = x*10 + (sir[i] - '0');
		}
		sum += x;
	}
	fclose(input);
	printf("%d", sum);

}