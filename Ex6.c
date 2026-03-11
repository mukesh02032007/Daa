#include <stdio.h>
#include <conio.h>

#define MAX 10

int visited[MAX], adj[MAX][MAX], n;

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);   // Print the visited vertex

    for(i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    getch();
    return 0;
}


--output--
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex (0 to 3): 0
DFS Traversal: 0 1 3 2
