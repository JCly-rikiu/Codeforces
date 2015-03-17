#include <cstdio>

int num[20];
int tree[18][140000];

int main()
{
    num[0] = 1;
    for(int i=1; i<20; i++)
        num[i] = num[i-1] * 2;

    int n, m;
    scanf("%d%d", &n, &m);

    for(int i=0; i<num[n]; i++)
        scanf("%d", &tree[n][i]);

    int state = n % 2;

    for(int i=n-1; i>=0; i--)
        for(int j=0; j<num[i]; j++)
            if(i % 2 == state)
                tree[i][j] = tree[i+1][j*2] ^ tree[i+1][j*2+1];
            else
                tree[i][j] = tree[i+1][j*2] | tree[i+1][j*2+1];

    for(int i=0; i<m; i++)
    {
        int p, b;
        scanf("%d%d", &p, &b);

        tree[n][p-1] = b;
        int now = p-1;
        for(int j=n-1; j>=0; j--)
        {
            now = now/2;
            if(j % 2 == state)
                tree[j][now] = tree[j+1][now*2] ^ tree[j+1][now*2+1];
            else
                tree[j][now] = tree[j+1][now*2] | tree[j+1][now*2+1];
        }

        printf("%d\n", tree[0][0]);
    }

    return 0;
}
