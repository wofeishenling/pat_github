#include<stdio.h>
#include<iostream>

using namespace std;

void swap(int &a, int &b){
    int t;
    t = a;
    a = b;
    b = t;
}

int main(){
    int val1 = 10;
    int val2 = 20;
    swap(val1,val2);
    printf("%d %d\n",val1,val2);
    
    return 0;
}