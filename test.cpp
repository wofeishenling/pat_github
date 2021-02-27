#include <algorithm>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
vector<int> nums;
vector<int> path,res;
int N,K,P,max_sum = -1;
void dfs(int depth,int sum,int num_sum,int start){
    if(sum>N) return;
    if(depth==K){
        if(sum==N && num_sum>max_sum){
            max_sum = num_sum;
            res = path;
            for(int i=0;i<path.size();i++){
                printf(" %d^%d",path[i],P);
                if(i<path.size()-1) printf(" +");
            }
            printf("\n");
        } 
        return ;
    }
    for(int i=start;i<nums.size();i++){
        path.push_back(nums[i]);
        dfs(depth+1,sum+pow(nums[i],P),num_sum+nums[i],i);
        path.pop_back();
    }
}
int main(){
    scanf("%d%d%d",&N,&K,&P);
    for(int i=1;pow(i,P)<=N;i++)
        nums.push_back(i);
    reverse(nums.begin(), nums.end());
    dfs(0,0,0,0);
    if(res.empty()) printf("Impossible\n");
    else{
        printf("%d =",N);
        for(int i=0;i<res.size();i++){
            printf(" %d^%d",res[i],P);
            if(i<res.size()-1) printf(" +");
        }
    }
    return 0;
}