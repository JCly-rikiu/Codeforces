#include <iostream>
#include <set>

using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;

  set<int> wl, hl;
  wl.insert(0);
  wl.insert(w);
  hl.insert(0);
  hl.insert(h);

  multiset<int> wm, hm;
  wm.insert(w);
  hm.insert(h);

  while (n--) {
    char way;
    int pos;
    cin >> way >> pos;

    set<int>::iterator it, l, r;
    multiset<int>::iterator mit;
    int gap;
    switch (way) {
      case 'H':
        r = it = hl.lower_bound(pos);
        it--;
        l = it;
        gap = *r - *l;
        
        mit = hm.find(gap);
        hm.erase(mit);
        hm.insert(*r - pos);
        hm.insert(pos - *l);

        hl.insert(pos);

        break;
      case 'V':
        r = it = wl.lower_bound(pos);
        it--;
        l = it;
        gap = *r - *l;

        mit = wm.find(gap);
        wm.erase(mit);
        wm.insert(*r - pos);
        wm.insert(pos - *l);

        wl.insert(pos);

        break;
    }

    cout << static_cast<long long>(*hm.rbegin()) * (*wm.rbegin()) << endl;
  }

  return 0;
}