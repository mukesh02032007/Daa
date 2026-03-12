#include<stdio.h>
#include<conio.h>

#define MAX 10

int n;
int graph[MAX][MAX];
int visited[MAX];
int min_cost = 9999;

/* Optimal TSP using simple recursion */
void tsp(int city, int count, int cost)
{
    int i;

    if(count == n && graph[city][0] != 0)
    {
        cost = cost + graph[city][0];

        if(cost < min_cost)
            min_cost = cost;

        return;
    }

    for(i=0;i<n;i++)
    {
        if(!visited[i] && graph[city][i])
        {
            visited[i]=1;
            tsp(i,count+1,cost+graph[city][i]);
            visited[i]=0;
        }
    }
}

/* Approximation using Nearest Neighbor */
int nearest_neighbor()
{
    int cost=0;
    int i,j,next,min;
    int visited2[MAX]={0};

    int current=0;
    visited2[0]=1;

    for(i=1;i<n;i++)
    {
        min=9999;

        for(j=0;j<n;j++)
        {
            if(!visited2[j] && graph[current][j] && graph[current][j]<min)
            {
                min=graph[current][j];
                next=j;
            }
        }

        visited2[next]=1;
        cost+=min;
        current=next;
    }

    cost+=graph[current][0];

    return cost;
}

void main()
{
    int i,j;
    int approx_cost;
    float error;

    clrscr();

    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    for(i=0;i<n;i++)
        visited[i]=0;

    visited[0]=1;

    tsp(0,1,0);

    approx_cost = nearest_neighbor();

    error = ((approx_cost - min_cost)*100.0)/min_cost;

    printf("\nOptimal cost = %d",min_cost);
    printf("\nApproximate cost = %d",approx_cost);
    printf("\nApproximation Error = %f %%",error);

    getch();
}

--output--
Enter number of cities: 4

Enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

Optimal cost = 80
Approximate cost = 80
Approximation Error = 0.000000 %