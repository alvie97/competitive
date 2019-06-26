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
    int n, m, k, x, y;
    cin >> n >> m >> k;
    bool whole[n + 1];
    memset(whole, false, sizeof(whole));
    forn(i, m) {
        cin >> x;
        whole[x - 1] = true;
    }
    int ball = 0;
    forn(i, k) {
        cin >> x >> y;
        --x; --y;
        if (!whole[ball]) {
            if (ball == x) ball = y;
            else if (ball == y) ball = x;
        }
    }
    cout << ball + 1 << endl;
    return 0;
}

