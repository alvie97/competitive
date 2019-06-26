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
    int n, q, m;
    cin >> n;
    vi shops(n + 1);
    forn(i, n) cin >> shops[i];
    sort(all(shops));
    cin >> q;
    int cnt;
    forn(i, q) {
        cin >> m;
        cnt = upper_bound(all(shops), m) - shops.begin();
        cout << cnt - 1 << endl;
    }
    return 0;
}

