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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while(n>0 && fast){
            fast = fast->next;
            n--;
        }
        if(!fast)return head->next;

        while(fast){
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
