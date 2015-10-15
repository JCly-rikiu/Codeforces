#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int weight[2000010];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i != n; i++) {
    int buf;
    scanf("%d", &buf);
    weight[buf]++;
  }

  int ans = 0;
  for (int i = 0; i != 2000010; i++) {
    if (weight[i] != 0) {
      if ((weight[i] & 1) == 1)
        ans++;
      
      weight[i + 1] += weight[i] / 2;
    }
  }

  printf("%d\n", ans);

  return 0;
}