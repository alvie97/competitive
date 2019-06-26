#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define trav(a, x) for(auto& a: x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int d, st, mint, maxt, mins = 0, maxs = 0;
    cin >> d >> st;
    vii times(d);
    vi ans(d);

    forn(i, d) {
        cin >> mint >> maxt;
        ans[i] = mint;
        times[i] = {mint, maxt};
        mins += mint;
        maxs += maxt;
    }

    if (mins <= st && st <= maxs) {
        forn(i, d) {
            pii el = times[i];
            mins += el.second - el.first;
            if (mins >= st) {
                ans[i] = el.second - (mins - st);
                break;
            }
            ans[i] = el.second;
        }
        cout << "YES" << endl;
        forn(i, d) cout << ans[i] << (i < d - 1 ? " " : "\n");
    } else cout << "NO" << endl;
    return 0;
}


