#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int getM(int n, int flag)
{
    char str[10];
    sprintf(str, "%04d", n);
    string S(str);
    if (flag == 0)
        sort(S.begin(), S.end());
    else
        sort(S.begin(), S.end(), greater<int>());
    sscanf(S.c_str(), "%04d", &n);
    return n;
}
int main()
{
    int number;
    scanf("%d", &number);
    while (1)
    {
        int max = getM(number, 1);
        int min = getM(number, 0);
        printf("%04d - %04d = ", max, min);
        number = max - min;
        printf("%04d\n", number);
        if(number == 6174 || number==0) break;
    }
    return 0;
}

/*#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>

using namespace std;
void int2array(int n,vector<int>& numarray)
{
	for (int i = 0; i < 4; i++)
	{
		numarray[i] = n % 10;
		n = n / 10;
	}
}
int array2int(vector<int> numarray)
{
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		n = n * 10 + numarray[i];
	}
	return n;
}
int main()
{
	int n, MAX, MIN;
	scanf("%d", &n);
	vector<int> numarray(4);
	while (1)
	{
		int2array(n, numarray);
		sort(numarray.begin(), numarray.end());
		MIN = array2int(numarray);
		sort(numarray.begin(), numarray.end(), [](int a, int b) {return a > b; });
		MAX = array2int(numarray);
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if (n == 0 || n == 6174) break;
	}
	system("pause");
	return 0;
}*/