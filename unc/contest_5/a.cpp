#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
const int max_n = 1e5 + 5;
vector<int> graph[max_n];
bool vis[max_n];
int n, x, y;

void dfs(int x) {
  if (vis[x])return;

  vis[x] = true;

  fore(i, graph[x].size())
    dfs(graph[x][i]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;

  fore(i, n) {
    cin >> x >> y;
    graph[--x].push_back(--y);
  }

  if (n == 1) {
    cout << "Poor Alex" << endl;
    return 0;
  }

  int comp = 0;

  fore(i, n)
    if (!vis[i]) {
      ++comp;
      dfs(i);
    }

  cout << (comp != n ? "Happy Alex" : "Poor Alex") << endl;
    
  return 0;
}

