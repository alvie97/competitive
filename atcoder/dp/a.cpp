#include <bits/stdc++.h>
using namespace std;

int h[100005];
int memo[100005];
bool vis[100005];
int n;

#define fore(i, n) for(int i = 0; i < n; ++i)


int solve(int i) {
  if (vis[i]) return memo[i];
  if (i >= n - 1) return 0;

  int res = solve(i + 1) + abs(h[i] - h[i + 1]);
  
  if (i + 2 < n)
    res = min(res, solve(i + 2) + abs(h[i] - h[i + 2]));
    

  vis[i] = true;
  return memo[i] = res;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;

  fore(i, n)
    cin >> h[i];

  cout << solve(0) << endl;

  return 0;
}
