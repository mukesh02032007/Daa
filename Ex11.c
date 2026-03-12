#include <stdio.h>
#include <conio.h>
struct Pair
{
    int min;
    int max;
};
struct Pair minMax(int arr[], int low, int high)
{
    struct Pair result, left, right;
    int mid;

    if(low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    if(high == low + 1)
    {
        if(arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    mid = (low + high) / 2;
    left = minMax(arr, low, mid);
    right = minMax(arr, mid + 1, high);
    if(left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if(left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;
    return result;
}
void main()
{
    int n, i, arr[100];
    struct Pair result;
    clrscr();
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    result = minMax(arr, 0, n - 1);
    printf("\nMinimum element = %d", result.min);
    printf("\nMaximum element = %d", result.max);
    getch();
}


