```c++
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int M, N, K;

	cin >> M >> N >> K;
	while (K--) {
		vector<int> popped;
		stack<int> s;
		int cnt = 0, flag = 0;
		for (int i = 0; i < N; i++) {
			int temp;
			scanf("%d", &temp);
			popped.push_back(temp);
		}
		for (int i = 1; i <= N; i++) {
			s.push(i);
			if (s.size() > M) flag = 1;
			while (!s.empty() && cnt < N && s.top() == popped[cnt]) {
				cnt++;
				s.pop();
			}
		}
		if (s.empty() && flag == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
```
