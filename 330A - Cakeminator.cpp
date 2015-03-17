#include <cstdio>

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);

    char input[15][15];

    for(int i=0; i<r; i++)
        scanf("%s", input[i]);

    int rblank = 0, cblank = 0;
    for(int i=0; i<r; i++)
    {
        bool flag = true;
        for(int j=0; j<c; j++)
        {
            if(input[i][j] == 'S')
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            rblank++;
    }

    for(int i=0; i<c; i++)
    {
        bool flag = true;
        for(int j=0; j<r; j++)
        {
            if(input[j][i] == 'S')
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
            cblank++;
    }

    //printf("%d %d\n", rblank, cblank);

    printf("%d\n", rblank*c + cblank*(r-rblank));

    return 0;
}
