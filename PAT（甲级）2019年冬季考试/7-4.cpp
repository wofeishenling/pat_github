#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
int in[33];
struct node{
    int val;
    node* left;
    node* right;
};
vector<int> ans;
void levelTraversal(node* root){
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        node* tmp = Q.front();
        Q.pop();
        ans.push_back(tmp->val);
        if(tmp->left) Q.push(tmp->left);
        if(tmp->right) Q.push(tmp->right);
    }
}
node* createT(int inl,int inr){
    if(inl>inr) return NULL;
    int min = in[inl];
    int pos_min = inl;
    for(int i=inl;i<=inr;i++){
        if(in[i]<min){
            min = in[i];
            pos_min = i;
        }
    }
    node* root = new node();
    root->val = min;
    root->left = createT(inl,pos_min-1);
    root->right = createT(pos_min+1,inr);
    return root;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    node* root;
    root = createT(0,n-1);
    levelTraversal(root);
    for(int i=0;i<ans.size();i++){
        printf("%d",ans[i]);
        if(i<n-1) printf(" ");
    }
    return 0;
}