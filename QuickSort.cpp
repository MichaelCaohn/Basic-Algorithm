#include <iostream>
#include <stdlib.h>

using namespace std;

void swap( int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int exchange = 1;
        for(int j = 0; j < len - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(&a[j], &a[j+1]);
                exchange = 0;
            }
        }
        if(exchange)
            break;
    }
}

void QuickSort(int a[], int start, int end)
{
    if(start < end)
    {
        int key = a[start];
        int i = start;
        int j = end;
        while(i < j)
        {
            while ( i < j && a[j] >= key)
                --j;
            a[i] = a[j];
            while (i < j && a[i] <= key)
                ++i;
            a[j] = a[i];
        }
        a[i] = key;
        QuickSort(a, start, i - 1);
        QuickSort(a, i + 1, end);
    }
}

int main()
{
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};

    QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}