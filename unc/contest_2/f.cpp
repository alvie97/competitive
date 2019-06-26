#include <cstdio>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

bool f(vector<pair<int, int>> &freq_s, int max_cuts, int k)
{
    for (int i = 0; i < freq_s.size(); ++i)
    {
        k -= freq_s[i].first / max_cuts;

        if (k <= 0)
        {
            return true;
        }
    }

    return false;
}

int bs(vector<pair<int, int>> &freq_s, int k)
{

    int mid, hi = freq_s[0].first, lo = 0;
    while (lo < hi)
    {
        mid = lo + (hi - lo + 1) / 2;
        if (f(freq_s, mid, k))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return lo;
}

int main()
{

    int n, k, x, max_cuts, aux;
    map<int, int> freq;
    vector<pair<int, int>> freq_s;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        freq[x]++;
    }

    for (map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it)
        freq_s.push_back(make_pair(it->second, it->first));

    sort(freq_s.begin(), freq_s.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });

    max_cuts = bs(freq_s, k);

    for (int i = 0; k > 0 && i < freq_s.size(); ++i)
    {
        aux = freq_s[i].first / max_cuts;

        if (k - aux <= 0)
        {
            while (k--)
            {
                printf("%d%s", freq_s[i].second, k ? " " : "\n");
            }
        }
        else
        {
            k -= aux;

            while (aux--)
            {
                printf("%d ", freq_s[i].second);
            }
        }
    }
    return 0;
}