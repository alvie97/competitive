#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
const int maxn = 5005;
const ll INF = 1e9 * maxn + 5;
int n, m;
ll p[maxn];
ll memo[maxn][maxn];
bool vis[maxn][maxn];

ll solve(int i, int k) {
  if (k <= 0) return 0;
  if (i >= n) return -INF;
  if (i + m - 1 >= n) return -INF;
  if (vis[i][k]) return memo[i][k];

  ll res = max(solve(i + m, k - 1) + p[i + m] - p[i], 
    solve(i + 1, k));

  vis[i][k] = true;
  return memo[i][k] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;

  cin >> n >> m >> k;

  fore(i, n)
    cin >> p[i + 1];

  fors(i, 1, n + 1)
    p[i] = p[i] + p[i - 1];

  cout << solve(0, k) << endl;

  return 0;
}

