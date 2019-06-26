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
    cout.precision(10);
    int a, b, x, y, n, v;
    cin >> a >> b >> n;
    double mn = numeric_limits<double>::max();
    forn(i, n) {
        cin >> x >> y >> v;
        mn = min(mn, hypot((double)(a - x), (double)(b - y)) / v);
    }
    cout << fixed << mn << endl;
    return 0;
}

