#include<vector>
using namespace std;
//二分查找有很多种写法，这里将c++库函数中的源码作为一种模板记忆
//该模板有很好的适应性.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0,r = nums.size();
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid]<=target)//等号不能少，相当于upper_bound(l,r,t)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};