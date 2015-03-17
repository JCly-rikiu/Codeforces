#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> puzzle;

    for(int i=0; i<m; i++)
    {
        int f;
        scanf("%d", &f);
        puzzle.push_back(f);
    }

    sort(puzzle.begin(), puzzle.end());

    int ans = INF;
    for(int i=0; i+n-1<puzzle.size(); i++)
        if(puzzle[i+n-1] - puzzle[i] < ans)
            ans = puzzle[i+n-1] - puzzle[i];

    printf("%d\n", ans);

    return 0;
}
