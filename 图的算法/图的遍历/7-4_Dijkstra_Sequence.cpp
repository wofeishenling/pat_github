#include <cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
const int INF = 0x3fffffff;
const int MAXV = 1010;
int G[MAXV][MAXV];
int d[MAXV];
vector<int> path[1010];
int n,m;
bool vis[MAXV];

bool Dijkstra(vector<int>& input,int s){
    memset(vis,0,sizeof(vis));
    fill(d,d+MAXV,INF);
    d[s] = 0;
    for(int i=0;i<n;i++){
        int u = -1,min = INF;
        for(int j=1;j<=n;j++){
            if(!vis[j] && d[j]<min){
                min = d[j];
                u = j;
            }
        }
        if(d[input[i]]==min){
            u = input[i];
        }else return false;
        vis[u] = true;
        for(int v=1;v<=n;v++){
            if(!vis[v] && G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v] = d[u]+G[u][v];
                }
            }
        }
    }
    return true;
}
int main(){
    int v1,v2,dis;
    scanf("%d%d",&n,&m);
    fill(G,G+MAXV*MAXV,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&v1,&v2,&dis);
        G[v1][v2] = dis;
        G[v2][v1] = dis;
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        vector<int> input;
        for(int j=0;j<n;j++){
            int tmp;
            scanf("%d",&tmp);
            input.push_back(tmp);
        }
        if(Dijkstra(input,input[0])){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}