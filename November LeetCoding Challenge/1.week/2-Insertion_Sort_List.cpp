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
    // O(n^2) time complexity
    // O(n) memory complexity
    ListNode* insertionSortList(ListNode* head) 
    {
        if(!head)
            return head;
        
        ListNode *answer = new ListNode(0,nullptr);
        while(head)
        {
            ListNode *temp = answer;
            
            while(temp -> next && (temp->next->val) < (head->val) )
            {
                temp = temp->next;
            }
            
            temp -> next = new ListNode(head->val, temp->next);
            head = head->next;
            
        }
        return answer -> next;
        
        
    }
};