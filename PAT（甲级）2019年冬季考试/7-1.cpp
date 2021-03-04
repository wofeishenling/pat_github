#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

char table[26][7][5];

int main(){
    for(int i=0;i<26;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<5;k++){
                scanf("%c",&table[i][j][k]);
            }
            getchar();
        }
    }
    string input,s;
    getline(cin,input);
    for(char& e:input){
        if(e<'A' || e>'Z') e = ' ';
    }
    stringstream ss(input);
    vector<string> worlds;
    while(ss>>s){
        worlds.push_back(s);
    }
    for(int i=0;i<worlds.size();i++){
        for(int j=0;j<7;j++){//one line
            for(int k=0;k<worlds[i].size();k++){
                for(int u=0;u<5;u++){
                    printf("%c",table[worlds[i][k]-'A'][j][u]);
                }
                if(k<worlds[i].size()-1) printf(" ");
            }
            printf("\n");
        }
        if(i<worlds.size()-1) printf("\n");
    }
    return 0;
}