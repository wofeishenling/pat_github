#include<stdio.h>
#include<iostream>
#include<string>
#include<set>

using namespace std;

int hash1[128],hash2[128];

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    for(char e:s1) hash1[e]++;
    for(char e:s2) hash2[e]++;
    //迭代器在迭代时不能增减
    bool flag = true;
    int cnt = 0;
    for(int i=0;i<128;i++){
        if(hash2[i]>hash1[i]){
            flag = false;
            cnt += (hash2[i]-hash1[i]);
        }
    }
    if(flag) printf("Yes %llu",s1.size()-s2.size());
    else printf("No %d",cnt);
    return 0;
}