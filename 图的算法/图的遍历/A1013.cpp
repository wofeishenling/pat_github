#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> G[1010];
bool vis[1010];

void BFS(int v, int broken){
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0;i<G[temp].size();i++){
            if(G[temp][i]!=broken && !vis[G[temp][i]]){
                q.push(G[temp][i]);
                vis[G[temp][i]] = true;
            }
        }
    }
}
int main(){
    int n,m,k;
    int c1,c2;
    vector<int> ans;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d%d",&c1,&c2);
        G[c1].push_back(c2);
        G[c2].push_back(c1);
    }
    for(int i=0;i<k;i++){
        int tmp,cnt=0;
        for(int i=0;i<=n;i++) vis[i] = false;
        scanf("%d",&tmp);
        for(int j=1;j<=n;j++){
            if(!vis[j] && j!=tmp){
                BFS(j,tmp);
                cnt++;
            }
        }
        ans.push_back(cnt-1);
    }
    for(int i=0;i<ans.size();i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}