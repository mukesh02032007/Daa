#include <stdio.h>
#include <conio.h>

#define MAX 10

int main() {
    int reach[MAX][MAX], n;
    int i, j, k;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge, 1 if edge exists):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &reach[i][j]);
        }
    }

    // Warshall’s Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printf("\nTransitive Closure Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }

    getch();
    return 0;
}


--output--
Enter number of vertices: 4
Enter adjacency matrix:
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0
Transitive Closure Matrix:
0 1 1 1
0 0 1 1
0 0 0 1
0 0 0 0
