#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int cnt[10];
    for(int i=0; i<10; i++) cnt[i] = 0;
    for(int i=0; i<n; i++)
    {
        int buf;
        scanf("%d", &buf);

        cnt[buf]++;
    }

    int ans[5];
    for(int i=0; i<5; i++) ans[i] = 0;
    bool flag = true;
    for(int i=0; i<n/3; i++)
    {
        if(cnt[4] > 0 && cnt[2] > 0 && cnt[1] > 0)
        {
            ans[0]++;
            cnt[4]--;
            cnt[2]--;
            cnt[1]--;
            continue;
        }
        if(cnt[6] > 0 && cnt[2] > 0 && cnt[1] > 0)
        {
            ans[1]++;
            cnt[6]--;
            cnt[2]--;
            cnt[1]--;
            continue;
        }
        if(cnt[6] > 0 && cnt[3] > 0 && cnt[1] > 0)
        {
            ans[2]++;
            cnt[6]--;
            cnt[3]--;
            cnt[1]--;
            continue;
        }
        flag = false;
        break;
    }

    if(flag == false)
        printf("-1\n");
    else
    {
        for(int i=0; i<ans[0]; i++)
            printf("1 2 4\n");
        for(int i=0; i<ans[1]; i++)
            printf("1 2 6\n");
        for(int i=0; i<ans[2]; i++)
            printf("1 3 6\n");
    }

    return 0;
}
