#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, d, st = 0, started, i = 0, jumps = 0;
    string s;

    cin >> n >> d >> s;

    while (st + 1 < n)
    {
        i = st;
        started = i;

        while (i < n && i <= started + d)
        {
            if (s[i] == '1')
                st = i;

            ++i;
        }

        if (started == st)
        {
            cout << "-1" << endl;
            return 0;
        }

        jumps++;
    }

    cout << jumps << endl;

    return 0;
}