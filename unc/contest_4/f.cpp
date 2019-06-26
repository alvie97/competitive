#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
const int maxn = 5005;
const int maxm = 1005;
int n;
int food[maxn], memo[maxn][maxm];
bool vis[maxn][maxm];

int solve(int day, int last) {
  if (day >= n) return 0;
  if (vis[day][last + 1]) return memo[day][last + 1];

  int res = 0;
  if (last == -1 || food[last] < food[day])
    res = solve(day + 1, day) + 1;

  res = max(res, solve(day + 1, last));

  vis[day][last + 1] = true;
  return memo[day][last + 1] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  fore (i, n)
    cin >> food[i];

  cout << solve(0, -1) << endl;
  return 0;
}
