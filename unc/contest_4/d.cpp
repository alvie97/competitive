#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 5005;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)

int n;
int memo[maxn];
int h[maxn];
bool vis[maxn];

int solve(int i) {
  if (i >= n - 1) return 0;
  if (vis[i]) return memo[i];

  int res = INF;

  fors(j, i + 1, min(n, i + h[i]))
    res = min(res, solve(j) + 1);

  vis[i] = true;
  return memo[i] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  fore(i, n)
    cin >> h[i];

  int ans = solve(0);

  cout << (ans >= INF ? -1 : ans) << endl;

  return 0;
}

