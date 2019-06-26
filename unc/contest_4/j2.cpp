#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for (int i = 0; i < n; ++i)
#define fors(i, s, n) for (int i = s; i < n; ++i)
const int M = 1e9 + 7;

ll add(ll x, ll y)
{
  x %= M;
  y %= M;

  return (x + y) % M;
}

ll sub(ll x, ll y)
{
  x %= M;
  y %= M;

  return (x - y + M) % M;
}

string n;
int d;
int memo[1005][205][5][20];
bool vis[1005][205][5][20];

int solve(int rem, int index, int all, int seven)
{
  if (seven > 17) return 0;
  if (index >= n.size())
    return rem == 0 && seven == 17;
  if (vis[index][rem][all][seven])
    return memo[index][rem][all][seven];

  int res = 0;

  if (all)
  {
    int cur = n[index] - '0';

    fore(i, cur + 1)
        res = add(res, 
          solve((rem + i) % d, index + 1, i == cur, seven + (i == 7)));
  }
  else
  {
    fore(i, 10)
        res = add(res, 
          solve((rem + i) % d, index + 1, 0, seven + (i == 7)));
  }
  
  vis[index][rem][all][seven] = true;
  return memo[index][rem][all][seven] = res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> d;

  cout << sub(solve(0, 0, 1, 0), 1) << endl;

  return 0;
}
