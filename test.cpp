#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int quick_select(vector<int>& nums,vector<int>::iterator first,vector<int>::iterator last,int k){
        //把第k+1大/小的元素放到正确的位置上，quick_select
        nth_element(first,first+k,last,[](const int &a, const int &b){return a>b;});
        return nums[k];
    }
int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums,nums.begin(),nums.end(),k-1);//ch index start by 0 第k转化为下标为k-1
}
int main(){
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    findKthLargest(nums,7);
	system("pause");
    return 0;
}