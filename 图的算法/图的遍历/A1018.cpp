#include<stdio.h>
#include<algorithm>

using namespace std;
const int MAXV = 505;
const int INF = 0x3fffffff;
int G[MAXV][MAXV];
int weight[MAXV];
int d[MAXV],w[MAXV];
bool vis[MAXV];

int cmax,n,ed,m;
void Dijkstra(int s){
    fill(d,d+MAXV*MAXV,INF);
    memset(w,0,sizeof(w));
    d[s] = 0;
    w[s] = 0;
    for(int i=0;i<n;i++){
        int u = -1,min = INF;
        for(int j=0;j<n;j++){
            if(!vis[j] && d[j]<min){
                min = d[j];
                u = j;
            }
        }
        if(u==-1) break;
        vis[u] = true;
        for(int v=0;v<n;v++){
            if(G[u][v]!=INF && !vis[v]){
                if(d[u]+G[u][v]<d[v]){
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                }
                else if(d[u]+G[u][v]==d[v]){
                    
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&cmax,&n,&ed,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    int c1,c2,time;
    fill(G,G+MAXV*MAXV,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&c1,&c2,&time);
        G[c1][c2] = time;
        G[c2][c1] = time;
    }
    Dijkstra(0);
    return 0;
}