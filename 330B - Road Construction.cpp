#include <cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    bool node[1010];
    for(int i=0; i<1010; i++) node[i] = true;

    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        node[a] = node[b] = false;
    }

    int ans = 1;
    for(ans; ans<=n; ans++)
        if(node[ans] == true)
            break;

    printf("%d\n", n-1);
    for(int i=1; i<=n; i++)
    {
        if(i == ans) continue;
        printf("%d %d\n", ans, i);
    }

    return 0;
}
