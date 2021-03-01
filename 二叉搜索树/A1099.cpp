#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
    int val;
    int left;
    int right;
    node(){
        left = -1;
        right = -1;
    };
}SBT[110];

priority_queue<int> input;
void SBT_inTraversal(int root){
    if(root==-1) return;
    SBT_inTraversal(SBT[root].left);
    SBT[root].val = input.top();
    input.pop();
    SBT_inTraversal(SBT[root].right); 
    return ;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&SBT[i].left,&SBT[i].right); 
    }
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        input.push(temp);
    }
    SBT_inTraversal(0);
    return 0;
}