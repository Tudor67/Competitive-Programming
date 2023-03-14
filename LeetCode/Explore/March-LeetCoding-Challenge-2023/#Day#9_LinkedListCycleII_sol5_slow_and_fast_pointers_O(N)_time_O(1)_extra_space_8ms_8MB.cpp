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
    ListNode *detectCycle(ListNode *head) {
        // Step 1: special case
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }

        // Step 2: use slow and fast pointers to find the cycle
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(slow != fast && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 3: if (fast == nullptr || fast->next == nullptr) => there is no cycle => return nullptr
        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }

        // Step 4: find the cycle start
        ListNode* cycleStart = head;
        while(cycleStart != slow){
            slow = slow->next;
            cycleStart = cycleStart->next;
        }

        return cycleStart;
    }
};