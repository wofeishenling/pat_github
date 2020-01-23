```c++
//字符串整数映射+图的遍历+连通块的边权和
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 2020;
int G[maxn][maxn];//无向图邻接矩阵方便访问边
int W[maxn];//点权数组
int cnt = 0,K_threthold=0;
bool vis[maxn] = { false };

map<string, int> Gangs;
map<string, int> string2int;
map<int, string> int2string;
int getNumber(const string& s) {
	if (string2int.find(s) != string2int.end()) {
		return string2int[s];
	}
	else {
		string2int[s] = cnt++;
		int2string.insert(make_pair(cnt - 1, s));
		return cnt - 1;
	}
}
void dfs(int u, int& head, int& num_gang, vector<int>& sset) {
	num_gang++;
	vis[u] = true;
	sset.push_back(u);
	if (W[u] > W[head]) head = u;
	for (int i = 0; i < cnt; i++) {
		if (vis[i] == false && G[u][i] != 0) {
			dfs(i, head, num_gang, sset);
		}
	}
}
void DFSTravel() {
	for (int i = 0; i < cnt; i++) {
		if (vis[i] == false) {
			int head = i, num_gang = 0, sum_eweight = 0;
			vector<int> sset;//连通块
			dfs(i,head,num_gang,sset);
			for(int k=0;k<sset.size();k++)
				for (int j = k+1; j < sset.size(); j++) {
					sum_eweight += G[k][j];
				}
			if (num_gang > 2 && sum_eweight > K_threthold) {
				Gangs.insert(make_pair(int2string[head], num_gang));
			}
		}
	}
}
int main()
{
	int N,weight;
	string name1, name2;
	cin >> N >> K_threthold;
	while (N--) {
		cin >> name1 >> name2 >> weight;
		int v1 = getNumber(name1);
		int v2 = getNumber(name2);
		G[v1][v2] += weight;
		G[v2][v1] += weight;
		W[v1] += weight;
		W[v2] += weight;
	}
	DFSTravel();//访问每一个连通块
	printf("%d\n", Gangs.size());
	for (auto e : Gangs) {
		cout << e.first << ' ' << e.second << endl;
	}
	return 0;
}
```
