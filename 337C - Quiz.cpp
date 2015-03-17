#include <cstdio>
#include <iostream>
using namespace std;

const int MOD = 1000000009;

long long int kerker(long long int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 2;
    long long int ans;
    if(n % 2 == 1)
    {
        long long int buf = kerker(n/2);
        ans =  buf*buf*2 % MOD;
    }
    else
    {
        long long int buf = kerker(n/2);
        ans =  buf*buf % MOD;
    }
    if(ans - 2 <= 0) return ans + MOD;
    return ans;
}

int main()
{
    long long int n, m, k;
    cin >> n >> m >> k;

    long long int sec = n/k;
    long long int st = n - sec*k;

    long long int ans = 0;
    if(sec*(k-1) + n - sec*k >= m)
        ans = m % MOD;
    else
    {
        long long int remain = m - sec*(k-1);
        long long int len = st + (remain - st) * k;
        ans += len - (len/k)*k;
        ans += (k*((kerker(len/k+1)-2) % MOD)) % MOD;
        ans += m - len;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
