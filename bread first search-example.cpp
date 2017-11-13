#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
struct node{
    int r;
    int c;
};
int source[6][6];
int visit[6][6];
queue < node> que;
node father[10][10];
int d[10][10];
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
vector <node> nodes;
void print_way(node front){
    while(1){
        nodes.push_back(front);
        if(d[front.r][front.c] == 0)
            break;
        front = father[front.r][front.c];
    }
    for(int i = (int)nodes.size() - 1; i >= 0; i--){
        printf("(%d, %d)\n", nodes[i].r, nodes[i].c);
    }
}
void bfs(){
    node ini = {0, 0};
    que.push(ini);
    visit[0][0] = 1;
    d[0][0] = 0;
    while(!que.empty()){
        node front = que.front();
        que.pop();
        if(front.c == 4 && front.r == 4){
            print_way(front);
            return;
        }
        for(int i = 0; i < 4; i++){
            int x1 = front.r + x[i];
            int y1 = front.c + y[i];
            node fre;
            fre.r = x1;
            fre.c = y1;
            if(x1 >= 0 && y1 >= 0 && y1 < 5 && x1 < 5 && source[x1][y1] == 0 && visit[x1][y1] == 0){
                d[x1][y1] = d[front.r][front.c] + 1;
                father[fre.r][fre.c] = front;
                visit[x1][y1] = 1;
                que.push(fre);
            }
        }
    }
}
int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &source[i][j]);
        }
    }
    memset(visit, 0, sizeof(visit));
    bfs();
    return 0;
}