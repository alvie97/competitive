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
const int maxn = 2005;
const ll inf = 1e15;
ll memo[maxn][maxn];
bool vis[maxn][maxn];
ll grid[maxn][maxn];
int n, m;

ll solve(int i, int j) {
    if (i >= n && j >= m) return 0;
    if (i >= n || j >= m) return 0;
    if (vis[i][j]) return memo[i][j];
    ll mx = max(solve(i + 1, j) + grid[i][j], solve(i, j + 1) + grid[i][j]);
    vis[i][j] = true;
    return memo[i][j] = mx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    forn(i, n) forn(j, m) cin >> grid[i][j];
    cout << solve(0, 0) << endl;
    return 0;
}

