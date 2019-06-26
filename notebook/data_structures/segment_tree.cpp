/* 
 * Time complexity: 
 * O(n*log(n)) construction, O(log(n)) updates, O(log
 *
 * Usage:
 *
 * STree st(n);
 * st.init(1, 0, n - 1);
 * st.query(1, 0, n - 1, i, j);
 * st.update(1, 0, n - 1, position, value);
 * st.query(1, 0, n - 1, i, j);
 */

#define neut inf // neutral value

struct STree {
    vi st; int n;
    STree(int n) : st(4 * n + 1), n(n) {}
    f(int a, int b) { return max(a, b); } // associative fn
    void init(int node, int l, int r) {
        if (l == r) { st[node] = a[l]; return; }
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        st[node] = f(a[node * 2], a[node * 2 + 1];
    }

    int query(int node, int l, int r, int i, int j) {
        if (r < i || j < l) return neut;
        if (i <= l && r <= j) return st[node];
        int m = (l + r) / 2;
        int lq = query(node * 2, l, m, i, j);
        int rq = query(node * 2 + 1, m + 1, r, i, j);
        return f(lq, rq);
    }

    void update(int node, int l, int r, int p, int val) {
        if (l == r) { st[node] = val; return; }
        int m = (l + r) / 2;
        if (p <= m) update(node * 2, l, m, p, val);
        else update(node * 2 + 1, m + 1, r, p, val);
        st[node] = f(a[node * 2], a[node * 2 + 1]);
    }
};

