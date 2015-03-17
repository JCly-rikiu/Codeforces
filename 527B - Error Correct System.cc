#include <iostream>
#include <map>
#include <string>

using namespace std;

const int NUM = 26;

int main() {
  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;  

  int cnt = 0;
  map<int, int> location[NUM];
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      location[s1[i] - 'a'][s2[i] - 'a'] = i;
      cnt++;
    }
  }

  int ai = -2, aj = -2;
  bool is_find = false;
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) continue;
    if (location[s2[i] - 'a'].size() > 0) {
      map<int, int>::iterator it = location[s2[i] - 'a'].find(s1[i] - 'a');
      is_find = true;
      if (it != location[s2[i] - 'a'].end()) {
        ai = i;
        aj = it->second;
        cnt--;
        break;
      } else {
        ai = i;
        aj = location[s2[i] - 'a'].begin()->second;
      }
    }
  }
  if (is_find)
    cnt--;

  cout << cnt << endl;
  cout << ai + 1  << " " << aj + 1 << endl;
  
  return 0;
}