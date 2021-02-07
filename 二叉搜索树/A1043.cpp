#include<stdio.h>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

vector<int> orgin,pre,preM,post,postM;

void insert_BST(TreeNode* &root,int data){
    if(root == NULL){
	root = new TreeNode();
	root->data = data;
	root->left = NULL;
	root->right= NULL;
	return;
    }
    if(data < root->data) insert_BST(root->left,data);
    else insert_BST(root->right,data);
}
void preOrder(TreeNode* root,vector<int>& pre){
    if(!root) return;
    pre.push_back(root->data);
    preOrder(root->left,pre);
    preOrder(root->right,pre);
}
void preOrderMirror(TreeNode* root,vector<int>& pre){
    if(!root) return;
    pre.push_back(root->data);
    preOrderMirror(root->right,pre);
    preOrderMirror(root->left,pre);
}
void postOrder(TreeNode* root,vector<int>& pre){
    if(!root) return;
    postOrder(root->left,pre);
    postOrder(root->right,pre);
    pre.push_back(root->data);
}
void postOrderMirror(TreeNode* root,vector<int>& pre){
    if(!root) return;
    postOrderMirror(root->right,pre);
    postOrderMirror(root->left,pre);
    pre.push_back(root->data);
}

int main(){
    int n, Data;
    TreeNode* root = NULL;
    scanf("%d",&n);
    //build BST
    while(n--){
        scanf("%d",&Data);
        orgin.push_back(Data);
        insert_BST(root,Data);
    }
    preOrder(root,pre);
    preOrderMirror(root,preM);
    postOrder(root,post);
    postOrderMirror(root,postM);
    if(orgin == pre){
        printf("YES\n");
        for(int i = 0;i<post.size()-1;i++)
            printf("%d ",post[i]);
        printf("%d",post[post.size()-1]);
    }
    else if(orgin == preM){
        printf("YES\n");
        for(int i = 0;i<postM.size()-1;i++)
            printf("%d ",postM[i]);
        printf("%d",post[postM.size()-1]);
    }
    else printf("NO\n");
    return 0;
}