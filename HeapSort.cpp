#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void CreateHeap(int a[], int end)
{
    int finish = 1;
    do
    {
        finish = 1;
        for(int i = 0; (2*i + 1) < end; i++)
        {
            if(a[i] < a[2*i + 1])
            {
                swap(&a[i], &a[2 * i + 1]);
                finish = 0;
            }
            if(a[i] < a[2*i + 2])
            {
                swap(&a[i], &a[2*i + 2]);
                finish = 0;
            }
        }
    }
    while(!finish);
}

void HeapSort(int a[], int end)
{
    CreateHeap(a, end);
    while (end > 0)
    {
        swap(&a[0], &a[end]);
        end--;
        CreateHeap(a, end);
    }
}

int main()
{
    int a[] = {90, 42, 53, 38, 98, 54, 78, 32, 30, 108, 456, 10};
    for (int i  = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        cout << a[i] << '\t' ;
    }
    cout << endl;
    HeapSort(a, sizeof(a)/sizeof(a[0]) - 1);
    for ( int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        cout << a[i] << '\t';
    }
    return 0;
}