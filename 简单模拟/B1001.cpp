#include<stdio.h>

using namespace std;

int cnt = 0;

void Callatz(int n){
    if(n==1) return;
    cnt++;
    if(n%2==1) Callatz((3*n+1)/2);
    else if(n%2==0) Callatz(n/2);
}
int main(){
    int n;
    scanf("%d",&n);
    Callatz(n); 
    printf("%d",cnt);
    return 0;
}