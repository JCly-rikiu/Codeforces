#include <cstdio>
#include <vector>

using namespace std;

int num[1000010];
vector<int> prime;

int main() {
  for (int i = 2; i < 1000010; i++) {
    if (num[i] != 0)
      continue;

    prime.push_back(i);
    for (int j = 2; i * j < 1000010; j++)
      num[i * j] = 1;
  }

  long long n;
  scanf("%I64d", &n);

  vector<long long> buf;
  int now = 0;
  while (n > 1) {
    if (n % prime[now] == 0) {
      buf.push_back(prime[now]);
      while (n % prime[now] == 0) {
        n /= prime[now];
      }
    }
    now++;

    if (now == prime.size()) {
      buf.push_back(n);
      break;
    }
  }

  long long ans = 1;

  for (int i = 0; i != buf.size(); i++) {
    ans *= buf[i];
  }

  printf("%I64d\n", ans);

  return 0;
}