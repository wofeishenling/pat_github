#include <cstdlib>
#include<stdio.h>
#include<set>
#include<algorithm>

using namespace std;

const int MAXN = 100005;

struct node{
    int address;
    int val;
    int next;
    int order;
    node(){order = 2*MAXN;}
}static_list[MAXN];
int cnt1 = 0;
int cnt2 = 0;

int main(){
    int Address,Key,Next;
    int node0,n;
    set<int> isExist;
    scanf("%d%d",&node0,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&Address,&Key,&Next);
        static_list[Address].address = Address;
        static_list[Address].val = Key;
        static_list[Address].next = Next;
    }
    while(node0!=-1){
        if(isExist.find(abs(static_list[node0].val))!=isExist.end()){
            static_list[node0].order = MAXN + cnt2++;
        }
        else{
            static_list[node0].order = cnt1++;
            isExist.insert(abs(static_list[node0].val));
        }
        node0 = static_list[node0].next;
    }
    sort(static_list,static_list+MAXN,[](auto& a,auto& b){ 
        return a.order<b.order; });
    for(int i=0;i<cnt1+cnt2;i++){
        if(i==cnt1-1 || i==cnt1+cnt2-1)
            printf("%05d %d -1\n",static_list[i].address,static_list[i].val);
        printf("%05d %d %05d\n",static_list[i].address,static_list[i].val,static_list[i+1].address);
    }
    return 0;
}