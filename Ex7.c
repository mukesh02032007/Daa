#include <stdio.h>
#include <conio.h>

#define INF 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], dist[MAX], pred[MAX];
    int visited[MAX], count, mindist, nextnode, i, j;

    // Create cost matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(G[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = G[i][j];

    // Initialize distances and visited[]
    for(i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < n-1) {
        mindist = INF;

        // Find the next minimum distance node
        for(i = 0; i < n; i++)
            if(dist[i] < mindist && !visited[i]) {
                mindist = dist[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        // Update distances
        for(i = 0; i < n; i++)
            if(!visited[i])
                if(mindist + cost[nextnode][i] < dist[i]) {
                    dist[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }

        count++;
    }

    // Print shortest paths
    for(i = 0; i < n; i++) {
        if(i != start) {
            printf("\nDistance from %d to %d = %d", start, i, dist[i]);
            printf("\nPath = %d", i);
            j = i;
            while(j != start) {
                j = pred[j];
                printf(" <- %d", j);
            }
        }
    }
}

int main() {
    int G[MAX][MAX], i, j, n, start;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 0 if no edge):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    dijkstra(G, n, start);

    getch();
    return 0;
}

--output--
Enter number of vertices: 4
Enter adjacency matrix:
0 5 9 0
5 0 2 3
9 2 0 1
0 3 1 0
Enter starting vertex (0 to 3): 0
Distance from 0 to 1 = 5
Path = 1 <- 0

Distance from 0 to 2 = 7
Path = 2 <- 1 <- 0

Distance from 0 to 3 = 8
Path = 3 <- 2 <- 1 <- 0
