#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int ans = 0;
  int now = 110;
  for (int i = 0; i != n; i++) {
    int a, p;
    scanf("%d%d", &a, &p);

    if (now > p)
      now = p;
    ans += now * a;
  }

  printf("%d\n", ans);

  return 0;
}