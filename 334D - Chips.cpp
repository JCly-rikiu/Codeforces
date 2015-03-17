#include <cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    bool row[1010];
    bool col[1010];
    for(int i=0; i<1010; i++) row[i] = col[i] = true;
    row[0] = col[0] = row[n-1] = col[n-1] = false;

    for(int i=0; i<m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        row[x-1] = false;
        col[y-1] = false;
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(i == n-i-1)
        {
            if(row[i] || col[i])
                ans++;
            continue;
        }
        if(row[i])
        {
            ans++;
            row[i] = false;
        }
        if(row[n-i-1])
        {
            ans++;
            row[n-i-1] = false;
        }
        if(col[i])
        {
            ans++;
            col[i] = false;
        }
        if(col[n-i-1])
        {
            ans++;
            col[n-i-1] = false;
        }
    }

    printf("%d\n", ans);

    return 0;
}
