#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int address;
    int val;
    int flag;
    int next;
}SL[100010];
int getLength(int L){
    int len = 0;
    while(L!=-1){
        len++;
        L=SL[L].next;
    }
    return len;
}
int main(){
    int L,n,k;
    scanf("%d%d%d",&L,&n,&k);
    int Address,Data,Next;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&Address,&Data,&Next);
        SL[Address].val = Data;
        SL[Address].address = Address;
        SL[Address].next = Next;
    }    
    int len = getLength(L);
    int p = L;
    vector<int> flag_list;
    for(int i=0;i<=len/k;i++){
        for(int j=1;j<=k;j++){
            flag_list.push_back(k*((len/k+1)-i)+j);
        }
    }
    int cnt = 0;
    while(p!=-1){
        SL[p].flag = flag_list[cnt++];
        p=SL[p].next;
    }
    sort(SL,SL+100010,[](auto& a,auto& b){
        return a.flag<b.flag;
    });
    for(int i=0;i<n;i++){
        if(i==n-1) printf("%05d %d -1\n",SL[i].address,SL[i].val);
        else printf("%05d %d %05d\n",SL[i].address,SL[i].val,SL[i+1].address); 
    }
    return 0;
}