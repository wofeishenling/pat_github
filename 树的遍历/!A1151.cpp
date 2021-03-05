#include<stdio.h>

using namespace std;
const int MAXN = 1010;
int in[MAXN],pre[MAXN];
struct node{
    int val;
    node* left;
    node* right;
};
node* createT(int inl,int inr,int prel,int prer){
    if(inl>inr) return nullptr;
    int val_root = pre[prel];
    int pos_root = inl;
    for(int i=inl;i<=inr;i++){
        if(in[i]==val_root){
            pos_root = i;
            break;
        }
    }
    int num_left = pos_root-inl;
    node* root = new node();
    root->val = val_root;
    root->left = createT(inl,pos_root-1,prel+1,prel+num_left);
    root->right = createT(pos_root+1,inr,prel+num_left+1,prer);
    return root;
}
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&pre[i]);
    }
    createT(0, n-1, 0, n-1);
    return 0;
}