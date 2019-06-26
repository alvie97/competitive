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
const int max_n = 3 * 1e5 + 5;

vi a(max_n, -1);
vi st(4 * max_n + 1, -1);

void update(int node, int l, int r, int tl, int tr, int p) {
    if (r < tl || tr < l) return;
    if (tl <= l && r <= tr) {
        if (st[node] != -1) {
            a[st[node]] = p;
            st[node] = p;
            return;
        }
        st[node] = p;
    }

    if (l == r) {
        a[l] = p;
        return;
    }

    int m = (l + r) / 2;
    update(node * 2, l, m, tl, tr, p);
    update(node * 2 + 1, m + 1, r, tl, tr, p);
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m, l, r, x;
  cin >> n >> m;
  forn(i, m) {
      cin >> l >> r >> x;
      --l; --r; --x;
      update(1, 0, n - 1, l, r, x);
  }

  forn(i, n) cout << (i == a[i] ? 0 : a[i] + 1) << (i + 1 == n ? '\n' : ' ');
  return 0;
}

