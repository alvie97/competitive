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
    int n;
    cin >> n;
    bool odd[n + 1];
    int a[n + 1];
    int g = 0;
    forn(i, n) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        odd[i] = a[i] & 1;
    }

    if (g > 1) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return 0;
    }
    int steps = 0;
    forn(i, n - 1) {
        if (odd[i]) {
            if (!odd[i + 1]) steps += 2;
            else ++steps;
            odd[i] = odd[i + 1] = 0;
        }
    }

    if (odd[n - 1]) steps += 2;

    cout << "YES" << endl;
    cout << steps << endl;
    return 0;
}

