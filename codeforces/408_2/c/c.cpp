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
    int n, p, q;
    multiset<int> banks;
    cin >> n;
    int s[n + 5];
    vi graph[n + 5];
    forn(i, n) {
        cin >> s[i];
        banks.insert(s[i] + 2);
    }
    forn(i, n - 1) {
        cin >> p >> q;
        --p; --q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
    int mn = numeric_limits<int>::max();
    forn(u, n) {
        banks.erase(banks.find(s[u] + 2));
        banks.insert(s[u]);
        trav(v, graph[u]) {
            banks.erase(banks.find(s[v] + 2));
            banks.insert(s[v] + 1);
        }
        mn = min(mn, *(banks.rbegin()));
        banks.erase(banks.find(s[u]));
        banks.insert(s[u] + 2);
        trav(v, graph[u]) {
            banks.erase(banks.find(s[v] + 1));
            banks.insert(s[v] + 2);
        }

    }
    cout << mn << endl;
    return 0;
}

