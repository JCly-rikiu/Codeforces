#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    long long int a, b;
    cin >> a >> b;

    if(a < b)
    {
        long long int c = a;
        a = b;
        b = c;
    }

    long long int ans = 0;
    while(1)
    {
        ans += a / b;
        a = a % b;

        if(a == 0)
            break;

        long long int c = a;
        a = b;
        b = c;
    }

    cout << ans << endl;

    return 0;
}
