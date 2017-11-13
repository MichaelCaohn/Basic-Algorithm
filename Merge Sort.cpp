#include <iostream>

using namespace std;


void join(int a[], int start, int mid, int end){
    int n1 = mid - start + 1, n2 = end - mid;
    int L1[n1], L2[n2];
    for(int i = 0; i < n1; i++)
        L1[i] = a[start + i];
    for(int i = 0; i < n2; i++)
        L2[i] = a[mid + i + 1];
    /*for(int i = 0; i < n1; i++)
        printf("%d ", L1[i]);
    printf("\n");
    for(int i = 0; i < n2; i++)
        printf("%d ", L2[i]);
    printf("\n");*/
    int l1 = 0, l2 = 0;
    while(l1 < n1 && l2 < n2){
        if(L1[l1] < L2[l2])
            a[start++] = L1[l1++];
        else
            a[start++] = L2[l2++];
    }
    while(l2 < n2){
        a[start++] = L2[l2++];
    }
    while(l1 < n1){
        a[start++] = L1[l1++];
    }

}
void merge_sort(int a[], int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        merge_sort(a, start, mid);
        merge_sort(a, mid + 1, end);
        join(a, start, mid, end);
    }
    return;
}
void print(int a[], int end){
    for(int i = 0; i < end; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main(){
    int arr[] = {12, 11, 13, 5, 6, 7, 1, 29, 23490, 2};
    print(arr, sizeof(arr)/sizeof(arr[0]) - 1);
    merge_sort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    print(arr, sizeof(arr)/sizeof(arr[0]));
}