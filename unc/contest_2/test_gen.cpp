#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("tests.in", "w", stdout);

    puts("200000 1000000000 1000000000");
    for (int i = 0; i < 200000; ++i)
        printf("%d%s", 1000000000 - i, i + 1 < 200000 ? " " : "");
    return 0;
}
