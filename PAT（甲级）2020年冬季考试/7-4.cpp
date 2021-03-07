#include <sstream>
#include<stdio.h>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main(){
    set<int> have;
    vector<int> prod;
    map<int,vector<string>> mp;
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        have.insert(tmp);
    }    
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int tmp;
        scanf("%d",&tmp);
        prod.push_back(tmp);
    }
    int k;
    scanf("%d\n",&k);
    for(int i=0;i<k;i++){
        string s;
        int flag = 1;
        getline(cin,s);
        stringstream ss(s);
        int num,last;
        while(ss>>num){
            if(have.find(num)==have.end()){
                flag = 0;
                break;
            }
            last = num;
        }
        if(flag){
            mp[last].push_back(s);
        } 
    }
    for(int i=0;i<m;i++){
        if(have.find(prod[i])!=have.end()){
            printf("%02d -> %02d\n",prod[i],prod[i]);
        }
        else{
            cout<<mp[prod[i]][0]<<"\n";
        }
    }
    return 0;
}