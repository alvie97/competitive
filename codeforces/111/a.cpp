#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 5];
    a[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a, a + n + 1);
    for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
    for (int i = n; i >= 0; --i)
        if (a[i] < a[n] - a[i]) {
            cout << n - i << '\n';
            return 0;
        }
    return 0;
}