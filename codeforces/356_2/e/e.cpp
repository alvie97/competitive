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

int n;

char graph[505][505];
bool vis[505][505];

int mover[4] = {0, 1, 0, -1};
int movec[4] = {1, 0, -1, 0};

bool valid_move(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n && graph[i][j] != 'X';
}

void bfs(int i, int j) {
   queue<pii> q;
   q.push(make_pair(i, j));
   while (!q.empty()) {
       pii m = q.front(); q.pop();
       vis[m.first][m.second] = true;
       for (int i = 0; i < 4; ++i) {
           int r = m.first + mover[i];
           int c = m.second + movec[i];

           if (valid_move(r, c) && !vis[r][c]) {
                // put in component;
               q.push(make_pair(r, c));
           }
       }
   }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    return 0;
}

