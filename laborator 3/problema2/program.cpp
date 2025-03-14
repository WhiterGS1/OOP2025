#include "Canvas.h"
#include <string.h>
using namespace std;

int main()
{
	Canvas tablou;
	tablou.FillRect(3, 3, 8, 8, 'O');
	tablou.Print();

}