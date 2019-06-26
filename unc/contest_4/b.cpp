#include <bits/stdc++.h>

using namespace std;
#define fore(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;
const int maxn = 2 * 1005;
const int M = 1e9 + 7;
int n;
int memo[maxn][maxn];
int vis[maxn][maxn];

ll add(ll x, ll y) {
  x %= M;
  y %= M;

  return (x + y) % M;
}

int solve(int i, int b) {
  if (i >= n) {
    if (b != 0)
      return 0;
    else
      return 1;
  }
  if (vis[i][b]) return memo[i][b];

  int res = 0;

  if (b == 0)
    res = solve(i + 1, b + 1);

  if (b > 0)
    res = add(solve(i + 1, b + 1), solve(i + 1, b - 1)); 
  vis[i][b] = true;
  return memo[i][b] = res;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  n = 2 * n;

  cout << solve(0, 0) << endl;

  return 0;
}
