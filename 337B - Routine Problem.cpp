#include <cstdio>

int gcd(int a, int b)
{
    int c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    int ansa, ansb;
    if(b*c >= a*d)
    {
        ansa = b*c - a*d;
        ansb = b*c;
    }
    else
    {
        ansa = a*d - b*c;
        ansb = a*d;
    }

    int ansc = gcd(ansa, ansb);

    printf("%d/%d\n", ansa/ansc, ansb/ansc);

    return 0;
}
