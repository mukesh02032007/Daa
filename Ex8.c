#include <stdio.h>
#include <conio.h>

#define INF 9999
#define MAX 10

int main() {
    int G[MAX][MAX], visited[MAX], n;
    int i, j, u, v, min, total_cost = 0;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 if no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
            if(G[i][j] == 0)
                G[i][j] = INF;   // Replace 0 with INF for no edge
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;  // Start from vertex 0

    printf("\nEdges in MST:\n");

    for(i = 0; i < n-1; i++) {
        min = INF;
        for(u = 0; u < n; u++) {
            if(visited[u]) {
                for(v = 0; v < n; v++) {
                    if(!visited[v] && G[u][v] < min) {
                        min = G[u][v];
                        j = u;
                        k = v;
                    }
                }
            }
        }
        visited[k] = 1;
        printf("%d -> %d  cost = %d\n", j, k, min);
        total_cost += min;
    }

    printf("\nMinimum cost of spanning tree = %d", total_cost);

    getch();
    return 0;
}


--output--
Enter number of vertices: 4
Enter adjacency matrix:
0 5 8 0
5 0 10 15
8 10 0 20
0 15 20 0
Edges in MST:
0 -> 1  cost = 5
0 -> 2  cost = 8
1 -> 3  cost = 15

Minimum cost of spanning tree = 28
