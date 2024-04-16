https://leetcode.com/problems/add-two-numbers/

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
        ListNode* tampu = new ListNode();
        ListNode* result = tampu;
        int rem = 0;
        while(l1 || l2 || rem)
        {
            int total = 0;
            if(l1)
            {
                total = total + l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                total = total + l2->val;
                l2 = l2->next;
            }
            if(rem)
                total = total + rem;
            
            int ans = total % 10;
            rem = total/10;

            ListNode* temp = new ListNode(ans);
            tampu->next = temp;
            tampu = tampu->next;
        }

        return result->next;
    }
};