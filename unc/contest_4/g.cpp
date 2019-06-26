#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
typedef long long ll;
const int maxn = 105;
const int maxm = 15;
const int M = 1e8;
int f, h, kf, kh;
int memo[maxn][maxn][maxm][maxm];
bool vis[maxn][maxn][maxm][maxm];

ll add(ll x, ll y) {
  x %= M;
  y %= M;
  return (x + y) % M;
}

int solve(int f_m, int h_m, int f_s, int h_s) {
  if (f_m < 0 || h_m < 0) return 0;
  if (f_s > kf || h_s > kh) return 0;
  if (f_m == 0 && h_m == 0) return 1;

  if (vis[f_m][h_m][f_s][h_s]) return memo[f_m][h_m][f_s][h_s];

  int res = add(solve(f_m - 1, h_m, f_s + 1, 0), solve(f_m, h_m - 1, 0, h_s + 1));

  vis[f_m][h_m][f_s][h_s] = true;
  return memo[f_m][h_m][f_s][h_s] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> f >> h >> kf >> kh;

  cout << solve(f, h, 0, 0) << endl;

  return 0;
}

