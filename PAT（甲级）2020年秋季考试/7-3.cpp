#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;
int in[30];
int pre[30];
struct node{
    int val;
    node* left;
    node* right;
};
node* createT(int inl,int inr,int prel,int prer){
    if(inl>inr) return nullptr;
    int root_val = pre[prel];
    int root_pos = -1;
    for(int i=inl;i<=inr;i++){
        if(in[i]==root_val){
            root_pos = i;
            break;
        }
    }
    int num_left = root_pos - inl;
    node* root = new node();
    root->val = root_val;
    root->left = createT(inl,root_pos-1,prel+1,prel+num_left);
    root->right = createT(root_pos+1, inr, prel+num_left+1, prer);
    return root;
}
vector<vector<int>> ans;
void levelTraversal(node* root){
    queue<node*> Q;
    Q.push(root);
    while(!Q.empty()){
        int size = Q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            node* tmp = Q.front();
            Q.pop();
            level.push_back(tmp->val);
            if(tmp->left) Q.push(tmp->left);
            if(tmp->right) Q.push(tmp->right);
        }
        ans.push_back(level);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    node* root = createT(0,n-1,0,n-1);
    levelTraversal(root);
    for(int i=0;i<ans.size();i++){
        printf("%d",ans[i][0]);
        if(i<ans.size()-1) printf(" ");
    }
    return 0;
}