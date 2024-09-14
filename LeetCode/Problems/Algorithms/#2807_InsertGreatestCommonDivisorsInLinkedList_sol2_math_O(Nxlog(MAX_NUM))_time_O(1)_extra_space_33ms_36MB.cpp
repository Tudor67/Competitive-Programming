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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node = head;
        while(node->next != nullptr){
            ListNode* gcdNode = new ListNode(gcd(node->val, node->next->val));
            gcdNode->next = node->next;
            node->next = gcdNode;
            node = node->next->next;
        }
        return head;
    }
};