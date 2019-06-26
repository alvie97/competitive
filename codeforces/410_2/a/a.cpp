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
    string s;
    cin >> s;
    int l = 0, r = sz(s) - 1, cnt = 0;
    while (l < r) {
        if (s[l] != s[r])
            ++cnt;

        if (cnt > 1) {
            cout << "NO" << endl;
            return 0;
        }

        ++l; -- r;
    }

    if (cnt == 0)
        if (sz(s) & 1)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}

