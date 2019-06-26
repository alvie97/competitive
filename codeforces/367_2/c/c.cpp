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
const int maxn = 1e5 + 5;
const ll inf = 1e15;
ll memo[maxn][5];
bool vis[maxn][5];
string words[maxn];
string rwords[maxn];
ll c[maxn];
int n;

ll solve(int i, int r) {
    if (i >= n) return 0LL;
    if (vis[i][r]) return memo[i][r];
    ll mn = inf;
    if (r) {
        if (rwords[i - 1] <= words[i])
            mn = min(mn, solve(i + 1, 0));
        if (rwords[i - 1] <= rwords[i])
            mn = min(mn, solve(i + 1, 1) + c[i]);
    } else {
        if (words[i - 1] <= words[i])
            mn = min(mn, solve(i + 1, 0));
        if (words[i - 1] <= rwords[i])
            mn = min(mn, solve(i + 1, 1) + c[i]);
    }
    vis[i][r] = true;
    return memo[i][r] = mn;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(vis, false, sizeof(vis));
    cin >> n;
    forn(i, n) cin >> c[i];
    forn(i, n) {
        cin >> words[i];
        rwords[i] = words[i];
        reverse(all(rwords[i]));
    }
    ll ans = min(solve(1, 0), solve(1, 1) + c[0]);
    cout << (ans >= inf ? -1 : ans) << endl;
    return 0;
}

