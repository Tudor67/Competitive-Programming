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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> st;
        for(ListNode* node = head; node != nullptr; node = node->next){
            st.push(node);
        }
        
        int carry = 0;
        while(!st.empty()){
            ListNode* node = st.top();
            st.pop();
            
            int sum = 2 * node->val + carry;
            
            node->val = sum % 10;
            carry = sum / 10;
        }
        
        if(carry > 0){
            head = new ListNode(carry, head);
        }
        
        return head;
    }
};