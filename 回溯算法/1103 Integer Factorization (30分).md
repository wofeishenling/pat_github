```c++
实际上是子集问题的两种模板
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> np,ans,tmp;
int n, k, p, maxn=0;
void DFS(int sum,int nofp,int sumofn,int upper)
{
	if (sum > n || nofp > k) return;
	if (sum == n && nofp == k)
	{
		if (sumofn > maxn)
		{
			maxn = sumofn;
			ans = tmp;
		}
		return;
	}
	if (upper > 0)
	{
		tmp.push_back(upper);
		DFS(sum + np[upper], nofp + 1, sumofn + upper, upper);
		tmp.pop_back();
		DFS(sum, nofp, sumofn, upper - 1);
	}
}
int main()
{
	cin >> n >> k >> p;
	for (int i = 0; pow(i, p) <= n; i++)
	{
		np.push_back(pow(i, p));
	}
	DFS(0, 0, 0, np.size() - 1);
	if (ans.size() == 0)
	{
		printf("Impossible");
	}
	else
	{
		printf("%d = ", n);
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d^%d", ans[i], p);
			if (i < ans.size() - 1) printf(" + ");
		}
	}
	system("pause");
	return 0;
}

#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N, K, P, maxn = 0;
vector<int> nums, ans, tmp;
void dfs(int level, int sum_factor, int sum, int n_num);
int main()
{
    cin >> N >> K >> P;
    for (int i = 0; pow(i, P) <= N; i++){
        nums.push_back(pow(i, P));
    }

    dfs(nums.size()-1,0,0,0);//输入序列nums,递归堆栈tmp,保存结果ans,递归层次level,(状态数组used或其他标识)

	if (ans.size() == 0){
		printf("Impossible");
	}
	else{
		printf("%d = ", N);
		for (int i = 0; i < ans.size(); i++){
			printf("%d^%d", ans[i], P);
			if (i < ans.size() - 1) printf(" + ");
		}
	}
	return 0;
}
void dfs(int level, int sum_factor, int sum,int n_num) {
	if (sum > N || n_num > K) return;
	if (sum == N && n_num == K && sum_factor > maxn) {
		maxn = sum_factor;
		ans = tmp;
	}
	for (int i = level; i > 0; i--) {
		tmp.push_back(i);

		dfs(i, sum_factor + i, sum + nums[i], n_num + 1);

		tmp.pop_back();
	}
}
```
