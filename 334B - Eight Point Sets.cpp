#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
    int x;
    int y;
};

int main()
{
    point pset[10];
    for(int i=0; i<8; i++)
        scanf("%d%d", &pset[i].x, &pset[i].y);

    vector<int> x;
    vector<int> y;
    for(int i=0; i<8; i++)
    {
        bool put = true;
        for(int j=0; j<x.size(); j++)
        {
            if(pset[i].x == x[j])
            {
                put = false;
                break;
            }
        }
        if(put)
            x.push_back(pset[i].x);
        put = true;
        for(int j=0; j<y.size(); j++)
        {
            if(pset[i].y == y[j])
            {
                put = false;
                break;
            }
        }
        if(put)
            y.push_back(pset[i].y);
    }

    sort(x.begin(), x.begin()+x.size());
    sort(y.begin(), y.begin()+y.size());

    if(x.size() != 3 || y.size() != 3)
        printf("ugly\n");
    else
    {
        int check = 0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
            {
                if(i == 1 && j == 1)
                    continue;
                for(int k=0; k<8; k++)
                    if(pset[k].x == x[i] && pset[k].y == y[j])
                    {
                        check++;
                        break;
                    }
            }
        if(check == 8)
            printf("respectable\n");
        else
            printf("ugly\n");
    }


    return 0;
}
