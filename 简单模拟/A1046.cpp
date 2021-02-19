#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

int dis[100005];// 0 1 3 7 21 30
                // 1 2 4 14 9
int mySum(int l,int r){
    return dis[r]-dis[l];
}
int main(){
    int n,temp;
    vector<int> input;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        input.push_back(temp);
    }
    dis[1]=input[0];
    for(int i=2;i<=n;i++) dis[i]=dis[i-1]+input[i-1];
    for(int i=0;i<=n;i++) printf("%d ",dis[i]);
    int m,left,right;
    int total_sum = mySum(0,input.size());
    scanf("%d",&m);
    for(int i=0;i<m;i++){//n
        scanf("%d%d",&left,&right);
        if(left>right) swap(left,right);
        left--;
        right--;
        int sum1 =  mySum(left,right);//m
        int sum2 = total_sum - sum1;
        printf("%d\n",min(sum1,sum2));
    }

    return 0;
}