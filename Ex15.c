#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1,j;

    for(j=l;j<r;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[r]);
    return i+1;
}

int random_partition(int arr[],int l,int r)
{
    int i=l+rand()%(r-l+1);
    swap(&arr[i],&arr[r]);
    return partition(arr,l,r);
}

int kthSmallest(int arr[],int l,int r,int k)
{
    int pos;

    if(k>0 && k<=r-l+1)
    {
        pos=random_partition(arr,l,r);

        if(pos-l==k-1)
            return arr[pos];

        if(pos-l>k-1)
            return kthSmallest(arr,l,pos-1,k);

        return kthSmallest(arr,pos+1,r,k-pos+l-1);
    }

    return -1;
}

void main()
{
    int arr[100],n,i,k,result;

    clrscr();
    srand(time(NULL));

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter k value: ");
    scanf("%d",&k);

    result=kthSmallest(arr,0,n-1,k);

    printf("\n%d th smallest element = %d",k,result);

    getch();
}

--output--
Enter number of elements: 6
Enter elements:
12 3 5 7 19 1

Enter k value: 3

3 th smallest element = 5