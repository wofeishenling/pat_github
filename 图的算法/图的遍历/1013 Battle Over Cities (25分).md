```c++
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> G[1100];//邻接表
int occupied;
void dfs(int, unordered_set<int>&);
int main()
{
	int N_v, M_e, K_q;
	cin >> N_v >> M_e >> K_q;
	while (M_e--) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);//无向图的邻接表存储
	}
	while (K_q--) {
		scanf("%d", &occupied);
		unordered_set<int> vised;
		int cnt = 0;
		for (int i = 1; i <= N_v; i++) {
			if (vised.find(i) == vised.end() && i!=occupied) {
				dfs(i, vised);
				cnt++;
			}
		}
		printf("%d\n", cnt-1);
	}
	return 0;
}
void dfs(int s, unordered_set<int> &vised) {
	if (s == occupied) return;
	vised.insert(s);
	for (int i = 0; i < G[s].size(); i++) {
		if (vised.find(G[s][i]) == vised.end())
			dfs(G[s][i],vised);
	}
}
```
