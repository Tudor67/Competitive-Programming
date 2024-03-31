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
    bool isPalindrome(ListNode* head) {
        const long long BASE = 10;
        const vector<long long> MODULOS = {(long long)1e9 + 7, (long long)1e9 + 9, (long long)1e9 + 21};

        for(const long long MODULO: MODULOS){
            long long h1 = 0;
            long long h2 = 0;
            long long p = 1;
            for(ListNode* node = head; node != nullptr; node = node->next){
                h1 = (h1 * BASE + node->val) % MODULO;
                h2 = (h2 + node->val * p) % MODULO;
                p = (p * BASE) % MODULO;
            }
            if(h1 != h2){
                return false;
            }
        }
        
        return true;
    }
};