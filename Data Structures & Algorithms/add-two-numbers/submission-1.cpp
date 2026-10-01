/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        int ost = 0;

        while(l1 || l2){
            int val1,val2;
            if(l1){
                val1 = l1->val;
            }
            else{
                val1 = 0;
            }
            if(l2){
                val2 = l2->val;
            }
            else{
                val2 = 0;
            }
            int sum = val1+val2+ost;

            if(sum>=10){
                sum-=10;
                ost=1;
            }
            else{
                ost=0;
            }
            ListNode* node = new ListNode(sum,nullptr);
            current->next = node;
            current = current->next;

            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        if(ost == 1){
            current->next = new ListNode(1,nullptr);
            current = current->next;
        }
        return head->next;
    }
};
