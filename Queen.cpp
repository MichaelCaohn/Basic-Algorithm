#include <iostream>
#include <math.h>

#define QUEEN 8
#define INITIAL -10000

using namespace std;

int a[QUEEN];

void init(){
    int* p;
    for(p = a; p < a + QUEEN; p++)
        *p = INITIAL;
}
int valid(int row, int col){
    for(int i = 0; i < QUEEN; i++){
        if(a[i] == col || abs(a[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}
void print(){
    for(int i = 0; i < QUEEN; i++){
        for(int j = 0; j < QUEEN; j++){
            if(a[i] != j)
                printf("%c ", '#');
            else
                printf("%c ", 'Q');
        }
        printf("\n");
    }
    for(int i = 0; i < QUEEN; i++)
        printf("%d ", a[i]);
    printf("\n\n");
}
void queen(){
    int i = 0, j = 0, n = 0, count = 0;
    while(i < QUEEN){
        while(j < QUEEN){
            if(valid(i, j)){
                a[i] = j;
                j = 0;
                break;
            }
            else
                j++;
        }
        if(a[i] == INITIAL){
            if(i == 0){ //因为回溯了，所以回溯到1的时候要自动跳出，不能够通过 i<QUEEN 来判断
                printf("%d  %d\n", n, ++count);
                break;
            }
            else{
                i--;
                j = a[i] + 1;
                a[i] = INITIAL;
                continue;
            }
        }
        if(i == QUEEN - 1){
            printf("Answer %d: \n", ++n);
            print();
            j = a[i] + 1;
            a[i] = INITIAL;
            continue;
        }
        i++;
    }
}
int main(){
    init();
    queen();
    return 0;
} 