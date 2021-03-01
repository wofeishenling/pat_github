#include<stdio.h>

using namespace std;
const int MAXN = 1010;
int CBT[MAXN];
int n;

void CBT_inTraversal(int root){
    if(root>n) return;
    CBT_inTraversal(2*root);
    scanf("%d",&CBT[root]);
    CBT_inTraversal(2*root+1);
    return ;
}
int main(){
    scanf("%d",&n);
    CBT_inTraversal(1);
    return 0;
}