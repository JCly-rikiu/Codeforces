#include <cstdio>
#include <cstring>

using namespace std;

const int NUM = 200100;

int main() {
  char str[NUM];
  scanf("%s", str);
  
  int m;
  scanf("%d", &m);

  int loc[NUM] = {0};
  for (int i = 0; i != m; ++i) {
    int buf;
    scanf("%d", &buf);
    loc[buf - 1]++;
  }
  
  int len = strlen(str);
  int half = len / 2;
  int cnt = 0;
  for (int i = 0; i != half; ++i) {
    cnt += loc[i];
    cnt = cnt & 1;
    if (cnt == 1) {
      char tmp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = tmp;
    }
  }

  printf("%s\n", str);

  return 0;
}