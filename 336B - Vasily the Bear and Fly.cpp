#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int m, r;
    while(cin >> m >> r)
    {
        double ans;
        if(m >= 3)
            ans = ((m-3)*(m-2)*(m-1)/3*2*r + ((m-2)*2 + (m-2)*(m-3))*sqrt(8)*r + 2*m*r + (m-1)*(m-2)*2*r + (m-1)*2*(2+sqrt(2))*r)/m/m;
        else
            ans = (2*m*r + (m-1)*2*(2+sqrt(2))*r)/m/m;

        printf("%.10f\n", ans);
    }

    return 0;
}
