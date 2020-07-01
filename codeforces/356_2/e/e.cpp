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


const int MAX_N = 505;

int n, k;
char graph[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int added[MAX_N * MAX_N];

int mover[4] = {0, 1, 0, -1};
int movec[4] = {1, 0, -1, 0};


class ufd{
   public:
      vi p, rank, set_size;
      int disj_sets;
      ufd(int n){
         rank.assign(n, 0);
         p.assign(n, 0);
         set_size.assign(n, 1);
         for(int i = 0; i < n; i++)
            p[i] = i;
         disj_sets = n;
      }
      int find(int i){ return (p[i] == i)? i: (p[i] = find(p[i])); }
      bool same_set(int x, int y) { return find(x) == find(y); }
      void merge(int x, int y){
         if (!same_set(x, y)){
            int u = find(x); int v = find(y);
            if (rank[u] > rank[v]) {
               p[v] = u;
               set_size[u] += set_size[v];
            } else {
               p[u] = v;
               set_size[v] += set_size[u];
               if (rank[u] == rank[v])
                  ++rank[v];
            }
            --disj_sets;
         }
      }
      int num_disj_sets() { return disj_sets; }
      int set_size_of(int i) { return set_size[find(i)]; }
};

ufd f(MAX_N * MAX_N + 1);

bool valid_move(int i, int j) {
   return i >= 0 && j >= 0 && i < n && j < n;
}

int get_idx(int i, int j) {
   return i * n + j;
}

void bfs(int x, int y) {
   queue<pii> q;
   q.push(make_pair(x, y));
   vis[x][y] = true;
   while (!q.empty()) {
      pii m = q.front(); q.pop();
      for (int i = 0; i < 4; ++i) {
         int r = m.first + mover[i];
         int c = m.second + movec[i];

         if (valid_move(r, c) && !vis[r][c]) {
            vis[r][c] = true;
            q.push(make_pair(r, c));
            f.merge(get_idx(x, y), get_idx(r, c));
         }
      }
   }
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);
   cin >> n >> k;
   forn(i, n) cin >> graph[i];
   forn(i, n) 
      forn(j, n) 
         vis[i][j] = graph[i][j] == 'X', added[get_idx(i, j)] = 0;
   int max_c = 0;
   forn(i, n) {
      forn(j, n) {
      if (!vis[i][j])
         bfs(i, j);
      }
   }
   int t = 1;
   for (int m = 0; m + k <= n; ++m) {
      fore(i, m, m + k) {
         forn(j, k) {
            --f.set_size[f.find(get_idx(i, j))];
         }
      }
      forn(j, n - k + 1) {
         int c = k * k;
         fore(i, m, m + k) { 
            if (valid_move(i, j - 1) && graph[i][j - 1] != 'X' && added[f.find(get_idx(i, j - 1))] != t) {
               c += f.set_size_of(get_idx(i, j - 1));
               added[f.find(get_idx(i, j - 1))] = t;
            }
            if (valid_move(i, j + k) && graph[i][j + k] != 'X' && added[f.find(get_idx(i, j + k))] != t) {
               c += f.set_size_of(get_idx(i, j + k));
               added[f.find(get_idx(i, j + k))] = t;
            }
         } 
         fore(i, j, j + k) { 
            if (valid_move(m - 1, i) && graph[m - 1][i] != 'X' && added[f.find(get_idx(m - 1, i))] != t) {
               c += f.set_size_of(get_idx(m - 1, i));
               added[f.find(get_idx(m - 1, i))] = t;
            }
            if (valid_move(m + k, i) && graph[m + k][i] != 'X' && added[f.find(get_idx(m + k, i))] != t) {
               c += f.set_size_of(get_idx(m + k, i));
               added[f.find(get_idx(m + k, i))] = t;
            }
         } 
         if (j + k != n) {
            fore(i, m, m + k) {
               ++f.set_size[f.find(get_idx(i, j))];   
               --f.set_size[f.find(get_idx(i, j + k))];   
            }
         }
         max_c = max(c, max_c);
         ++t;
      }
      fore(i, m, m + k) {
         fore(j, n - k, n) {
            ++f.set_size[f.find(get_idx(i, j))];
         }
      }
   }
   cout << max_c << '\n';
   return 0;
}
