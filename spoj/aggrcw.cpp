#include <cstdio>
#include <algorithm>

using namespace std;

bool f(int stables[100005], int dist, int n, int cows) {
    --cows;
    int cow_dist = stables[0];

    for (int i = 1; i < n; ++i) {
        if (stables[i] - cow_dist >= dist) {
            cow_dist = stables[i];
            --cows;
        }

        if (cows == 0) {
            return true;
        }
    }

    return false;
}

int solve(int stables[100005], int n, int c) {
    int mid, hi = 1000000005, lo = 0; 

    while (lo<hi) {
        mid = lo + (hi-lo+1)/2;

        if (f(stables, mid, n, c)) lo = mid;
        else hi = mid - 1;
    }

    return lo;
}

int main() {
    int t, n, c;
    int arr[100005];

    scanf("%d", &t);

    while(t--) {

        scanf("%d %d", &n, &c);

        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        sort(arr, arr + n);
        printf("%d\n", solve(arr, n, c));
    }
}
