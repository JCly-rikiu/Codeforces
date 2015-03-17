#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int pos[100010];
    pos[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int buf;
        scanf("%d", &buf);

        pos[i + 1] = pos[i] + buf;
    }

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int worm;
        scanf("%d", &worm);

        int ans = lower_bound(pos, pos + n, worm) - pos;
        printf("%d\n", ans);
    }

    return 0;
}