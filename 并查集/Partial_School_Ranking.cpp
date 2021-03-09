#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;
int score[10001];
int N;
int father[10001];
int findFather(int x){
    if(father[x]==x) return x;
    return father[x] = findFather(father[x]);
}
void Union(int a,int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa!=fb) father[fa] = fb;
}
void init(){
    for(int i=0;i<10001;i++) father[i] = i;
}
int main(){
    cin >> N;
    init();
    set<int> total_number;
    map<int,set<int>> mp;
    int lead,num,teammate,sco;
    for(int i=0;i<N;i++){
        cin >> lead;
        total_number.insert(lead);
        cin >> num;
        for(int j=0;j<num;j++){
            cin >> teammate;
            total_number.insert(teammate);
            if(father[teammate]==teammate){
                father[teammate]=lead;
            }
            else{
                father[findFather(teammate)] = lead;
            }
        }
        cin >> sco;
        score[lead] = sco;
    }
    for(auto e:total_number){
        mp[findFather(e)].insert(e);
    }
    
    return 0;
}