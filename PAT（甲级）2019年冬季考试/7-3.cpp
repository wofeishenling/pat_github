#include<stdio.h>
#include<vector>

using namespace std;
vector<int> G[205];

int main(){
    int n,m,v1,v2;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&v1,&v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        int t;
        vector<int> area;
        scanf("%d",&t);
        vector<int> cnt_vis(n+1);
        for(int j=0;j<t;j++){
            int tmp;
            scanf("%d",&tmp);
            area.push_back(tmp);
        }
        for(int p=0;p<area.size();p++){
            for(int q=0;q<G[area[p]].size();q++){
                cnt_vis[G[area[p]][q]]++;
            }
        }
        int notOk = 0;
        for(int p=0;p<area.size();p++){
            if(cnt_vis[area[p]]!=area.size()-1){
                notOk = 1;
                break;
            }
        }
        if(notOk){
            printf("Area %d needs help.\n",i);
            continue;
        }
        int can_in=-1;
        for(int p=1;p<=n;p++){
            if(cnt_vis[p]==area.size()){
                can_in = p;
                break;
            }
        }
        if(can_in!=-1){
            printf("Area %d may invite more people, such as %d.\n",i,can_in);
        }
        else printf("Area %d is OK.\n",i);
    }
    return 0;
}