
#include <cstdio>
#include <cstring>

const int INF = 10000;

int main()
{
    char t[7];
    scanf("%s", t);

    int need[10];
    for(int i=0; i<10; i++) need[i] = 0;

    int lt = strlen(t);
    for(int i=0; i<lt; i++)
        need[t[i]-'0']++;
    need[2] += need[5];
    need[6] += need[9];

    char seq[210];
    scanf("%s", seq);

    int digit[10];
    for(int i=0; i<10; i++) digit[i] = 0;

    int len = strlen(seq);
    for(int i=0; i<len; i++)
        digit[seq[i]-'0']++;
    digit[2] += digit[5];
    digit[6] += digit[9];

    int ans = INF;
    for(int i=0; i<10; i++)
    {
        if(i == 5 || i == 9 || need[i] == 0)
            continue;
        int buf = digit[i]/need[i];
        if(ans > buf)
            ans = buf;
    }
    printf("%d\n", ans);

    return 0;
}
