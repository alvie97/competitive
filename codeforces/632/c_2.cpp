#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> arr(n + 1, 0);
  for (int i = 1; i <= n; ++i) 
    cin >> arr[i], arr[i] += arr[i - 1];
  int b = 0, e = 0;
  set<long long> x;
  x.insert(0);
  long long cnt = 0;
  while (b < n) {
    while (e < n && !x.count(arr[e + 1])) {
      x.insert(arr[++e]);
    }
    cnt += e - b;
    x.erase(arr[b++]);
  }
  cout << cnt << '\n';
}
