//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* build_BST(vector<int>& nums,int L,int R){
        //递归边界
        if(L > R) return NULL;
        int mid = L + (R - L)/2;
        TreeNode* T = new TreeNode(nums[mid]);
        T->left = build_BST(nums,L,mid-1);
        T->right= build_BST(nums,mid+1,R);
        return T;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_BST(nums,0,nums.size()-1);
    }
};