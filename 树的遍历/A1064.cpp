#include<stdio.h>
#include<algorithm>

using namespace std;
const int MAXN = 1010;
int CBT[MAXN],input[MAXN];
int N, cnt=0;
void inorderTraversal(int root){
    if(root>N) return;
    inorderTraversal(2*root);
    CBT[root]=input[cnt++];
    inorderTraversal(2*root+1);
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&input[i]);
    sort(input,input+N);
    inorderTraversal(1);
    for(int i=1;i<=N;i++){
        printf("%d",CBT[i]);
        if(i<N) printf(" ");
    }
    return 0;
}