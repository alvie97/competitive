#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define trav(a, x) for(auto& a: x)
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define N 1005
#define M 1005

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

typedef struct t_node* node;

struct t_node {
    node right;
    node down;
    int el;
    int i;
    int j;
};

node g[N][M];

node create_node() {
    node n = (node)malloc(sizeof(t_node));
    n->el = -1;
    n->right = NULL;
    n->down = NULL;
    n->i = -1;
    n->j = -1;
    return n;
}

node get(int i, int j) {
    node x = g[0][0];
    while (i--) {
        x = x->down;
    }
    while (j--) {
        x = x->right;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q, x, a, b, c, d, h, w;
    cin >> n >> m >> q;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            g[i][j] = create_node();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
           cin >> x; 
           g[i][j]->el = x;
           g[i][j]->right = g[i][j + 1];
           g[i][j]->down = g[i + 1][j];
           g[i][j]->i = i;
           g[i][j]->j = j;
        }
    }
    for (int i = 0; i <= n; ++i) g[i][0]->right = g[i][1], g[i][0]->down = g[i + 1][0];
    for (int i = 0; i <= m; ++i) g[0][i]->down = g[1][i], g[0][i]->right = g[0][i + 1];
    while (q--) {
        cin >> a >> b >> c >> d >> h >> w;
        node x = get(a, b - 1);
        node y = get(c, d - 1);
        node xx = get(a, b + w - 1);
        node yy = get(c, d + w - 1);
        for (int i = 0; i < h; ++i) {
            swap(x->right, y->right);
            x = x->down;
            y = y->down;
        }
        for (int i = 0; i < h; ++i) {
            swap(xx->right, yy->right);
            xx = xx->down;
            yy = yy->down;
        }
        x = get(a - 1, b);
        y = get(c - 1, d);
        xx = get(a + h - 1, b);
        yy = get(c + h - 1, d);
        for (int i = 0; i < w; ++i) {
            swap(x->down, y->down);
            x = x->right;
            y = y->right;
        }
        for (int i = 0; i < w; ++i) {
            swap(xx->down, yy->down);
            xx = xx->right;
            yy = yy->right;
        }
    }
    node r = g[0][0]->down->right;
    for (int i = 0; i < n; ++i) {
        node x = r;
        for (int j = 0; j < m; ++j) {
            cout << r->el;
            if (j < m - 1) cout << ' ';
            r = r->right;
        }
        r = x->down;
        cout << '\n';
    }
    return 0;
}

