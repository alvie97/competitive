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
    int cards[6];
    int numbers[105] = {0};
    int sum = 0;
    forn(i, 5) {
        cin >> cards[i];
        sum += cards[i];
        ++numbers[cards[i]];
    }
    int mn = sum;
    forn(i, 5) {
        if (numbers[cards[i]] > 1) {
            mn = min(mn, sum - (numbers[cards[i]] >= 3 ? cards[i] * 3 : cards[i] * 2));
        }
    }
    cout << mn << endl;
    return 0;
}

