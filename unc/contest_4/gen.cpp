#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  freopen("in", "w", stdout);
  cout << 1;
  for(int i = 1; i < 9999; ++i)
    cout << i % 10;

  cout << " " << 1 << endl;
}
