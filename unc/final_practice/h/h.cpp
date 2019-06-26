#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define trav(a, x) for(auto& a: x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, u, v, k;
    cin >> n;
    vi graph[n + 1];
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    int parent[n + 1];
    memset(parent, -1, sizeof(parent));
    int cont[n + 1];
    fill(cont, cont + n, n + 1);
    forn(i, n - 1) {
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> t;
    vis[0] = true;
    t.push(0);
    while (!t.empty()) {
        int x = t.front(); t.pop();
        trav(i, graph[x]) {
            if (vis[i]) continue;
            vis[i] = true;
            t.push(i);
            parent[i] = x;
        }
    }
    cin >> k;
    queue<pii> q; 
    forn(i, k) {
        cin >> u;
        cont[--u] = 0;
        q.push({u, 0});
    }
    while(!q.empty()) {
        pii x = q.front(); q.pop();
        if (parent[x.first] == -1) continue;
        if (cont[parent[x.first]] > x.second + 1) {
            cont[parent[x.first]] = x.second + 1;
            q.push({parent[x.first], x.second + 1});
        }
    }
    forn(i, n) cout << cont[i] << (i < n - 1 ? " ": "\n");
    return 0;
}

