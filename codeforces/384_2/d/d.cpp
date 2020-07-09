#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int nax = 200005;
const ll INF = LLONG_MIN;

int a[nax];
vi g[nax];
ll sum_tree[nax], max_tree[nax];

void print_ar(int n, ll ar[]) {
  cout << "[";
  for (int i = 0; i < n; ++i)
    cout << ar[i] << ", ";
  cout << "\b\b]\n";
}

void sum_max(int u, int p) {
  ll sm = a[u], bs = INF;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    if (p == g[u][i])
      continue;
    sum_max(g[u][i], u);
    sm += sum_tree[g[u][i]];
    bs = max(bs, max_tree[g[u][i]]);
  }
  sum_tree[u] = sm;
  max_tree[u] = max(bs, sm);
}

ll bestn = INF;

void dfs(int u, int p, ll outside) {
  if (outside != INF)
    bestn = max(bestn, outside + sum_tree[u]);
  multiset<ll> mx_trees;
  for (int i = 0; i < (int)g[u].size(); ++i)
    if (p != g[u][i])
      mx_trees.insert(max_tree[g[u][i]]);
  for (int i = 0; i < (int)g[u].size(); ++i) {
    if (p == g[u][i])
      continue;
    mx_trees.erase(mx_trees.find(max_tree[g[u][i]]));
    dfs(g[u][i], u,
        max(outside, mx_trees.size() > 0u ? *mx_trees.rbegin() : INF));
    mx_trees.insert(max_tree[g[u][i]]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, u, v;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  sum_max(0, -1);
  /* print_ar(n, max_tree); */
  /* print_ar(n, sum_tree); */
  dfs(0, -1, INF);
  if (bestn != INF)
    cout << bestn;
  else
    cout << "Impossible";
  cout << '\n';
  return 0;
}
