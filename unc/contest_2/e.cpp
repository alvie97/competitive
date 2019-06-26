#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, t, b;
    vector<pair<int, int>> ts;
    vector<pair<int, int>> bs;
    vector<pair<int, int>> songs;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &t, &b);

        ts.push_back(make_pair(t, i));
        bs.push_back(make_pair(b, i));
        songs.push_back(make_pair(t, b));
    }

    sort(ts.begin(), ts.end());
    sort(bs.begin(), bs.end());

    int k_a, sum, j;
    long long max_s;

    for (int i = 0; i < bs.size(); ++i)
    {
        j = 0;
        k_a = k;
        max_s = bs[i].first * songs[bs[i].second].first;
        sum = songs[bs[i].second].first;

        while (k_a && j < ts.size())
        {
            if (ts[ts.size() - j].second == bs[i].second || bs[i].first > songs[ts[]])
                continue;

            max_s = max(max_s, (sum + ts[ts.size() - j].first) * bs[i].first);
        }
    }

    return 0;
}
