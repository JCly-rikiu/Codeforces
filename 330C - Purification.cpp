#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    char input[110][110];

    for(int i=0; i<n; i++)
        scanf("%s", input+i);

    bool blockr = false;
    for(int i=0; i<n; i++)
    {
        blockr = false;
        for(int j=0; j<n; j++)
        {
            if(input[i][j] == '.')
            {
                blockr = true;
                break;
            }
        }
        if(blockr == false)
            break;
    }

    bool blockc = false;
    for(int i=0; i<n; i++)
    {
        blockc = false;
        for(int j=0; j<n; j++)
        {
            if(input[j][i] == '.')
            {
                blockc = true;
                break;
            }
        }
        if(blockc == false)
            break;
    }

    if(blockr == false && blockc == false)
    {
        printf("-1\n");
        return 0;
    }

    if(blockr == false)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(input[j][i] == '.')
                {
                    printf("%d %d\n", j+1, i+1);
                    break;
                }
            }
        }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(input[i][j] == '.')
                {
                   printf("%d %d\n", i+1, j+1);
                   break;
                }
            }
        }
    }

    return 0;
}
