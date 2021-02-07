// build a tree by inorder and postorder
// layer traversals
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 50;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

int post[maxn], in[maxn];

TreeNode *buildTree(int postL, int postR, int inL, int inR) {
  if (inL < inR)
    return NULL; // boundary
  int root_key = post[postR];
  TreeNode *root = new TreeNode();
  root->val = root_key;
  int k;
  for (int i = inL; i <= inR; i++) {
    if (in[i] == root_key) {
      k = i;
      break;
    }
  }
  int left_n = k - inL;
  int right_n = inR - k;
  root->left = buildTree(postL, postL + left_n - 1, inL, k - 1);
  root->right = buildTree(postL + left_n, postR - 1, k + 1, inR);
  return root;
}
void layerTraversal(TreeNode *T){
    queue<TreeNode*> Q;
    Q.push(T);
    while(!Q.empty()){
        TreeNode* now = Q.front();
        Q.pop();
        printf("%d",now->val);
        if(now->left) Q.push((now->left));
        if(now->right)Q.push((now->right));
    }

}
int main() {
  // read data;
  int n, temp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    post[i] = temp;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    in[i] = temp;
  }
  // build tree
  TreeNode *T = buildTree(0, n - 1, 0, n - 1);
  // layer traversal
  layerTraversal(T);
  return 0;
}