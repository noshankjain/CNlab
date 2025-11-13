#include <stdio.h>

#define INF 999  // Infinity value

int main() {
    int cost[20][20], dist[20][20], via[20][20];
    int n, i, j, k;
    int updated;

    printf("Enter the number of routers: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (use 999 for no direct link):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];

            if (i != j && cost[i][j] != INF)
                via[i][j] = j;
            else
                via[i][j] = -1;
        }
    }

    // Distance Vector Algorithm
    do {
        updated = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if (dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        via[i][j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    // Print final routing tables
    printf("\nFinal Routing Tables:\n");
    for (i = 0; i < n; i++) {
        printf("\nRouter %d:\n", i + 1);
        printf("Destination\tCost\tNext Hop\n");
        for (j = 0; j < n; j++) {
            if (i != j) {
                if (via[i][j] != -1)
                    printf("%d\t\t%d\t\t%d\n", j + 1, dist[i][j], via[i][j] + 1);
                else
                    printf("%d\t\t%d\t\t-\n", j + 1, dist[i][j]);
            }
        }
    }

    return 0;
}
