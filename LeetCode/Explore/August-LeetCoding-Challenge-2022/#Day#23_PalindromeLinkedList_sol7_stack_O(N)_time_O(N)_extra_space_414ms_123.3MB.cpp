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
        stack<int> st;
        for(ListNode* node = head; node != nullptr; node = node->next){
            st.push(node->val);
        }
        
        for(ListNode* node = head; node != nullptr; node = node->next){
            if(node->val == st.top()){
                st.pop();
            }else{
                return false;
            }
        }
        
        return true;
    }
};