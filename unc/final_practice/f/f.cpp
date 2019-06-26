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

const int maxn = 1e5 + 5;

int uf[maxn];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, t, x, y;
    cin >> n >> m;
    uf_init();
    while(m--) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            uf_join(x, y);
        } else {
            cin >> x;
            if (uf[uf_find(x)] == -1)
                cout << 0 << endl;
            else cout << abs(uf[uf_find(x)]) - 1 << endl;
        }
    }
    return 0;
}

