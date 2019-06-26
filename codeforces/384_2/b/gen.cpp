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

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = atoi(argv[1]);
    srand(time(NULL));
    int k = rand(1, (1 << n) - 1);
    cout << n << " " << k << endl;
    return 0;
}


