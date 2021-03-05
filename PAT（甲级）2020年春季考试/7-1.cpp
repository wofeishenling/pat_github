#include <cstdio>
#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    int sqr = sqrt(n*1.0);
    for(int i=2;i<=sqr;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    string s;
    int flag = 1;
    cin >> s;
    for(int i=0;i<s.size();i++){
        string s1(s.begin()+i,s.end());
        int num;
        sscanf(s1.c_str(),"%d",&num);
        if(isPrime(num)){
            cout<<s1<<" Yes\n";
        }else{
            flag = 0;
            cout<<s1<<" No\n";
        }
    }
    if(flag) cout<< "All Prime!";
    return 0;
}