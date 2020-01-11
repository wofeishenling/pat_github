```c++
迭代
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre,*cur,*temp;
        pre = NULL;
        cur = head;
        while(cur){
            temp = cur->next;

            cur->next = pre;

            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
递归
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;//递归边界
        ListNode* p=reverseList(head->next);//子问题
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};
```
