```c++
#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//返回数组[l,r)第一个大于x的值的位置即upper_bound
//lower_bound可由upper_bound尾部加一个while循环改造得到
int binarySearch(vector<int> &nums, int l, int r, long long x) {
	while (l < r) {
		int mid = l + (r - l) / 2;

		if (nums[mid] <= x) {//丢弃左半部及中位数
			l = mid + 1;
		}
		else {
			r = mid;//右边界不收缩=》取左中位数
		}
	}
	/*
	lower_bound: add this part
	while(l!=0 && nums[l]==x) l--;
	if(l!=0) l++;
	*/
	return l;
}
int main()
{
	int N, p, max = -1;
	cin >> N >> p;
	vector<int> input;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < N; i++) {
		int n = binarySearch(input, i, N, (long long)input[i] * p) - i;

		//int n = upper_bound(input + i, input + N, (long long)(input[i])*p) - i;

		max = n > max ? n : max;
	}
	printf("%d", max);
	return 0;
}
```
