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
    // O(n) time complexity. 
    // O(n) memory complexity
    int getDecimalValue(ListNode* head) 
    {
        vector<int> v;
        int len = 0;
        int i = 0;
        while(head)
        {
            v.push_back(head -> val);
            i++;
            head = head->next;
        }
        len = i;
        i = 0;
        int res = 0;
        for(i = 0; i < len; i++)
        {
            if(v[i] == 1)
                res += (1 <<(len-i-1));
        }
        return res;
        
    }
};