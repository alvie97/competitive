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

const int M = 1e9 + 7;
const int max_n = 1e6 + 5;

ll fact[max_n];

ll inv(ll a) {
    a %= M;
    int b = M - 2;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

bool check(int num, int a, int b) {
    int d;
    do {
        d = num % 10;
        if (d != a && d != b) return false;
    } while (num /= 10);
    return true;
}

ll bc(int n, int k) {
    return fact[n] * inv(fact[k]) % M * inv(fact[n - k]) % M;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    fact[0] = fact[1] = 1;
    fore (i, 2, n + 1) fact[i] = i * fact[i - 1] % M;
    ll ans = 0;
    forn (i, n + 1) {
        int z = a * i + b * (n - i);
        if (check(z, a, b)) 
            ans = (ans + bc(n, i)) % M;
    }
    cout << ans << endl;
  return 0;
}

