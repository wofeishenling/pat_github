#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
//无边权有向图宜用邻接表处理
const int MAXN = 1010;
vector<int> G[MAXN];
bool inq[MAXN];
int cnt = 0,l_cnt = 0,l;
void BFS(int s){
    queue<int> Q;
    Q.push(s);
    cnt++;
    inq[s] = true;
    while(!Q.empty()){
        int size = Q.size();
        if(++l_cnt>l) break;
        for(int i=0;i<size;i++){
            int temp = Q.front();
            Q.pop();
            for(int j=0;j<G[temp].size();j++){
                if(!inq[G[temp][j]]){
                    Q.push(G[temp][j]);
                    cnt++;
                    inq[G[temp][j]] = true;
                }
            }
        }
    }
}
int main(){
    int n;
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++){
        int k=0;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int tmp;
            scanf("%d",&tmp);
            G[tmp].push_back(i);
        } 
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int tmp;
        scanf("%d",&tmp);
        cnt = 0;
        l_cnt = 0;
        for(int j=0;j<MAXN;j++) inq[j] = false;
        BFS(tmp);
        printf("%d\n",cnt-1);
    }
    return 0;
}