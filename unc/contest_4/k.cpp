#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for (int i = 0; i < n; ++i)
#define fors(i, s, n) for (int i = s; i < n; ++i)
const ll INF = 1e10;
int c[105][15];
int d, n;
ll memo[105][15][(1 << 10) + 5];
bool vis[105][15][(1 << 10) + 5];

ll solve(int lamp, int minute, int on)
{
  if (on == (1 << n) - 1)
    return 0;
  if (minute >= d || lamp >= n)
    return -INF;
  if (vis[minute][lamp][on])
    return memo[minute][lamp][on];

  ll res;

  if (on & (1 << lamp))
    res = max(solve(lamp + 1, minute, on), solve(0, minute + 1, on));
  else
  {
    res = max(solve(lamp + 1, minute, on), solve(0, minute + 1, on));
    res = max(res, solve(0, minute + 1, on | (1 << lamp)) + c[minute][lamp]);
  }

  vis[minute][lamp][on] = true;
  return memo[minute][lamp][on] = res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> d >> n;

  fore(i, d)
          fore(j, n)
              cin >> c[i][j];

  cout << solve(0, 0, 0) << endl;

  return 0;
}
