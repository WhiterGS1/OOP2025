#include "Math.h"
#include <string.h>
using namespace std;

int main()
{
	char* sir1 = new char[64];
	char* sir2 = new char[64];
	char* sir3 = new char[128];

	strcpy_s(sir1, 64, "Ana are mere");
	strcpy_s(sir2, 64, "dar nu are pere");

	sir3=Math::Add(sir1, sir2);
	printf("%s", sir3);
}