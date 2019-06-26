// codeforces contest 339 Div. 2 Problem D
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

int a[(1 << 17) + 5];

struct STree {
    vi st; int n;
    STree(int n) : st(4 * n + 1), n(n) {}
    void init(int node, int l, int r, int level) {
        if (l == r) { st[node] = a[l]; return;}
        int m = (l + r) / 2;
        init(node * 2, l, m, level - 1);
        init(node * 2 + 1, m + 1, r, level - 1);
        if (level & 1) st[node] = st[node * 2] | st[node * 2 + 1];
        else st[node] = st[node * 2] ^ st[node * 2 + 1];
    }
    void update(int node, int l, int r, int p, int val, int level) {
        if (l == r) { st[node] = val; return; }
        int m = (l + r) / 2;
        if (p <= m) update(node * 2, l, m, p, val, level - 1);
        else update(node * 2 + 1, m + 1, r, p, val, level - 1);
        if (level & 1) st[node] = st[node * 2] | st[node * 2 + 1];
        else st[node] = st[node * 2] ^ st[node * 2 + 1];
    }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m, p, b;
  cin >> n >> m;
  int n2 = 1 << n;
  forn(i, n2) cin >> a[i];
  STree segtree(n2);
  segtree.init(1, 0, n2 - 1, n);
  forn(i, m) {
      cin >> p >> b; 
      segtree.update(1, 0, n2 - 1, p - 1, b, n);
      cout << segtree.st[1] << endl;
  }
  return 0;
}
