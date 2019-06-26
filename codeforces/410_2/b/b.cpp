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

int steps(const string &x, const string &y) {
    forn(i, sz(x)) {
        if (x[0] == y[i]) {
            bool eq = true;
            forn(j, sz(x)) {
               if (x[j] != y[(i + j) % sz(y)]) {
                   eq = false;
                   break;
               }
            }
            if (eq) return i;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int sum, n, st, ans = numeric_limits<int>::max();
    cin >> n;
    string s[n + 1];
    forn(i, n) cin >> s[i];
    forn(i, n) {
        sum = 0;
        forn(j, n) {
            if (i == j) continue;
            st = steps(s[i], s[j]);
            if (st == -1) {
                cout << st << endl;
                return 0;
            }
            sum += st;
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
    return 0;
}

