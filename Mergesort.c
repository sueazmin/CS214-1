#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 5
 
void merge(int a[], int tmp[], int left, int mid, int right);
void msort(int a[], int tmp[], int left, int right);
void merge_sort(int a[], int tmp[], const int size);
void display(int a[],const int size);
 
int main()
{
    int a[SIZE] = {5,6,3,1,7};
    int tmp[SIZE];
 
    printf("--- C Merge Sort Demonstration --- \n");
 
    printf("Array before sorting:\n");
    display(a,SIZE);
 
    merge_sort(a, tmp, SIZE);
 
    printf("Array after sorting:\n");
    display(a,SIZE);
 
    return 0;
}
 
void merge_sort(int a[], int tmp[], const int size)
{
    msort(a, tmp, 0, size - 1);
}
 
void msort(int a[], int tmp[], int left, int right)
{
    int mid;  
    if (right > left)
    {
        mid = (right + left) / 2;        //7+0 3, 3+0 1, 1+0 0, | 
        msort(a, tmp, left, mid);
        //printf("%d\n", mid);
        msort(a, tmp, mid + 1, right);   //1+1
        //printf("%d\n", mid);
       // printf("%d\n", left);
        //printf("%d\n", right);
        merge(a, tmp, left, mid + 1, right); //0 1 1
    }
}
 
void merge(int a[], int tmp[], int left, int mid, int right)
{
    int i, left_end, count, tmp_pos;
    left_end = mid - 1;  // 0
    tmp_pos = left; // 0
    count = right - left + 1; // 2
 
    while ((left <= left_end) && (mid <= right))
    {
        if (a[left] <= a[mid])
        {
            tmp[tmp_pos] = a[left];
                                                printf("%d\n", tmp_pos);

            tmp_pos = tmp_pos + 1;
            left = left +1;
        }
        else
        {
            tmp[tmp_pos] = a[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }
 
    while (left <= left_end)
    {
        tmp[tmp_pos] = a[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right)
    {
        tmp[tmp_pos] = a[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }
 
    for (i = 0; i < count; i++)
    {
          printf("%d\n", tmp[right] );
                                                            printf("%s\n", "hello" );
                                                            printf("%d\n", count );
                                                            printf("%d\n", right );

        a[right] = tmp[right];
        printf("%d\n", a[right] );
        right = right - 1;
    }
}
 
void display(int a[],const int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ",a[i]);
 
    printf("\n");
}