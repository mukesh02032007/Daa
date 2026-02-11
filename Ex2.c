Linear Search #include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
void main()
{
    int gd = DETECT, gm;
    int arr[1000], i, n, idx = 0;
    int x[10], yBest[10], yAvg[10], yWorst[10];
    int key;
    clock_t start, end;
    double best, avg, worst;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    /* Draw Axes */
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);
    line(50, 400, 50, 50);     // Y-axis
    line(50, 400, 600, 400);   // X-axis
    outtextxy(60, 40, "Time / Comparisons");
    outtextxy(480, 420, "Input Size (n)");
    printf("n\tBest\tAverage\tWorst\n");
    printf("-----------------------------------\n");
    for (n = 10; n <= 100; n += 10)
    {
        for (i = 0; i < n; i++)
            arr[i] = i + 1;
        /* BEST CASE */
        key = arr[0];
        start = clock();
        for (i = 0; i < n; i++)
            if (arr[i] == key) break;
        end = clock();
        best = (double)(end - start) / CLOCKS_PER_SEC;
        /* AVERAGE CASE */
        key = arr[n / 2];
        start = clock();
        for (i = 0; i < n; i++)
            if (arr[i] == key) break;
        end = clock();
        avg = (double)(end - start) / CLOCKS_PER_SEC;
        /* WORST CASE */
        key = arr[n - 1];
        start = clock();
        for (i = 0; i < n; i++)
            if (arr[i] == key) break;
        end = clock();
        worst = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t%f\t%f\t%f\n", n, best, avg, worst);
        /* Store graph points */
        x[idx] = 50 + n * 5;
        yBest[idx]  = 380;               // constant
        yAvg[idx]   = 400 - (n * 2);      // linear
        yWorst[idx] = 400 - (n * 3);      // steeper
        idx++;
    }
    /* BEST CASE GRAPH */
    setcolor(GREEN);
    for (i = 0; i < idx - 1; i++)
        line(x[i], yBest[i], x[i+1], yBest[i+1]);
    /* AVERAGE CASE GRAPH */
    setcolor(BLUE);
    for (i = 0; i < idx - 1; i++)
        line(x[i], yAvg[i], x[i+1], yAvg[i+1]);
    /* WORST CASE GRAPH */
    setcolor(RED);
    for (i = 0; i < idx - 1; i++)
        line(x[i], yWorst[i], x[i+1], yWorst[i+1]);
    /* Legend */
    setcolor(GREEN); outtextxy(420, 80, "Best Case");
    setcolor(BLUE);  outtextxy(420, 100, "Average Case");
    setcolor(RED);   outtextxy(420, 120, "Worst Case");
    getch();
    closegraph();
}
