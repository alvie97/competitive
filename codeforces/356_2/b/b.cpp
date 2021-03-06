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
    int n, a;
    cin >> n >> a;
    int cities[n + 1];
    forn(i, n) cin >> cities[i];
    int criminals = cities[--a];
    int i = a - 1, j = a + 1;
    while (i >= 0 || j < n) {
        if (i < 0) criminals += cities[j];
        else if (j >= n) criminals += cities[i];
        else criminals += cities[i] && cities[j] ? 2 : 0;
        --i; ++j;
    }
    cout << criminals << endl;
    return 0;
}

