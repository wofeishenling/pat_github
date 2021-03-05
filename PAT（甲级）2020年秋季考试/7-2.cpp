#include<stdio.h>
#include<algorithm>
using namespace std;
int input[10010];
//int sum[10010];
int mySum(int i,int j){
    int sum = 0;
    for(;i<j;i++) sum+=input[i];
    return sum;
}
int main(){
    int n,m;
    int cnt = 0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(mySum(i,j)<m) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}