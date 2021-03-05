#include<stdio.h>
#include<set>
#include<map>
#include<vector>

using namespace std;
map<int,vector<int>> mp;
int input[10010];
int milk[10010];

int main(){
    int n;
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
        mp[input[i]].push_back(i);
    }
    for(auto e:mp){
        int weight = e.first;
        for(int i=0;i<e.second.size();i++){
            int max = 100;
            int flag = 0;
            if(input[e.second[i]]>input[e.second[i]-1]){
                if(milk[e.second[i-1]]>max){
                    max = milk[e.second[i-1]];
                    flag = 1;
                }
            }
            if(input[e.second[i]]>input[e.second[i]+1]){
                if(milk[e.second[i+1]]>max){
                    max = milk[e.second[i+1]];
                    flag = 1;
                }
            }
            if(flag) max+=100;
            milk[e.second[i]] = max;
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++) sum+=milk[i];
    printf("%d",sum);
    return 0;
}