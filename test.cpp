#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int quick_select(vector<int>& nums,vector<int>::iterator first,vector<int>::iterator last,int k){
        int pivot = *first;
        vector<int>::iterator p = partition(first,last,[pivot](const int &a){ return a>pivot; });//lambda
        if(first + k == p) return pivot;
        if(first + k < p) 
            return quick_select(nums,first,p,k);//第三个参数范围应该是0 -> p-first
        else if(first + k > p)
            return quick_select(nums,p+1,last,(first+k)-p-1);//第三参数应该能取0
        return -1;
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