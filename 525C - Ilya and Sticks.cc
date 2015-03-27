#include <cstdio>
#include <algorithm>

using namespace std;

const int NUM = 100010;

int main() {
  int n;
  scanf("%d", &n);

  long long len[NUM];
  for (int i = 0; i != n; ++i) {
    scanf("%I64d", len + i);
  }

  sort(len, len + n);

  int cnt = 0;
  long long ans = 0;
  long long buf = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (len[i] == len[i - 1]) {
      buf *= len[i];
      cnt++;
      --i;
    } else if (len[i] - 1 == len[i - 1]) {
      buf *= len[i - 1];
      cnt++;
      --i;
    }
    if (cnt == 2) {
      ans += buf;
      buf = 1;
      cnt = 0;
    }
  }

  
  printf("%I64d\n", ans);

  return 0;
}