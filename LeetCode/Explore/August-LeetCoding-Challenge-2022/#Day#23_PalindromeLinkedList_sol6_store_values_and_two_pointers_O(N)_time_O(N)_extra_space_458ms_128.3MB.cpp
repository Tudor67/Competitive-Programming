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
        vector<int> values;
        for(ListNode* node = head; node != nullptr; node = node->next){
            values.push_back(node->val);
        }
        
        for(int i = 0, j = (int)values.size() - 1; i < j; ++i, --j){
            if(values[i] != values[j]){
                return false;
            }
        }
        
        return true;
    }
};