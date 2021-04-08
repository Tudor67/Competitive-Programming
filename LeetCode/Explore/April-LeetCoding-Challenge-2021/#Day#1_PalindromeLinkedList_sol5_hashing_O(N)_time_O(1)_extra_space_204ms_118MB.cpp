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
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        const int BASE = 10;
        const int MODULO = 1e9 + 7;
        int leftHash = 0;
        int rightHash = 0;
        int p = 1;
        ListNode* node = head;
        for(int i = 1; i <= listSize; ++i){
            if(listSize % 2 == 1 && i == listSize / 2 + 1){
                // ignore middle element
            }else if(i <= listSize / 2){
                leftHash = (1LL * BASE * leftHash + node->val) % MODULO;
            }else{
                rightHash = (rightHash + 1LL * p * node->val) % MODULO;
                p = (1LL * BASE * p) % MODULO;
            }
            node = node->next;
        }
        
        return (leftHash == rightHash);
    }
};