#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  long long n, cnt = 0;
  cin >> n;
  long long arr[n + 5];
  pair<long long, int> sorted[n + 5];
  arr[0] = 0;
  for (int i = 1; i <= n; ++i) cin >> arr[i], arr[i] += arr[i - 1];
  ++n;
  for (int i = 0; i < n; ++i) 
    sorted[i].first = arr[i], sorted[i].second = i;
  sort(sorted, sorted + n);
  for (int i = 0; i < n - 1; ++i) {
    cnt += sorted[i].first == sorted[i + 1].first 
      ? sorted[i + 1].second - 1 - sorted[i].second
      : n - sorted[i].second - 1;
  }
  cnt += n - sorted[n - 1].second - 1;
  cout << cnt << '\n';
  return 0;
}
