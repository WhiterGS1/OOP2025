#include "header.h"

int Sum(int a, int b) { return a + b; } //float -> int
int Dif(int a, int b) { return a - b; } //char->int
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }//char -> int
//am pus semnele cum trebuie
int main(int argc, char* argv[])
{
    char input[40] = "---H***E+++L+++L///O---P+++O/+-**O---";//vector mai mare
    func Operatori[4] = { Sum, Dif, Mul, Div }; //am eliminat 65 si 0
    int S=0;//initializare s si sters V ( nu era folosit )
    Content x;//x initializat incorect
    int idx;//double -> int

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i] - '*')// (0*) (1+) (3-) (5/)
        {
        case INMULTIRE:
            idx = 2;
            x.p1 = 3;
            x.p2 = 3;
            break;
        case SUMA:
            idx = 0;
            x.p1 = 7;
            x.p2 = 5;
            break;
        case DIFERENTA:
            idx = 1;
            x.p1 = 10;
            x.p2 = 1;
            break;
        case IMPARTIRE:
            idx = 3;
            x.p1 = 8;
            x.p2 = 4;
            break;
        }//am adaugat break la toate case-urile

        S = S + Operatori[idx](x.p1, x.p2);
    }

    //S=337
    printf("S = %d\n", S);//%c -> %d

    return 0;
}
