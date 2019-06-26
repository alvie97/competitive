#include <cstdio>
#include <cstring>
using namespace std;

int main() {

    int n, faces = 0;
    char poly[20];

    scanf("%d", &n);

    while (n--) {

        scanf("%s", poly);

        if (strcmp(poly, "Tetrahedron") == 0) {
            faces += 4;
        } else if (strcmp(poly, "Cube") == 0) {
            faces += 6;
        } else if (strcmp(poly, "Octahedron") == 0) {
            faces += 8;
        } else if (strcmp(poly, "Dodecahedron") == 0) {
            faces += 12;
        } else {
            faces += 20;
        }
    }

    printf("%d\n", faces);

    return 0;
}
