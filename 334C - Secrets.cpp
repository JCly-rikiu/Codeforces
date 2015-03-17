#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int now = 3;
    if(n % now != 0)
        cout << n / now +1 << endl;
    else
    {
        while(n % now == 0 && n >= now) now *= 3;
        cout << n / now + 1;
    }

    return 0;
}
