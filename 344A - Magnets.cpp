#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);

    char fi[3] = "01";
    char se[3] = "10";
    int now = -1;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        char input[3];
        scanf("%s", input);

        int buf;

        if(strcmp(input, fi) == 0)
            buf = 0;
        else
            buf = 1;

        if(now != buf)
        {
            now = buf;
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
