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
    struct Contractor{
        bool operator()(ListNode* first,ListNode* second){
            return first->val>second->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Contractor> q;
        ListNode* head = new ListNode(0,nullptr);
        ListNode* current = head;

        

        for(int i=0;i<lists.size();i++){
            if(lists[i])q.push(lists[i]);
        }

        while(!q.empty()){
            ListNode* node = q.top();
            q.pop();

            if(node->next)q.push(node->next);

            current->next = node;
            current = current->next;
        }
        return head->next;
    }

};
