#include<stdio.h>
#include<vector>
#include<map>
#include<iostream>

using namespace std;
vector<int> input;
int sum = 0;
int need_num;
void backTrack(int cur_level,int cur_multi,int startIndex){
    //startIndex控制递归横向范围，level控制递归深度
    if(need_num==cur_level){
        sum+=cur_multi;
        return ;
    }
    for(int i=startIndex;i<input.size();i++){
        backTrack(cur_level+1,cur_multi*input[i],i+1);
    }
}
int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        input.push_back(-1*tmp);
    }
    vector<int> ans;
    for(int i=0;i<=N;i++){
        sum=0;
        need_num = i;
        backTrack(0,1,0);
        ans.push_back(sum);
    }
    for(int i=1;i<ans.size();i++){
        printf("%d",ans[i]);
        if(i<ans.size()-1) printf(" ");
    }
    return 0;
}