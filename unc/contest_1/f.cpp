#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

int main() {
    int n, res = 0;
    char name_1[30], name_2[30];
    map<string, int> graph;
    string u_1, u_2;

    scanf("%d", &n);

    while (n--) {
        scanf("%s reposted %s", name_1, name_2);

        u_1 = string(name_1);
        u_2 = string(name_2);

        for (int i = 0; i < u_1.size(); ++i)
            u_1[i] = tolower(u_1[i]);

        for (int i = 0; i < u_2.size(); ++i)
            u_2[i] = tolower(u_2[i]);

        graph[u_1] = graph[u_2] + 1;

        res = max(graph[u_1] + 1, res);
    }

    printf("%d\n", res);

    return 0;
}
