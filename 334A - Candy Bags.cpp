#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    bool flag = true;
    int ans[110][110];
    int now = 1;
    for(int i=0; i<n; i++)
    {
        if(flag == true)
        {
            flag = false;
            for(int j=0; j<n; j++)
                ans[i][j] = now++;
        }
        else
        {
            flag = true;
            for(int j=n-1; j>=0; j--)
                ans[i][j] = now++;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", ans[j][i]);
        printf("\n");
    }

    return 0;
}
