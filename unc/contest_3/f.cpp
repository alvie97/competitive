#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int arr[55];  
  int s, n, start, end;
  map<int, set<pair<int, int>>> sums;

  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  for (int i = 0; i < n; ++i) {
    s = 0;
    for (int j = i; j < n; ++j) {
      s += arr[j];
      sums[s].insert({j, i});
    }
  }

  vector<pair<int, int>> ans;

  for (auto it: sums) {
    vector<pair<int, int>> local_ans;
    int end = -1;

    for (auto jt: it.second) {
      if (jt.first > end && jt.second > end) {
        local_ans.push_back(jt);
        end = jt.first;
      }
    }

    if (ans.size() < local_ans.size()) {
      ans = local_ans;
    }
  }

  cout << ans.size() << endl;

  for (auto i: ans)
    cout << i.second + 1 << ' ' << i.first + 1 << endl;

  return 0;
}
