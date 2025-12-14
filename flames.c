#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countRemaining(char a[], char b[]) {
    int i, j, count = 0;
    for (i = 0; a[i]; i++) {
        for (j = 0; b[j]; j++) {
            if (a[i] == b[j] && a[i] != ' ') {
                a[i] = b[j] = '*';
                break;
            }
        }
    }
    for (i = 0; a[i]; i++) if (a[i] != '*' && a[i] != ' ') count++;
    for (j = 0; b[j]; j++) if (b[j] != '*' && b[j] != ' ') count++;
    return count;
}

char flamesResult(int count) {
    char f[] = "FLAMES";
    int len = 6, i, pos;
    while (len > 1) {
        pos = (count % len == 0) ? len : count % len;
        for (i = pos - 1; i < len - 1; i++)
            f[i] = f[i + 1];
        f[--len] = '\0';
    }
    return f[0];
}

int main() {
    char n1[100], n2[100];
    printf("Enter first name: ");
    fgets(n1, sizeof(n1), stdin);
    printf("Enter second name: ");
    fgets(n2, sizeof(n2), stdin);

    n1[strcspn(n1, "\n")] = n2[strcspn(n2, "\n")] = '\0';

    // convert to lowercase
    for (int i = 0; n1[i]; i++) n1[i] = tolower(n1[i]);
    for (int i = 0; n2[i]; i++) n2[i] = tolower(n2[i]);

    int count = countRemaining(n1, n2);
    char r = flamesResult(count);

    printf("\nResult: ");
    switch (r) {
        case 'F': puts("Friends"); break;
        case 'L': puts("Love"); break;
        case 'A': puts("Attraction"); break;
        case 'M': puts("Marriage"); break;
        case 'E': puts("Enemy"); break;
        case 'S': puts("Sister"); break;
    }
    return 0;
}
