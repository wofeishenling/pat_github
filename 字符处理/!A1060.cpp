#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void solution(string& S,int n){
    
}
int main(){
    int N;
    string A,B;
    cin >> N >> A >> B;
    solution(A,N);
    solution(B,N);
    if(A==B){
        cout << "YES " << A;
    }
    else{
        cout<< "NO " << A << B;
    }
    return 0;
}