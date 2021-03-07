#include <algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;
int K,N,M;
int G[1010][1010];//1~N
struct node{
    vector<int> call_out;
    set<int> call_in;
    bool isSuspect = false;
}V[1010];
bool vis[1010];
void bfs(int s,vector<int>& gang){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i=1;i<=N;i++){
            if(!vis[i]&&V[i].isSuspect&&G[s][i]!=0&&G[i][s]!=0){
                q.push(i);
                vis[i]=true;
                gang.push_back(i);
            }
        }
    }
}
int main(){
    cin >> K >> N >> M;
    int v1,v2,time;
    for(int i=0;i<M;i++){
        cin>>v1>>v2>>time;
        G[v1][v2] += time;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(G[i][j]<5){
                V[i].call_out.push_back(j);
            }
            if(G[i][j]>0) V[j].call_in.insert(i);
        }
    }
    for(int i=1;i<=N;i++){
        int cnt_back = 0;
        for(int j=0;j<V[i].call_out.size();j++){
            if(V[i].call_in.find(V[i].call_out[j])!=V[i].call_in.end()){
                cnt_back++;
            }
        }
        if(V[i].call_out.size()>K && 1.0*cnt_back/V[i].call_out.size()<=0.2) 
            V[i].isSuspect=true;
    }
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        vector<int> temp; 
        if(!vis[i] && V[i].isSuspect){
            bfs(i,temp);
        }
        ans.push_back(temp);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            printf("%d",ans[i][j]);
            if(j<ans[i].size()-1) printf(" ");
        }
        printf("\n");
    }
    if(ans.size()==0) printf("None\n");
    return 0;
}