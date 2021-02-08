#include<stdio.h>
#include<vector>

using namespace std;
const int maxn = 100001;
double total_sales = 0;
double unit_price,r;
struct node{
    int data;
    vector<int> child;
}static_tree[maxn];
void dfs(int index,int depth){
    if(static_tree[index].child.empty()){
        total_sales += 
            (static_tree[index].data*(unit_price)*pow(1+r,depth));
    }
    for(int i=0;i<static_tree[index].child.size();i++){
        dfs(static_tree[index].child[i],depth+1);
    }
}
int main(){
    int N,k,temp;
    scanf("%d%lf%lf",&N,&unit_price,&r);
    r = r/100;
    for(int i=0;i<N;i++){
        scanf("%d",&k);
        if(k==0){
            scanf("%d",&temp);
            static_tree[i].data = temp;
        }
        else{
            for(int j=0;j<k;j++){
                scanf("%d",&temp);
                static_tree[i].child.push_back(temp);
            }
        }
    }
    dfs(0,0);
    printf("%.1f",total_sales);
    return 0;
}