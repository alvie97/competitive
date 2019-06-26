#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)

const int max_n = 1e5;

vector<int> graph[max_n + 5];
int c[max_n + 5];
bool vis[max_n + 5];
int n, m;

int dfs(int x, int con) {
  if (vis[x]) return 0;
  vis[x] = true;
  if (c[x] + con > m) return 0;
  if (graph[x].size() == 1 && x != 0) return 1;

  int res = 0;

  fore(i, graph[x].size())
    res += dfs(graph[x][i], c[x] ? con + c[x] : 0);

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> n >> m;

  fore(i, n)
    cin >> c[i];

  fore(i, n - 1) {
    cin >> x >> y;
    --x; --y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  cout << dfs(0, 0) << endl;

  return 0;
}
