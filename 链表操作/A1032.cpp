#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

struct Node{                                //静态链表的结构体定义
    char data;
    int next;
}static_node[100001];

int getlength(int L){   
    int count=0;
    while(L!=-1){                           //null在静态链表中用-1来代表
        L = static_node[L].next;
        count++;
    }
    return count;
}

int main(){
    int L1,L2,n;                            //建立静态链表的过程
    int Address,Next;
    char data;
    scanf("%d%d%d",&L1,&L2,&n);
    while(n--){
        scanf("%d %c %d",&Address,&data,&Next);
    }
    int len1=getlength(L1);
    int len2=getlength(L2);
    int diff_length=abs(len1-len2);                 //链表长度之差
    if(len1>len2){                                  //长度大的链表先走diff_length的长度
        for(int i=0;i<diff_length;i++){
            L1=static_node[L1].next;
        }
    }
    else{
         for(int i=0;i<diff_length;i++){
            L2=static_node[L2].next;
        }
    }
    while(L1!=L2){
        L1=static_node[L1].next;                    //指针类型访问成员使用->；其他用.访问成员
        L2=static_node[L2].next;
    }
    if(L1==-1) printf("-1");
    else printf("%d",L1);
    return 0;
}