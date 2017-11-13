#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert_sort(int a[], int len){
    int i, j, k, temp;
    for(i= 1; i < len; i++){
        for(j = i - 1 ; j >= 0; j--){
            if(a[j] < a[i])
                break;
        }
        if(j != i - 1){
            temp = a[i];
            for(k = i - 1; k > j; k--){
                a[k+1] = a[k];
            }
            a[j + 1] = temp;
        }
    }
    /*for(i = 1; i < len; i++){
        if(a[i] < a[i - 1]){
            temp = a[i];
            for(j = i - 1; j >= 0 && a[j] > temp; j--){
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }

    }*/
}

void shellsort(int a[], int len){
    int i, j, gap;
    for(gap = len/2; gap > 0; gap /=2){
        for(i = gap; i < len; i++){
            for(j = i; j > 0 && a[j] < a[j - gap]; j -= gap)
                swap(&a[j], &a[j - gap]);
        }
    }
}



int main() {
    int a[] = {90, 60, 4, 23, 89, 67, 789, 18, 30, 456, 87, 56768798};
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        cout << a[i] << '\t';
    }
    cout << endl;
    shellsort(a, sizeof(a)/sizeof(a[0]) - 1);
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << '\t';
    cout << endl;
    insert_sort(a, sizeof(a)/sizeof(a[0]) - 1);
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << '\t';
    return 0;
}