#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;

  cin >> n >> s;

  if (n % 2 != 0)
  {
    cout << ":(" << endl;
    return 0;
  }

  int open = 0, close = s.size() - 1, opened = 0, closed = 0;

  while (open <= close)
  {
    if (opened <= closed)
    {
      if (s[open] == '(')
      {
        ++opened;
      }
      else if (s[open] == ')')
      {
        ++closed;
      }
      else
      {
        s[open] = '(';
        ++opened;
      }
      ++open;
    }
    else
    {
      if (s[close] == ')')
      {
        ++closed;
      }
      else if (s[close] == '(')
      {
        ++opened;
      }
      else
      {
        s[close] = ')';
        ++closed;
      }

      --close;
    }
  }

  if (opened == closed)
    cout << s << endl;
  else
    cout << ":(" << endl;

  return 0;
}
