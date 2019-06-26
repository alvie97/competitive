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
    string ans;
    int MAXN = 105;
    int cr[MAXN];
    vi primes;
    memset(cr, -1, sizeof(cr));
    fore(i, 2, MAXN)
        if(cr[i] < 0)
            for(ll j= 1LL * i * i; j < MAXN; j += i)
                cr[j] = i;
    for (int i = 2; i <= 50; ++i)
        if (cr[i] == -1)
            primes.push_back(i);
    int cnt = 0;
    trav(i, primes) {
        cout << i << endl;
        fflush(stdout);
        cin >> ans;
        if (ans == "yes") {
            cnt++;
            for (int j = i * i; j < 100; j *= i) {
                cout << j << endl;
                fflush(stdout);
                cin >> ans;
                if (ans == "yes") {
                    cout << "composite" << endl;
                    fflush(stdout);
                    return 0;
                }
            }
        }

        if (cnt > 1) break;
    }

    if (cnt > 1) cout << "composite" << endl;
    else cout << "prime" << endl;
    fflush(stdout);
    return 0;
}

