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

pair<ll, ll> best;

ll cube(ll a) { return a * a * a; }

void calc(ll blocks, ll x, ll m) {
    if (m == 0) {
        best = max(best, make_pair(blocks, x));
        return;
    } 
    ll a = 1;
    while (cube(a + 1) <= m) a++;
    calc(blocks + 1, x + cube(a), m - cube(a));
    calc(blocks + 1, x + cube(a - 1), cube(a) - 1 - cube(a - 1));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll m;
    cin >> m;
    calc(0, 0, m);
    cout << best.first << " " << best.second << '\n';
    return 0;
}

