#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int not_root[105];

struct node{
    int val;
    vector<int> child;
}static_tree[105];

int main(){
    int num_node,num_with_children;
    scanf("%d%d",&num_node,&num_with_children);
    int address,num_son,son,root;
    for(int i=0;i<num_with_children;i++){
        scanf("%d%d",&address,&num_son);
        for(int j=0;j<num_son;j++){
            scanf("%d",&son);
            not_root[son] = 1;
            static_tree[address].child.push_back(son);
        }
    }
    for(int i=0;i<num_node;i++){
        if(!not_root[i]){
            root = i;
            break;
        }
    }
    int level = 1,max = -1,cnt = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        if(size > max){
            max = size;
            level = max;
        }
        cnt++;
        for(int i=0;i<size;i++){
            int temp = q.front();
            q.pop();
            for(int j=0;j<static_tree[temp].child.size();j++){
                q.push(static_tree[temp].child[j]);
            }
        }
    }
    return 0;
}