#include<stdio.h>
#include<algorithm>

using namespace std;
const int MAXV = 505;
const int INF = 0x3fffffff;
//图信息记录数组：
//邻接矩阵、点权数组
//路径信息记录数组：
//最短距离数组、最大点权和、最短路径条数
int G[MAXV][MAXV];
int v_weight[MAXV];
int d[MAXV],w[MAXV],num[MAXV];
bool vis[MAXV];

int n,m,st,ed;

void Dijkstra(int s){
    fill(d,d+MAXV,INF);
    memset(w,0,sizeof(w));
    memset(num,0,sizeof(num));
    d[s] = 0;
    w[s] = v_weight[s];
    num[s] = 1;
    //固定的n次循环
    for(int i=0;i<n;i++){
        //get min next pos in which can achieve
        int u = -1,min = INF;
        for(int j=0;j<n;j++){
            if(!vis[j] && d[j]<min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) break;
        //let we use u as medium v
        vis[u] = true;
        for(int v=0;v<n;v++){
            if(!vis[v] && G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v] = d[u]+G[u][v];
                    w[v] = w[u]+v_weight[v];
                    num[v] = num[u];
                }
                else if(d[u]+G[u][v]==d[v]){
                    num[v] += num[u];
                    if(w[u]+v_weight[v]>w[v]){
                        w[v] = w[u]+v_weight[v];
                    }
                }

            }
        }
    }
}

int main(){
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    for(int i=0;i<n;i++){
        scanf("%d",&v_weight[i]);
    }
    int c1,c2,dis;
    fill(G,G+MAXV*MAXV,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&c1,&c2,&dis);
        G[c1][c2] = dis;
        G[c2][c1] = dis;
    }
    Dijkstra(st);
    printf("%d %d",num[ed],w[ed]);
    return 0;
}