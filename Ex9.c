#include <stdio.h>
#include <conio.h>

#define INF 9999
#define MAX 10

int main() {
    int G[MAX][MAX], dist[MAX][MAX];
    int i, j, k, n;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 if no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
            if(G[i][j] == 0 && i != j)
                G[i][j] = INF;   // Replace 0 with INF for no edge
            dist[i][j] = G[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Paths:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    getch();
    return 0;
}



--output--
Enter number of vertices: 4
Enter adjacency matrix:
0 5 0 10
0 0 3 0
0 0 0 1
0 0 0 0
All-Pairs Shortest Paths:
  0   5   8   9
INF   0   3   4
INF INF   0   1
INF INF INF   0
