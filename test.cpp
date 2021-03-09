#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int N;
bool flag = true;
int pre[33],in[33];
struct node{
    int val;
    node* left;
    node* right;
};
node* createT(int inl,int inr,int prel,int prer){
    if(inl>inr) return nullptr;
    int val_root = pre[prel];
    int pos_root_in = inl;
    for(int i=inl;i<=inr;i++){
        if(in[i] == val_root){
            pos_root_in = i;
            break;
        }
    }
    int num_left = pos_root_in - inl;
    node* root = new node();
    root->val = val_root;
    root->left = createT(inl,pos_root_in-1,prel+1,prel+num_left);
    root->right= createT(pos_root_in+1,inr,prel+num_left+1,prer);
    return root;
}
int isAVL(node* root){
    if(root==nullptr) return 0;
    int lh = isAVL(root->left);
    int rh = isAVL(root->right);
    if(abs(lh-rh)>1) flag = false;
    int h = lh>rh?lh:rh;
    return h;
}
int main(){
    cin >> N;
    while(N--){
        int n,tmp;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> tmp;
            pre[i] = in[i] = tmp;
        }
        sort(in,in+n);
        node* root = createT(0,n-1,0,n-1);
        flag = true;
        isAVL(root);
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}