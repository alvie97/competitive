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
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1];
    forn(i, n) cin >> a[i];
    int mx1 = 0, mx2 = 0;
    bool f1 = false, f2 = false;
    fore(i, m, n) {
        ++mx1;
        if (a[i] && a[i] <= k) {
            f1 = true;
            break;
        }
    }

    for (int i = m - 2; i >= 0; i--) {
        ++mx2;
        if (a[i] && a[i] <= k) {
            f2 = true;
            break;
        }
    }

    if (f1 && f2) cout << min(mx1, mx2) * 10 << endl;
    else cout << (f1 ? mx1 : mx2) * 10 << endl;
    return 0;
}

