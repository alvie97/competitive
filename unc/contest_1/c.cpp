#include <cstdio>
using namespace std;

int main() {

    int n_buttons, n_bulbs, x, y;
    int bulbs[105] = { 0 };

    scanf("%d %d", &n_buttons, &n_bulbs);

    while (n_buttons--) {
        scanf("%d", &x);

        while (x--) {
            scanf("%d", &y);
            ++bulbs[y];
        }
    }

    bool flag = true;

    for (int i = 1; i <= n_bulbs; ++i) {
        if (!bulbs[i]) {
            flag = false;
            printf("NO\n");
            break;
        }
    }

    if (flag) 
        printf("YES\n");

    return 0;
}
