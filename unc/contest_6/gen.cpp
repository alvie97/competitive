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

int a, b, n;

bool check(int num) {
    int d;
    do {
        d = num % 10;
        if (d != a && d != b) return false;
    } while (num /= 10);
    return true;
}

int bk (int sum, int s) {
    if (s >= n) return check(sum);
    return bk(sum + a, s + 1) + bk(sum + b, s + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> n;
    ll sum = 0;
    cout << bk(0, 0) << endl;
  return 0;
}
