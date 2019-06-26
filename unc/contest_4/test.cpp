#include <bits/stdc++.h>
using namespace std;

int calc(int n) {
  int sum = 0;
  int d;
  do {
    d = n % 10;
    sum += d;
  } while (n /= 10);

  return sum;
}

int main() {
  int n, k;
  cin >> n;
  map<int, int> sums;

  for (int i = 1; i <= n; ++i)
    ++sums[calc(i)];

  for (auto it: sums)
    cout << it.first << " repeats " << it.second << " times" << endl;
  return 0;
}
