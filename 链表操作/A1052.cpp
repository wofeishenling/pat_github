//链表排序
#include<stdio.h>

using namespace std;

struct A1052
{
    int key;
    int next;
    /* data */
}static_list[100001];
int insert_sort(int L){
    int new_L = 100000;
    static_list[new_L].key = 0x80000000;
    static_list[new_L].next = -1;
    static_list[new_L].next = L;
    L = static_list[L].next;
    int r;
    while(L!=-1){
        int temp = static_list[L].key;
        int start = static_list[new_L].next;
        int pre = new_L;//用来保存start的前驱节点
        //找到插入的位置
        while(start!=-1 && temp > static_list[start].key){
            start = static_list[start].next;
            pre = static_list[pre].next;
        }
        //位置在pre和start之间
        r = static_list[L].next;
        //执行插入
        static_list[pre].next = L;
        static_list[L].next = start;
        L = r;
    }
    return static_list[new_L].next;
}

int main(){
    int n,L;
    scanf("%d%d",&n,&L);
    int N = n;
    int Address,Key,Next;
    while(n--){
        scanf("%d%d%d",&Address,&Key,&Next);
        static_list[Address].key = Key;
        static_list[Address].next = Next;
    }
    L = insert_sort(L);
    printf("%d %05d",N,L);
    while(L!=-1){
        if(static_list[L].next==-1) printf("%05d %d -1\n",L,static_list[L].key);
        else printf("%05d %d %05d\n",L,static_list[L].key,static_list[L].next);
    }
    return 0;
}