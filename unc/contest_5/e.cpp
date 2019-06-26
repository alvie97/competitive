#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define pb push_back
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
const int max_n = 1e5 + 5;
const ll INF = numeric_limits<ll>::max();

vii graph[max_n];
ll dist[max_n];
int parent[max_n];
int n;

void solve() {
  priority_queue<pii> pq; 
  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    pii u = pq.top(); pq.pop();

    fore (i, graph[u.first].size()) {
      pii v = graph[u.first][i];
      if (dist[u.first] + v.second < dist[v.first]) {
        parent[v.first] = u.first;
        dist[v.first] = dist[u.first] + v.second;
        pq.push({v.first, dist[v.first]});
      }
    }
  }

}

void dfs(int x) {
  if (x != 0)
    dfs(parent[x]);

  cout << x + 1 << " ";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int m, a, b, w;

  cin >> n >> m;

  fore (i, m) {
    cin >> a >> b >> w;

    graph[--a].pb({--b, w});
    graph[b].pb({a, w});
  }
  
  fill(dist, dist + n, INF);
  solve();

  if (dist[n - 1] == INF) cout << -1;
  else dfs(n - 1);

  cout << endl;

  return 0;
}

