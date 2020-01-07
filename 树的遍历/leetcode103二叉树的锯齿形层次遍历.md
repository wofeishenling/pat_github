```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int flag = 1;
        queue<TreeNode*> q;
        TreeNode* tmp;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            deque<int> levelnodes;
            for(int i=0;i<width;i++){
                tmp=q.front();
                if(flag==1){
                    levelnodes.push_back(tmp->val);
                }else{
                    levelnodes.push_front(tmp->val);
                }
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            vector<int> temp(levelnodes.begin(),levelnodes.end());
            res.push_back(temp);
            flag=-flag;
        }
        return res;
    }
};
```
