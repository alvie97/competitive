#include <algorithm>
#include <cstdio>
using namespace std;

#define ll long long

void sum(ll n[100005], ll aux[100005], int len) {

    for (int i = 1; i <= len; ++i) {
        aux[i] = aux[i - 1] + n[i - 1];
    }

} 

int main() {
    int n, m, type, l, r;
    ll v[100005], u[100005], vi[100005], ui[100005];
    vi[0] = ui[0] = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
        u[i] = v[i];
    }

    sort(u, u + n);

    sum(v, vi, n);
    sum(u, ui, n);

    scanf("%d", &m);

    while (m--) {
        scanf("%d %d %d", &type, &l, &r);

        if (type == 1)
            printf("%lld\n", vi[r] - vi[l - 1]);
        else
            printf("%lld\n", ui[r] - ui[l - 1]);
    }
    return 0;
}
