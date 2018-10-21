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
    ListNode *sortList(ListNode *head) {
        if(head==nullptr ||head->next==nullptr)
        {
            return head;
        }
        //
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //
        
        ListNode* right=sortList(slow->next);
        slow->next=nullptr;//Add null to split the list
        ListNode* left=sortList(head);
        return merge(left,right);
    }
    ListNode* merge(ListNode * left, ListNode*right)
    {
        //Use stack management memory, save space, easy to operate
        ListNode head= ListNode(0);
        ListNode *p=&head;
        while(left!=nullptr&&right!=nullptr)
        {
            if(right->val<left->val)
            {
                p->next=right;
                right=right->next;
            }
            else{
                p->next=left;
                left=left->next;
            }
            p=p->next;
        }
        if(left==nullptr)
        {
            p->next=right;
        }
        if(right==nullptr)
        {
            p->next=left;
        }
        return head.next;
    }
};