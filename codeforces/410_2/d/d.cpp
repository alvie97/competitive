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
    int n, x;
    cin >> n;
    pii a[n + 1];
    int b[n + 1];
    forn(i, n) {
        cin >> x;
        a[i] = {x, i};
    }

    forn(i, n) cin >> b[i];
    sort(a, a + n, [](pii p, pii q) {return p.first > q.first;});
    vi bst;
    bst.push_back(a[0].second);
    for (int i = 1; i < n; i += 2) {
        int ans = a[i].second;
        if (i + 1 < n && b[a[i + 1].second] >= b[ans])
            bst.push_back(a[i + 1].second);
        else bst.push_back(ans);
    }

    cout << sz(bst) << endl;
    forn(i, sz(bst)) cout << bst[i] + 1 << (i < sz(bst) - 1 ? " ": "\n");

    return 0;
}

