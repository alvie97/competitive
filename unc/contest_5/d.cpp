#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
const int M = 1e9 + 7;

ll add(ll x, ll y) {
  x %= M;
  y %= M;

  return (x + y) % M;
}

int n, k, d;
int memo[105][105][5];
bool vis[105][105][5];

int solve(int sum, int node, bool flag) {
  if (sum > n) return 0;
  if (sum == n && flag) return 1;
  if (vis[sum][node][flag]) return memo[sum][node][flag];

  int res = 0;

  fore(i, k)
    res = add(res, solve(sum + i + 1, i, i + 1 >= d || flag));  


  vis[sum][node][flag] = true;
  return memo[sum][node][flag] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k >> d;

  cout << solve(0, 0, false) << endl;

  return 0;
}

