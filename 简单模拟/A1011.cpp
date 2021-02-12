#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main()
{
	double ans = 1;
	char decide[] = { 'W','T','L' };
	vector<int> anspath(3);
	for (int i = 0; i < 3; i++)
	{
		double max = -1;
		for (int j = 0; j < 3; j++)
		{
			double tmp;
			scanf("%lf", &tmp);
			if (tmp > max)
			{
				max = tmp;
				anspath[i] = j;
			}
		}
		ans *= max;
	}
	ans = (ans*0.65 - 1) * 2;
	printf("%c %c %c %.2lf", decide[anspath[0]], decide[anspath[1]], decide[anspath[2]], ans);
	system("pause");
	return 0;
}