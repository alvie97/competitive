#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fore(i, n) for(int i = 0; i < n; ++i)
#define fors(i, s, n) for(int i = s; i < n; ++i)
#define pb push_back
const int max_n = 2005;
vector<int> graph[max_n];
int indeg[max_n];
bool added[max_n];
int n;

int solve() {
  bool not_added = true;
  queue<int> rem_deg;
  int groups = 0;

  while (not_added) {
    not_added = false;
    fore(i, n)
      if (!added[i] && indeg[i] == 0)
        rem_deg.push(i);

    if (!rem_deg.empty()) {
      groups++;
      not_added = true;
    }

    while (!rem_deg.empty()) {
      int x = rem_deg.front();
      rem_deg.pop();

      added[x] = true;

      fore(i, graph[x].size())
        indeg[graph[x][i]]--;
    }
  }

  return groups;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x;

  cin >> n;

  fore(i, n) {
    cin >> x;

    if (x != -1) {
      graph[--x].pb(i);
      ++indeg[i];
    }
  }

  cout << solve() << endl;
  return 0;
}

