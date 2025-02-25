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
	while (fgets(sir, sizeof(sir), input))
	{
		for (int i = 0; i < strlen(sir); i++)
		{
			
			if (sir[i] == ' ')
			{
				if (i == 0) continue;
				if(sir[i-1]!=' ')
					printf("\n");
			}
			else
				printf("%c", sir[i]);
		}
	}
	fclose(input);
}