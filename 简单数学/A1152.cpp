#include<stdio.h>
#include<string>

using namespace std;
bool isPrime(long long num){
    if(num<2) return false;
    long long sqr = sqrt(num*1.0);
    for(long long i=2;i<=sqr;i++){
        if(num%i==0) return false;
    }
    return true;
}
int main(){
    int L,K;
    long long num;
    scanf("%d%d",&L,&K);
    getchar();
    char temp[1005];
    scanf("%s",temp);
    string input(temp);
    int i=0;
    for(;i+K<=L;i++){
        string K_digit;
        K_digit = input.substr(i,K);
        sscanf(K_digit.c_str(),"%lld",&num);
        if(isPrime(num)) break;
    }
    if(i+K>L) printf("404");
    else printf("%lld",num);
    return 0;
}