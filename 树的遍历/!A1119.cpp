#include<stdio.h>

using namespace std;
int pre[33],post[33];
struct node{
    int val;
    node* left;
    node* right;
    node(){
        val = 0;
        left = nullptr;
        right = nullptr;
    }
};
node* createT(int prel,int prer,int postl,int postr){
    if(prer==prel){
        node* root = new node();
        root->val = pre[prel];
        return root;
    }
    if(prer-prel==1){
        node* root = new node();
        root->val = pre[prel];
        node* l = new node();
        l->val = pre[prer];
        root->left = l;
        return root;
    }
    node* root = new node();
    root->val = pre[prel];
    int pos_pre = prel+1;
    int pos_post;
    for(int i=postl;i<=postr-1;i++){
        if(post[i]==pre[prel+1]){
           pos_post = i;
           break; 
        }
    }
    if(pos_post==postr-1){
        root->left = nullptr;
        root->right = 
    }
    root->left = createT(, int prer, int postl, int postr)
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);
    createT(0,n-1,0,n-1);
    return 0;
}