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
const int MAXN = 1e6 + 5;
int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}
map<int,int> fact(int n){
	map<int,int> r;
	while(cr[n]>=0)r[cr[n]]++,n/=cr[n];
	if(n>1)r[n]++;
	return r;
}
int divr[1000005];
bool f(int a, int b) {
    if (divr[a] == divr[b]) return a < b;
    return divr[a] < divr[b];

}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    int dni[100005];
    memset(divr, -1, sizeof(divr));
    init_sieve();
    cin >> n;
    forn(i, n) {
        cin >> dni[i];
        if (divr[dni[i]] == -1) divr[dni[i]] = fact(dni[i]).begin()->first;
    }
    sort(dni, dni + n, f);
    forn(i, n) cout << dni[i] << (i < n - 1 ? " ": "\n");
    return 0;
}

