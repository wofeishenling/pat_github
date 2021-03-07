#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;
vector<int> G[1010];
vector<int> num_pre(1010);
int N,M;
vector<int> ans;
bool isVaild(vector<int>& seq){
    vector<int> copy(num_pre);
    for(int i=0;i<N;i++){
        if(copy[seq[i]]==0){
            for(int j=0;j<G[seq[i]].size();j++){
                copy[G[seq[i]][j]]--;
            }
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    cin >> N >> M;
    int v1,v2;
    for(int i=0;i<M;i++){
        cin>>v1>>v2;
        G[v1].push_back(v2);
        num_pre[v2]++;
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        vector<int> seq(N);
        for(int j=0;j<N;j++) cin >> seq[j];
        if(!isVaild(seq)) ans.push_back(i);
    }
    for(int i=0;i<ans.size();i++){
        printf("%d",ans[i]);
        if(i<ans.size()-1) printf(" ");
    }
    return 0;
}