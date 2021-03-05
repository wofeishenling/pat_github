#include<stdio.h>
#include<algorithm>

using namespace std;
//双边权最短路径
const int MAXN = 505;
const int INF = 0x3fffffff;
int G_d[MAXN][MAXN],G_t[MAXN][MAXN];
int d[MAXN],t[MAXN],num[MAXN];
bool vis[MAXN];
int path1[MAXN],path2[MAXN];
int n;
void Dijkstra_d(int s){
    //reset global envir
    fill(vis,vis+MAXN,false);
    fill(d,d+MAXN,INF);
    fill(t,t+MAXN,INF);
    fill(num,num+MAXN,0);
    num[s] = 1;
    d[s] = 0;
    t[s] = 0;
    for(int i=0;i<n;i++){
        //-----------------
        int min = INF,u = -1;
        for(int j=0;j<n;j++){
            if(d[j]<min){
                min = d[j];
                u = j;
            }
        }
        if(u==-1) break;
        vis[u] = true;
        for(int v=0;v<n;v++){
            if(G_d[u][v]!=INF && vis[v]){
                if(d[u]+G_d[u][v]<d[v]){
                    d[v] = d[u]+G_d[u][v];
                    t[v] = t[u]+G_t[u][v];
                    num[v] = num[u];
                    path1[v] = u;
                }
                else if(d[u]+G_d[u][v]==d[v]){
                    if(t[u]+G_t[u][v]<t[v]){
                        d[v] = d[u]+G_d[u][v];
                        t[v] = t[u]+G_t[u][v]; 
                        path1[v] = u;
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}
void Dijkstra_t(int s){
    //reset global envir
    fill(vis,vis+MAXN,false);
    fill(d,d+MAXN,INF);
    fill(t,t+MAXN,INF);
    fill(num,num+MAXN,0);
    num[s] = 1;
    d[s] = 0;
    t[s] = 0;
    for(int i=0;i<n;i++){
        //-----------------
        int min = INF,u = -1;
        for(int j=0;j<n;j++){
            if(t[j]<min){
                min = t[j];
                u = j;
            }
        }
        if(u==-1) break;
        vis[u] = true;
        for(int v=0;v<n;v++){
            if(G_t[u][v]!=INF && vis[v]){
                if(t[u]+G_t[u][v]<t[v]){
                    d[v] = d[u]+G_d[u][v];
                    t[v] = t[u]+G_t[u][v];
                    num[v] = num[u];
                    path2[v] = u;
                }
                else if(t[u]+G_t[u][v]==t[v]){
                    if(d[u]+G_d[u][v]<d[v]){
                        d[v] = d[u]+G_d[u][v];
                        t[v] = t[u]+G_t[u][v]; 
                        path2[v] = u;
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}
int main(){
    int m,st,ed,v1,v2,one_way,dis,time;
    scanf("%d%d",&n,&m);
    fill(G_d[0],G_d[0]+MAXN*MAXN,INF);
    fill(G_t[0],G_t[0]+MAXN*MAXN,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d%d",&v1,&v2,&one_way,&dis,&time);
        if(one_way){
            G_d[v1][v2] = dis;
            G_t[v1][v2] = time;
        }
        else{
            G_d[v1][v2] = G_d[v2][v1] = dis;
            G_t[v1][v2] = G_t[v2][v1] = time;
        }
    }
    scanf("%d%d",&st,&ed);
    Dijkstra_d(st);
    Dijkstra_t(st);
    return 0;
}