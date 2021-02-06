//pat的链表题可以用双向链表取巧
//链表的逆转可以用递归、头插法等
#include <cstdlib>
#include<stdio.h>

using namespace std;

struct Node
{
    int data;
    int next;
    /* data */
}static_list[100001];
//      node0->node1->node2->node3->*
//      head                 tail
//pre   cur    nex
//      pre    cur    nex
void my_reverse(int head,int tail,int& new_head,int& new_tail){
    int pre,cur,nex;
    new_head = tail;
    new_tail = head;
    cur = head;
    pre = -1;
    while(pre != tail){
        nex = static_list[cur].next;//1
        static_list[cur].next = pre;//2
        pre = cur;
        cur = nex;
    }
}

int main(){
    int L,Address,Data,Next,n,K;
    scanf("%d%d%d",&L,&n,&K);
    //读取数据建立静态链表
    while(n--){
        scanf("%d%d%d",&Address,&Data,&Next);
        static_list[Address].data = Data;
        static_list[Address].next = Next;
    }
    int pre,nex;
    static_list[100000].next=L;
    pre = 100000;
    int hair = pre;
    while(true){
        //tail试探是否够K个一组
        int tail = pre;
        for(int i=0;i<K;i++){
            tail = static_list[tail].next;
            if(tail==-1) break;
        }
        if(tail==-1) break;
        nex = static_list[tail].next;
        //开始反转
        int new_head,new_tail;
        my_reverse(L,tail,new_head,new_tail);
        //重新连接链表
        static_list[new_tail].next = nex;
        static_list[pre].next = new_head;
        pre = new_tail;
        L = nex;    //head->node1->node2->node3->null
                    //pre   cur            
    }
    hair = static_list[hair].next;
    while(hair!=-1){
        if(static_list[hair].next==-1) printf("%05d %d -1\n",hair,static_list[hair].data);
        else printf("%05d %d %05d\n",hair,static_list[hair].data,static_list[hair].next);
        hair = static_list[hair].next;
    }
    system("pause");
    return 0;
}