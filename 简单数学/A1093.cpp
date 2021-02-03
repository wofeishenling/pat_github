#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main(){
    string s;
	cin >> s;
	int size = s.size();
	vector<int> leftP(size), rightT(size);
	for (int i = 1; i < size; i++)
	{
		if (s[i - 1] == 'P') leftP[i] = leftP[i - 1] + 1;
		else leftP[i] = leftP[i - 1];
	}
	for (int i = size - 2; i >= 0; i--)
	{
		if (s[i + 1] == 'T') rightT[i] = rightT[i + 1] + 1;
		else rightT[i] = rightT[i + 1];
	}
	long long ans = 0;
	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'A')
			ans += leftP[i] * rightT[i];
	}
	cout << ans % 1000000007;
	system("pause");
    return 0;
}