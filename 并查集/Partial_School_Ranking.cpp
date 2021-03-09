#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

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
struct node{
    int id;
    int num_stu;
    int total_score;
};
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
            Union(lead,teammate);
        }
        cin >> sco;
        score[lead] = sco;
    }
    for(auto e:total_number){
        mp[findFather(e)].insert(e);
    }
    vector<node> ans;
    for(auto e:mp){
        node tmp;
        tmp.id = *e.second.begin();
        tmp.num_stu = e.second.size();
        int sum = 0;
        for(int v:e.second) sum+=score[v];
        tmp.total_score = sum;
        ans.push_back(tmp);
    }
    sort(ans.begin(),ans.end(),[](node& a,node& b){
        if(a.total_score!=b.total_score) return a.total_score>b.total_score;
        if(a.num_stu!=b.num_stu) return a.num_stu<b.num_stu;
        return a.id<b.id;
    });
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%04d %d %d\n",ans[i].id,ans[i].num_stu,ans[i].total_score);
    }
    return 0;
}