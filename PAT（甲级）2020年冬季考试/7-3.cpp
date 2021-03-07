#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int>> ans;
vector<int> path(1010,0);
int main(){
    int n,k,cur_l=-1;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        string input;
        getline(cin,input);
        int level=0;
        for(;level<input.size();level++){
            if(input[level]!=' ') break;
        }
        int num;
        sscanf(input.c_str(),"%d",&num);
        path[level] = num;
        vector<int> tmp(path.begin(),path.begin()+level+1);
        ans[num] = tmp;
    }
    scanf("%d",&k);
    int q;
    for(int i=0;i<k;i++){
        scanf("%d",&q);
        if(ans.find(q)!=ans.end()){
            for(int j=0;j<ans[q].size();j++){
                printf("%04d",ans[q][j]);
                if(j<ans[q].size()-1) printf("->");
            }
            printf("\n");
        }else{
            printf("Error: %04d is not found.\n",q);
        }
    }
    return 0;
}