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
#define F(x) (x -> next -> next);
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *right = head -> next;
        ListNode *left = head;
        ListNode *headnext = head -> next;
        
        while(right != nullptr && right->next != nullptr)
        {
            left -> next = F(left);
            left = left -> next;
            right -> next = F(right);
            right = right -> next;
        }
        left -> next = headnext;
        return head;
    }
};
