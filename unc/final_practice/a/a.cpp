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
    int freq[30] = {0};
    string w = "pingo";
    int p = 0;
    cin >> s;
    forn(i, sz(s)) {
        if (s[i] < 'a' || s[i] > 'z') {
            cout << "NO" << endl;
            return 0;
        }
        ++freq[s[i] - 'a'];
        if (s[i] == w[0]) {
            int c = 0;
            for (int j = 0; i + j < sz(s) && j < sz(w); ++j) {
                if (s[i + j] == w[j]) ++c;
                else break;
            }  
            if (c == sz(w)) ++p;
        }
    }
    bool flag = true;
    forn(i, sz(w)) {
        if (freq[w[i] - 'a'] % 19 != 0) {
            flag = false;
        }
    }
    if (flag && (p % 19 == 0))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}

