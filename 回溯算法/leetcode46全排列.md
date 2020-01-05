```c++
1、回溯解法（深度优先遍历 + 状态重置 + 剪枝）
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(), false);//状态标识
        vector<vector<int>> res;
        vector<int> tmp;
        helper(nums, flag, tmp, res, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<bool>& flag, vector<int>& tmp, vector<vector<int>>& res, int level)
    {
        if (level == nums.size())//递归边界
        {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!flag[i])//用以限制下层递归选择范围
            {
                tmp.push_back(nums[i]);//1
                flag[i] = true;//2

                helper(nums, flag, tmp, res, level + 1);

                tmp.pop_back();//1状态重置
                flag[i] = false;//2上下对称
            }
        }
    }
};
```
