#include <cstdio>

const int NUM = 2100;
char apartment[NUM][NUM];
int n, m;


int mx[] = {-1, 0, 1, 0, -1};
int my[] = {0, 1, 0, -1, 0};
int msx[] = {-1, 1, 1, -1};
int msy[] = {1, 1, -1, -1};

bool check(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m)
    return true;
  else
    return false;
}

void dfs(int x, int y) {
  if (apartment[x][y] == '.')
    return ;

  for (int i = 0; i != 4; ++i) {
    int nx = x + mx[i];
    int ny = y + my[i];
    int nsx = x + msx[i];
    int nsy = y + msy[i];
    int nnx = x + mx[i + 1];
    int nny = y + my[i + 1];

    if (!check(nx, ny) || !check(nsx, nsy) || !check(nnx, nny))
      continue;

    if (apartment[nx][ny]   == '.' && 
        apartment[nsx][nsy] == '.' && 
        apartment[nnx][nny] == '.') {
      apartment[x][y] = '.';
      for (int j = 0; j != 4; ++j) {
        int dx = x + mx[j];
        int dy = y + my[j];
        if (check(dx, dy)) {
          dfs(dx, dy);
        }
      }
      for (int j = 0; j != 4; ++j) {
        int dsx = x + msx[j];
        int dsy = y + msy[j];
        if (check(dsx, dsy)) {
          dfs(dsx, dsy);
        }
      }
    }
  }

  return ;
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i != n; ++i)
    scanf("%s", apartment + i);

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      dfs(i, j);
    }
  }

  for(int i = 0; i != n; ++i) {
    printf("%s\n", apartment[i]);
  }

  return 0;
}