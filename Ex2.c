#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
int main()
{
    int gd = DETECT, gm;
    int n, x, y;
    int best, avg, worst;
    clock_t start, end;
    double time_taken;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    /* Draw axes */
    line(50, 400, 50, 50);     // Y-axis
    line(50, 400, 600, 400);   // X-axis
    outtextxy(60, 40, "Comparisons");
    outtextxy(520, 410, "Input Size (n)");
    start = clock();  /* Start timing */
    for (n = 10; n <= 100; n += 10)
    {
        x = 50 + (n * 5);
        /* Binary Search comparisons */
        best = 1;
        avg = (int)(log(n) / log(2));
        worst = avg;
        /* Best Case - GREEN circle */
        setcolor(GREEN);
        circle(x, 400 - best * 20, 3); // radius 3 pixels
        floodfill(x, 400 - best * 20, GREEN);
        /* Average Case - BLUE circle */
        setcolor(BLUE);
        circle(x, 400 - avg * 20, 3);
        floodfill(x, 400 - avg * 20, BLUE);
        /* Worst Case - RED circle */
        setcolor(RED);
        circle(x, 400 - worst * 20, 3);
        floodfill(x, 400 - worst * 20, RED);
    }
    end = clock();  /* End timing */
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    setcolor(WHITE);
    outtextxy(60, 420, "Time taken (seconds): ");
    printf("%f", time_taken);
    /* Labels */
    setcolor(GREEN);
    outtextxy(420, 80, "Best Case");
    setcolor(BLUE);
    outtextxy(420, 100, "Average Case");
    setcolor(RED);
    outtextxy(420, 120, "Worst Case");
    getch();
    closegraph();
    return 0;
}
