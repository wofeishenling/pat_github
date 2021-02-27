#include<stdio.h>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

const int MAXN = 33;
int pre[MAXN],in[MAXN];
int cnt1 = 0,cnt2 = 0;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* creatBT(int prel,int prer,int inl,int inr){
    if(inl > inr) return nullptr;
    int root_val = pre[prel];
    int pos_root_in = inl;
    for(int i=inl;i<=inr;i++){
        if(in[i]==root_val) {
            pos_root_in = i;
            break;
        }
    }
    int num_left = pos_root_in-inl;
    TreeNode* root = new TreeNode();
    root->val = root_val;
    root->left = creatBT(prel+1, prel+num_left, inl, pos_root_in-1);
    root->right = creatBT(prel+num_left+1, prer, pos_root_in+1, inr);
    return root;
}
void postTraversal(TreeNode* root){
    if(root==nullptr) return ;
    postTraversal(root->left);
    postTraversal(root->right);
    printf("%d ",root->val)
    return;
}
int main(){
    int n;
    stack<int> st;
    scanf("%d\n",&n);
    string opt;
    for(int i=0;i<2*n;i++){
        getline(cin,opt);
        if(opt[1]=='u'){
            string tmp(opt.substr(opt.size()-2,2));
            int num;
            sscanf(tmp.c_str(),"%d",&num);
            st.push(num);
            pre[cnt1++] = num;
        }
        else{
            in[cnt2++] = st.top();
            st.pop();
        }
    }
    TreeNode* root = creatBT(0,n-1,0,n-1);
    postTraversal(root);
    return 0;
}