#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n, m, d, x, sum;
    map<int, int> breaks;
    map<int, int>::iterator it;

    scanf("%d %d %d", &n, &m, &d);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        breaks[x] = i;
    }

    int ans[n + 5];

    int day = 0;

    while (!breaks.empty()) {
        it = breaks.begin();
        sum = it->first + 1 + d;
        ans[it->second] = ++day;
        breaks.erase(it);

        while (sum <= m && !breaks.empty()) {
            it = breaks.lower_bound(sum);
            if (it == breaks.end()) {
                break;
            }
            sum = it->first + 1 + d;
            ans[it->second] = day;
            breaks.erase(it);
        }
    }

    printf("%d\n", day);

    for(int i = 0; i < n; ++i)
        printf("%d%s", ans[i], i + 1 < n ? " ": "\n");

    return 0;
}
