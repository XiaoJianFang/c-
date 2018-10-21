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
    ListNode *insertionSortList(ListNode *head) {
      if(head==nullptr ||head->next==nullptr) return head;
        
        ListNode dummy= ListNode(0);
        ListNode *pre=&dummy;
        ListNode *cur=head;
        ListNode *temp;
            
        while(cur!=nullptr)
        {
            temp=cur->next;
            pre=&dummy;
            while(pre->next!=nullptr&&pre->next->val<cur->val)
            {
               pre=pre->next;
            }
            cur->next=pre->next;
            pre->next=cur;
            cur=temp;
        }
        return dummy.next;
    }
};