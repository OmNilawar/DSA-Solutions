https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
         if (head == nullptr || head->next == nullptr)
            return head;
        int num = head->val;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* forward = nullptr;

        while(curr != nullptr)
        {
            if(curr->val == num)
            {
                forward = curr->next;
                curr = forward;
                prev->next = curr;
            }
            else
            {
                num = curr->val;
                forward = curr->next;
                prev = curr;
                curr = forward;
            }
        }

        return head;
    }
};