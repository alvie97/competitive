#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a: x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int max_n = 2 * 1e5 + 5;

vi graph[max_n];
bool vis[max_n];
bool two_edges;
int last;

void dfs(int x) {
	if(vis[x]) return;
	last = x;
	vis[x]=true;
	if(sz(graph[x]) != 2) two_edges = false;
	rep(i, 0, sz(graph[x])) dfs(graph[x][i]);
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int n, m, u, v;

  cin >> n >> m;

  rep(i, 0, m) {
	  cin >> u >> v;
	 
	  graph[--u].push_back(--v);
	  graph[v].push_back(u);
  }

  int count = 0;

  rep(i, 0 , n) {
	  two_edges = true;
	  
	  if(!vis[i]) {
		  dfs(i);
		  if(two_edges) {
			  if(graph[last][0] == i || graph[last][1] == i)
				  count++;
		  }
	  }
  }

  cout << count << endl;
  
  return 0;
}
