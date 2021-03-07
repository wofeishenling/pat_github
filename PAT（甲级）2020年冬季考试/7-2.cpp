#include<stdio.h>
#include<string>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 0x3fffffff;

string input;
string str;
bool isVaild(int left,int right){
    queue<char> q;
    for(char e:str) q.push(e);
    for(int i=left;i<=right;i++){
        if(input[i]==q.front()){
            q.pop();
        }
    }
    if(q.empty()) return true;
    else return false;
}
int main(){
    cin >> input;
    cin >> str;
    int left = 0,right = 0,minLen = INF,anl,anr;
    while(right<input.size()){
        right++;
        while(isVaild(left,right)){
            if(right-left+1<minLen){
                minLen = right - left + 1;
                anl = left;
                anr = right;
            }
            left++;
        }
    }
    for(int i=anl;i<=anr;i++) cout<<input[i];
    return 0;
}