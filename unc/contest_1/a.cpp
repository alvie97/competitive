#include <cstdio>
#include <algorithm>
using namespace std;

int main(){ 

    int n, num, res = 0;
    int a[105] = {0};

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &num);
        ++a[num];
        res = max(a[num], res);
    }

    printf("%d\n", res);

    return 0;
}

