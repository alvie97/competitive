#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5005;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
int c[maxn];
ll memo[maxn];
bool vis[maxn];

ll solve(int l) {
  if (l <= 0) return 0;
  if (vis[l]) return memo[l];

  ll res = 0;

  fore(i, l)
    res = max(res, solve(l - i - 1) + c[i]);

  vis[l] = true;
  return memo[l] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;

  fore(i, n)
    cin >> c[i];
  
  cout << solve(n) << endl;
  return 0;
}

