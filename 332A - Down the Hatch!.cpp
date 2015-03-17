#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);

    char seq[2010];
    scanf("%s", seq);

    int ans = 0;
    int len = strlen(seq);
    for(int i=n; i<len; i+=n)
    {
        bool flag = true;
        for(int j=1; j<4; j++)
        {
            if(seq[i-1] != seq[i-j])
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
