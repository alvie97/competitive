#include <cstdio>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;


int main () {
    int n, x, m;
    int worms[100005], p_s[100005];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        worms[i] = x;
    }

    partial_sum(worms, worms + n, p_s);

    
    scanf("%d", &m);

    while (m--) {
        scanf("%d", &x);
        int *i = lower_bound(p_s, p_s + n, x);

        printf("%ld\n", (i - begin(p_s)) + 1);
    }
    
    return 0;
}
