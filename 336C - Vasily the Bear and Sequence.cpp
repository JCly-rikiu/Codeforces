#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100100;
int input[MAXN];
int bit[32];
vector<int> bitl[32];

void put(int n)
{
    for(int i=0; i<=30; i++)
        if(n & bit[i])
            bitl[i+1].push_back(n);
}

int main()
{
    bit[0] = 1;
    for(int i=1; i<=30; i++)
        bit[i] = bit[i-1] * 2;

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", input+i);
        put(input[i]);
    }

    int ans = 0;
    for(int i=30; i>=1; i--)
    {
        if(bitl[i].size() == 0) continue;
        int now;
        bool first = true;
        for(int j=0; j<bitl[i].size(); j++)
        {
            if(first)
            {
                now = bitl[i][j];
                first = false;
                continue;
            }
            now = now & bitl[i][j];
        }
        if(now == (now & ~(bit[i-1]-1)))
        {
            ans = i;
            break;
        }
    }

    if(ans > 0)
    {
        printf("%d\n", bitl[ans].size());
        sort(bitl[ans].begin(), bitl[ans].begin()+bitl[ans].size());
        for(int i=0; i<bitl[ans].size(); i++)
            printf("%d ", bitl[ans][i]);
        printf("\n");
    }
    else
        printf("-1\n");



    return 0;
}
