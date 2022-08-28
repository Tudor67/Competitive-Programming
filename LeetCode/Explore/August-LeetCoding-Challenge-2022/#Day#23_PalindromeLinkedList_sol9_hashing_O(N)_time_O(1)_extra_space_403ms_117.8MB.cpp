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
private:
    bool hashMatching(ListNode* head, const long long& BASE, const long long& MODULO){
        long long hash1 = 0;
        long long hash2 = 0;
        long long currentPow = 1;
        for(ListNode* node = head; node != nullptr; node = node->next){
            hash1 = (hash1 * BASE + node->val) % MODULO;
            hash2 = (hash2 + node->val * currentPow) % MODULO;
            currentPow = (currentPow * BASE) % MODULO;
        }
        return (hash1 == hash2);
    }
    
public:
    bool isPalindrome(ListNode* head) {
        const long long BASE = 11;
        const long long MODULO1 = 1e9 + 7;
        const long long MODULO2 = 1e9 + 9;
        return (hashMatching(head, BASE, MODULO1) && hashMatching(head, BASE, MODULO2));
    }
};