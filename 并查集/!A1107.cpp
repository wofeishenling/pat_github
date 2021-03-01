#include<stdio.h>

using namespace std;
//并查集数据结构
const int MAXN = 1010;
int isRoot[MAXN];
int fatherOf[MAXN];
void init(){
    for(int i=0;i<MAXN;i++) fatherOf[i] = i;
}
int findFatherOf(int x){
    if(fatherOf[x]==x) return x;
    return fatherOf[x] = findFatherOf(fatherOf[x]);
}
void Union(int a,int b){
    int fa = findFatherOf(a);
    int fb = findFatherOf(b);
    if(fa!=fb) fatherOf[fa]=fb;
}
int main(){
    int n,k,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d:",&k);
        int first;
        scanf("%d",&first);
        if(!isRoot[first]){
            isRoot[first] = 1;
        }
        
        for(int j=1;j<k;j++){
            scanf("%d",&temp);
        } 
    }
    return 0;
}