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

const int max_n = 1e5 + 5;
int a[max_n];

struct STree {
    vii st;
    STree(int s): st(4 * s + 5, {0, 0}) {}

    void init(int node, int l, int r) {
        if (l + 1 == r) {
            st[node] = {a[l], 1};
            return;
        }
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m, r);
        int freq = 0, gcd;
        gcd = __gcd(st[node * 2].first, st[node * 2 + 1].first);
        if (gcd == st[node * 2].first) 
            freq += st[node * 2].second;
        if (gcd == st[node * 2 + 1].first) 
            freq += st[node * 2 + 1].second;
        st[node] = {gcd, freq};
    }

    pii query(int node, int l, int r, int i, int j) {
        if (l >= j || r <= i) return {0, 0};
        if (l >= i && r <= j) return st[node];
        int m = (l + r) / 2;
        int freq = 0, gcd;
        pii lq, rq;
        lq = query(node * 2, l, m, i, j);
        rq = query(node * 2 + 1, m, r, i, j);
        gcd = __gcd(lq.first, rq.first);
        if (gcd == lq.first) freq += lq.second;
        if (gcd == rq.first) freq += rq.second;
        return {gcd, freq};
    }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m, l, r;
  cin >> n;
  STree st(n);
  forn(i, n) cin >> a[i];
  st.init(1, 0, n);
  cin >> m;
  forn(i, m) {
    cin >> l >> r;
    cout << r - l - st.query(1, 0, n, l - 1, r).second + 1 << endl;
  }
  return 0;
}

