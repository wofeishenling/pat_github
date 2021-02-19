#include <cstdlib>
#include<stdio.h>
#include<vector>

using namespace std;

char mp[5] = {'S','H','C','D','J'};
char* int2str(int n){
    char* s = (char*)malloc(5);
    s[0] = mp[(n-1)/13];
    int k = n%13;
    if(k==0) k = 13;
    if(k>=10){
        s[1] = '0'+k/10;
        s[2] = '0'+k%10;
        s[3] = '\0';
    }
    else{
        s[1] = '0'+k;
        s[2] = '\0';
    }
    return s;
}
int main(){
    int repeat_times;
    int shuffling_order[55],start[55],end[55];
    scanf("%d",&repeat_times);
    for(int i=1;i<55;i++){
        scanf("%d",&shuffling_order[i]);
        start[i]=i;
    }
    for(int i=0;i<repeat_times;i++){
        for(int j=1;j<55;j++){
            end[shuffling_order[j]]=start[j];
        }
        for(int j=1;j<55;j++){
            start[j] = end[j];
        }
    }
    for(int i=1;i<55;i++){
        printf("%s",int2str(start[i]));
        if(i<54) printf(" ");
    }
}