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

const int maxn = 1e6 + 5;

ll cr[maxn]; // -1 if prime, some not trivial divisor if not
set<ll> primes;
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,maxn)
            if(cr[i]<0) {
                for (ll j = 1LL * i; j <= maxn; j *= i) {
                    primes.insert(j);
                }

                for(ll j=1LL*i*i;j<maxn;j+=i)cr[j]=i;
            }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    init_sieve();
    cin >> n;
    for (ll i = 1LL; (i * i) <= n; ++i) {
        if (n % (i * i) == 0) {
            ll q = n / (i * i);
            if (q == 2LL || primes.find(q) != primes.end()) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

