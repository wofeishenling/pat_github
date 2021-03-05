#include<stdio.h>
#include<set>

using  namespace std;
int hashmap[100010];
int input[11][1010];
int isOut[11];
set<int> inq;
bool isVaild(int n){
    for(auto e:inq){
        if(inq.find(n+e)!=inq.end()) return true;
    }
    return false;
}
int main(){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    int num,round;
    scanf("%d%d",&num,&round);
    for(int i=1;i<=num;i++){
        for(int j=1;j<=round;j++){
            scanf("%d",&input[i][j]);
        }
    }
    for(int i=1;i<=round;i++){
        for(int j=1;j<=num;j++){
            if(!isOut[j]){
                int flag = 1;
                if(inq.find(input[j][i])!=inq.end()){
                    isOut[j] = 1;
                    flag = 0;
                }
                if(!isVaild(input[j][i])){
                    isOut[j] = 1;
                    flag = 0;
                }
                if(flag == 0){
                    printf("Round #%d: %d is out.",i,j);
                    continue;
                }
                hashmap[input[j][i]]=1;
                inq.insert(input[j][i]);
            }
        }
    }
    return 0;
}
