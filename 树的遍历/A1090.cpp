#include<stdio.h>
#include<vector>

using namespace std;
const int maxn = 100001;
double max_price = -1;
double unit_price,r;
int cnt = 0;
struct node{
    int data;
    vector<int> child;
}static_tree[maxn];

void dfs(int index,int depth){
    if(static_tree[index].child.empty()){
        double cur_price = unit_price*pow(1+r,depth);
        if(cur_price>max_price) {
            max_price = cur_price;
            cnt=1;
        }
        if(cur_price==max_price) cnt++;
        return;
    }
    for(int i=0;i<static_tree[index].child.size();i++){
        dfs(static_tree[index].child[i],depth+1);
    }
}
int main(){
    int N,k,temp,root;
    scanf("%d%lf%lf",&N,&unit_price,&r);
    r = r/100;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        if(temp==-1) {
            root = i;
            continue;
        }
        static_tree[i].child.push_back(temp);
    }
    dfs(root,0);
    printf("%.2f %d",max_price,cnt);
    return 0;
}