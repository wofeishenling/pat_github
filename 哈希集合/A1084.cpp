#include<stdio.h>
#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    set<char> set1,set2;
    for(char e:s1) set1.insert(toupper(e));
    for(char e:s2) set2.insert(toupper(e));
    //set1-set2
    //迭代器在迭代时不能增减
    for(auto e:set2){
        if(set1.find(e)!=set1.end()) 
            set1.erase(e);
   }
    for(char e:s1){
        if(set1.find(toupper(e))!=set1.end()){
            printf("%c",toupper(e));
            set1.erase(toupper(e));
        }
    }
    return 0;
}