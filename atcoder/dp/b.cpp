#include <bits/stdc++.h>
using namespace std;

#define fore(i, n) for(int i = 0; i < n; ++i)
const int MAXN = 1e5 + 5;
int memo[MAXN];
bool vis[MAXN];
int h[MAXN];
int n, k;

int solve(int i) {
  if (i >= n - 1) return 0;
  if (vis[i]) return memo[i];
  
  int res = 2e9;

  for (int j = i + 1; j <= min(i + k, n - 1); ++j)
    res = min(res, solve(j) + abs(h[i] - h[j]));

  vis[i] = true;
  return memo[i] = res;
}

int main() {
  cin >> n >> k;  

  fore(i, n) 
    cin >> h[i];

  cout << solve(0) << endl;
  return 0;
}
