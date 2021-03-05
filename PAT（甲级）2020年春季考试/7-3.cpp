#include<stdio.h>
#include<vector>
#include<set>

using namespace std;
const int MAXN = 505;
vector<int> G[MAXN];
int animal[MAXN];

int main(){
    int n,r,k;
    int v1,v2;
    scanf("%d%d%d",&n,&r,&k);
    for(int i=0;i<r;i++){
        scanf("%d%d",&v1,&v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    int num_plan;
    scanf("%d",&num_plan);
    for(int i=0;i<num_plan;i++){
        set<int> spe;
        for(int j=1;j<=n;j++) animal[j]=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&animal[j]);
            spe.insert(animal[j]);
        }
        if(spe.size()>k){
            printf("Error: Too many species.\n");
            continue;
        }
        if(spe.size()<k){
            printf("Error: Too few species.\n");
            continue;
        }
        //遍历所有区域
        int flag = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<G[i].size();j++){
                if(animal[i]==animal[G[i][j]]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0) break;
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}