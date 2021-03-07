#include<stdio.h>
#include<map>
#include<cmath>
using namespace std;

int main(){
    int n1=0,n2=1;
    int n,pre;
    scanf("%d",&n);
    while(n2<n && n1<n){
        n1 = n1+n2;
        pre = n2;
        n2 = n2+n1;
    }
    map<int,int> ans;
    ans[abs(n2-n)] = n2;
    ans[abs(n1-n)] = n1;
    ans[abs(pre-n)] = pre;
    printf("%d",ans.begin()->second);
    return 0;
}