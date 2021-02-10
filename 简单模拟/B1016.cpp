#include<stdio.h>

int main(){
    long long A,Da,B,Db;
    scanf("%lld%lld%lld%lld",&A,&Da,&B,&Db);
    long long Pa=0, Pb=0;
    int cnt1=0,cnt2=0;
    while(A){
        if(A%10==Da) Pa = Pa*10 + Da;
        A /= 10;
    }
    while(B){
        if(B%10==Db) Pb = Pb*10 + Db;
        B /= 10;
    }
    printf("%lld",Pa+Pb);
    return 0;
}