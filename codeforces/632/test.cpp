#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int, int> > t;
  t.push_back({1, 0});t.push_back({2, 1});t.push_back({3, -1});
  auto it = lower_bound(t.begin(), t.end(), make_pair(2, 2));
  cout << it->first << " " << it->second << '\n';
}
