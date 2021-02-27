#include<stdio.h>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
    int left;
    int right;
    int val;
    node(){
        val = 0;
        left = -1;
        right = -1;
    };
}static_tree[20];
int inq[20];
void invert(int root){
    if(root == -1) return;
    invert(static_tree[root].left);
    invert(static_tree[root].right);
    swap(static_tree[root].left,static_tree[root].right);
    return ;
}
void levelTraversal(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        printf("%d ",static_tree[temp].val);
        if(static_tree[temp].left!=-1) q.push(static_tree[temp].left);
        if(static_tree[temp].right!=-1) q.push(static_tree[temp].right);
    }
    return;
}
int main(){
    int n,root;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        char l,r;
        scanf("%c %c",&l,&r);
        if(l != '-') {static_tree[i].val = l - '0';inq[l-'0'] = 1;}
        if(r != '-') {static_tree[i].val = r - '0';inq[r-'0'] = 1;}
        static_tree[i].val = i;
    }
    for(int i=0;i<n;i++){
        if(inq[i] == 0){
            root = i;
            break;
        }
    }
    invert(root);
    levelTraversal(root);
    //inorderTraversal(root);
    return 0;
}