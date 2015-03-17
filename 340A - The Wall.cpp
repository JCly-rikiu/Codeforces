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
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &y, &a, &b);

    int gc = gcd(x, y);

    int num = x * y / gc;

    printf("%d\n", b / num - (a-1) / num);

    return 0;
}
