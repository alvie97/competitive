#include <bits/stdc++.h>
using namespace std;

#define fore(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;
const int maxn = 1005;
const int M = 1e9 + 7;
int memo[maxn][maxn];
bool vis[maxn][maxn];
char g[maxn][maxn];
int h, w;

ll add(ll x, ll y) {
  y %= M;
  x %= M;

  return (y + x) % M;
}

int solve(int i, int j) {
  if (i >= h || j >= w) return 0;
  if (i == h - 1 && j == w - 1) return 1;
  if (g[i][j] == '#') return 0;
  if (vis[i][j]) return memo[i][j];

  vis[i][j] = true;
  return memo[i][j] = add(solve(i + 1, j), solve(i, j + 1));
}

int main() {
  cin >> h >> w;

  fore(i, h)
    fore(j, w)
      cin >> g[i][j];

  cout << solve(0, 0) << endl;
  return 0;
}
