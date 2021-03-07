#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int Msize,N,M;
int hash_map[10010];
bool isPrime(int n){
    if(n<2) return false;
    int sqr = sqrt(1.0*n);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}
int getPrime(int n){
    while(!isPrime(n)) n++;
    return n;
}
void createHash(vector<int>& input,int Msize){
    for(int i=0;i<input.size();i++){
        bool flag = false;
        for(int j=0;j<Msize;j++){
            if(hash_map[(input[i]+j*j)%Msize]==0){
                hash_map[(input[i]+j*j)%Msize]=input[i];
                flag = true;
                break;
            }
        }
        if(!flag) printf("%d cannot be inserted.\n",input[i]);
    }
}
int getTime(int n){
    int cnt = 0;
    for(int i=0;i<=Msize;i++){//实际上i=Msize和i=0是一样的，没有必要取=
        cnt++;
        if(hash_map[(n+i*i)%Msize]==n){
            break;//find successfully
        }
        if(hash_map[(n+i*i)%Msize]==0){
            break;//not found
        }
        //无限循环查找
    }
    return cnt;
}
int main(){
    cin >> Msize >> N >> M;
    //If the maximum size given by the user is not prime,
    //you must re-define the table size to be the smallest prime number 
    //which is larger than the size given by the user.
    if(!isPrime(Msize)) Msize = getPrime(Msize);
    vector<int> input(N);
    vector<int> seq(M);
    for(int i=0;i<N;i++) cin>>input[i];
    for(int i=0;i<M;i++) cin>>seq[i];
    createHash(input,Msize);
    double sum=0;
    for(int i=0;i<M;i++){
        sum+=getTime(seq[i]);
    }
    printf("%.1f",sum/seq.size());
    return 0;
}