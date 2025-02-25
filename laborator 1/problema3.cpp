#include <iostream>
using namespace std;

bool isPrime(int n)
{
    //trebuia si if(n<2) return false; pentru 1 si 0
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}
