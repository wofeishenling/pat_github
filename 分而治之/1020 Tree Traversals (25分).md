```c++
#include<stdio.h>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node {
	int data;
	node* left;
	node* right;
}node;

const int MAXN = 33;
int in[MAXN], post[MAXN];
vector<int> ans;

node* createTree(int inl, int inr, int postl, int postr);
void bfs(node* T);
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", post + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", in + i);
	}
	node* T = createTree(0,n-1,0,n-1);
	bfs(T);
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) printf("%d", ans[i]);
		else printf("%d ", ans[i]);
	}
	return 0;
}
node* createTree(int inl,int inr,int postl,int postr) {
	if (inl > inr) return NULL;//递归边界
	int pos = -1;
	for (int i = inl; i <= inr; i++) {
		if (in[i] == post[postr]) {
			pos = i;
			break;
		}
	}
	node* root = (node*)malloc(sizeof(node));
	root->data = in[pos];
	root->left = createTree(inl, pos - 1, postl, postl + pos - inl - 1);
	root->right = createTree(pos + 1, inr, postl + pos - inl, postr-1);
	return root;
}
void bfs(node* T) {
	queue<node*> q;
	q.push(T);
	while (!q.empty()) {
		node* tmp = q.front();
		ans.push_back(tmp->data);
		q.pop();
		if (tmp->left) q.push(tmp->left);
		if (tmp->right) q.push(tmp->right);
	}
}
```
