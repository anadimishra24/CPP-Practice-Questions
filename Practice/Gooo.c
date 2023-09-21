#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 100001

int countDistinctShops(char* s, int n, int u, int v) {
    int visited[MAXN] = {0}; // 0 indicates not visited, 1 indicates visited
    int distinctShops = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L' || s[i] == 'R') {
            visited[i] = 1;
            distinctShops++;
        }
    }

    for (int i = u - 1; i <= v - 1; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }

    return distinctShops;
}

int main() {
    char s[MAXN];
    printf("Enter the string s: ");
    scanf("%s", s);

    int n = strlen(s);

    int m;
    printf("Enter the number of queries: ");
    scanf("%d", &m);

    int u[m], v[m];
    printf("Enter the queries (u[i]):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &u[i]);
    }

    printf("Enter the queries (v[i]):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }

    int result[m];
    for (int i = 0; i < m; i++) {
        result[i] = countDistinctShops(s, n, u[i], v[i]);
    }

    printf("Results of the queries:\n");
    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
