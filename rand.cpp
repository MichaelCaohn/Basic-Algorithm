#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

double random(double start, double end1){
    return start + (end1 - start)*rand()/(RAND_MAX + 1);
}
int main(){
    /*int N = 9;
    srand((unsigned)time(NULL));
    for(int i = 0; i <= 10; i++){
        cout << rand()%N << endl;
    }*/
    for(int i = 0; i <= 10; i++){
        cout << RAND_MAX << '\t' << int(random(1,10)) << endl;
    }
    /*for(int i = 0; i < 1000; i++){
        cout << rand() << endl;
    }*/
    return 0;
}
//�ڵ���rand()֮ǰҪ�ȵ���srand(time(NULL)),�����ÿ��rand()��������rand()����һ����
