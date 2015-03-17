#include <cstdio>
using namespace std;

int main() {
  long long a, b;
  scanf("%I64d%I64d", &a, &b);

  long long ans = a / b;
  long long c = a - ans * b;
  while(c != 0) {
    a = b;
    b = c;
    long long buf = a / b;
    c = a - buf * b;
    ans += buf;
  }

  printf("%I64d\n", ans);

  return 0;
}