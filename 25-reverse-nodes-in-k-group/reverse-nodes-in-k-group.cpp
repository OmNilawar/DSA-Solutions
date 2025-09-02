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
    ListNode* findKth(ListNode* head, int k)
    {
        for(int i = 0;i < k-1;i++)
        {
            if(head == nullptr)
                return head;
            
            head = head->next;
        }

        return head;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr)
        {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        ListNode* KthNode = findKth(curr,k);

        if(!KthNode)
            return head;
        else
            head = KthNode;
            
        ListNode* prevStart = nullptr;

        while(KthNode)
        {
            ListNode* nextStart = KthNode->next;
            KthNode->next = nullptr;
            ListNode* prev = reverseList(curr);
            if(prevStart)
                prevStart->next = prev;
                
            prevStart = curr;
            curr = nextStart;
            KthNode = findKth(curr,k);
        }

        prevStart->next = curr;

        return head;
    }
};