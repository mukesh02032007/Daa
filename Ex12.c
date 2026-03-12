#include<stdio.h>
#include<conio.h>
#include<time.h>
int a[1000], temp[1000];
/* MERGE FUNCTION */
void merge(int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];

    while(j<=high)
        temp[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=temp[i];
}
/* MERGE SORT */
void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}
/* QUICK SORT */
void quicksort(int low,int high)
{
    int i,j,pivot,temp;
    if(low<high)
    {
        pivot=a[low];
        i=low;
        j=high;
        while(i<j)
        {
            while(a[i]<=pivot && i<high)
                i++;
            while(a[j]>pivot)
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        a[low]=a[j];
        a[j]=pivot;

        quicksort(low,j-1);
        quicksort(j+1,high);
    }
}
void main()
{
    int n,i;
    clock_t start,end;
    double time;
    clrscr();
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    /* MERGE SORT TIME */
    start=clock();
    mergesort(0,n-1);
    end=clock();
    time=((double)(end-start))/CLK_TCK;
    printf("\nTime taken for Merge Sort = %f",time);
    printf("\nSorted array (Merge Sort):\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    /* QUICK SORT TIME */
    printf("\n\nEnter elements again:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    start=clock();
    quicksort(0,n-1);
    end=clock();
    time=((double)(end-start))/CLK_TCK;
    printf("\nTime taken for Quick Sort = %f",time);
    printf("\nSorted array (Quick Sort):\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    getch();
}
