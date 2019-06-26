#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
const int maxn = 1e5 + 5;
int stations[maxn][5];
int costs[maxn][5];
ll memo[maxn];
bool vis[maxn];
int n;

ll solve(int node) {
  if (node == n - 1) return 0;
  if (vis[node]) return memo[node];
  
  ll res = solve(stations[node][0]) + costs[node][0];

  fors(i, 1, 3)
    res = min(res, solve(stations[node][i]) + costs[node][i]);

  vis[node] = true;
  return memo[node] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s1, s2, s3, c1, c2, c3;

  cin >> n;

  fore(i, n - 1) {
    cin >> s1 >> c1 >> s2 >> c2 >> s3 >> c3;
    --s1; --s2; --s3;
    stations[i][0] = s1;
    stations[i][1] = s2;
    stations[i][2] = s3;

    costs[i][0] = c1;
    costs[i][1] = c2;
    costs[i][2] = c3;
  }

  cout << solve(0) << endl;

  return 0;
}

