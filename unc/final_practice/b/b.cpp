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

string board[5];
bool check(int x, int y, int player) {
    int l = 0, r = 0;
    char c = player == 0 ? 'X' : 'O';
    fore(i, x + 1, 3) 
        if (board[i][y] == c) ++l;
    for(int i = x - 1; i >= 0; --i) 
        if (board[i][y] == c) ++r;
    if (l + r + 1 == 3) return true;
    l = r = 0;
    fore(i, y + 1, 3) 
        if (board[x][i] == c) ++l;
    for(int i = y - 1; i >= 0; --i) 
        if (board[x][i] == c) ++r;
    if (l + r + 1 == 3) return true;
    l = r = 0;
    for (int i = 1; x + i < 3 && y + i < 3; ++i)
        if (board[x + i][y + i] == c) ++l;
    for (int i = 1; x - i >= 0 && y - i >= 0; ++i)
        if (board[x - i][y - i] == c) ++r;
    if (l + r + 1 == 3) return true;
    l = r = 0;
    for (int i = 1; x + i < 3 && y - i >= 0; ++i)
        if (board[x + i][y - i] == c) ++l;
    for (int i = 1; x - i >= 0 && y + i < 3; ++i)
        if (board[x - i][y + i] == c) ++r;
    return l + r + 1 == 3;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int x = 0, o = 0;
    forn(i, 3) cin >> board[i];
    forn(i, 3) forn(j, 3) {
        if (board[i][j] == 'X')
            ++x;
        if (board[i][j] == 'O')
            ++o;
    }

    if (x <= o) {
        forn(i, 3) {
            forn(j, 3) {
                if (board[i][j] == '.')
                    if (check(i, j, 0)) {
                        puts("X 1");
                        return 0;
                    }
            }
        }
        puts("X 0");
    } else {
        forn(i, 3) {
            forn(j, 3) {
                if (board[i][j] == '.')
                    if (check(i, j, 1)) {
                        puts("O 1");
                        return 0;
                    }
            }
        }
        puts("O 0");
    }
    return 0;
}

