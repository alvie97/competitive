#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, b, a, a_r;
    int ox[200005];

    scanf("%d %d %d", &n, &b, &a);

    for (int i = 0; i < n; ++i)
        scanf("%d", &ox[i]);

    int i = 0;

    a_r = a;

    for (; i < n; ++i)
    {
        if (ox[i])
        {
            if (b > 0)
            {
                if (a == a_r)
                {
                    --a;
                }
                else
                {
                    --b;
                    a = min(a_r, a + 1);
                }
            }
            else
            {
                --a;
            }
        }
        else
        {
            if (a > 0)
                --a;
            else
                --b;
        }

        if (a == 0 && b == 0)
        {
            i++;
            break;
        }
    }

    printf("%d\n", i);

    return 0;
}