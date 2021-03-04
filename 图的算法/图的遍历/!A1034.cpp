#include<stdio.h>
#include<string>
#include<map>
#include<iostream>

using namespace std;
map<string,int> name2num;
map<int,string> num2name;
const int MAXN = 1010;
int G[MAXN][MAXN];
int v_weight[MAXN];
int cnt = 0;

int main(){
    int n,k;
    cin >> n >> k;
    string name1,name2;
    int time;
    for(int i=0;i<n;i++){
        cin >> name1 >> name2 >> time;
        if(name2num.find(name1)==name2num.end()){
            name2num[name1] = cnt++;
            num2name[cnt-1] = name1;
        }
        if(name2num.find(name2)==name2num.end()){
            name2num[name2] = cnt++;
            num2name[cnt-1] = name2;
        } 
        G[name2num[name1]][name2num[name2]] += time;
        G[name2num[name2]][name2num[name1]] += time;
        v_weight[name2num[name1]] += time;
        v_weight[name2num[name2]] += time;
    }
    return 0;
}