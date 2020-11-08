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
    stack<int> listToStack(ListNode* head){
        stack<int> st;
        for(ListNode* node = head; node != NULL; node = node->next){
            st.push(node->val);
        }
        return st;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1 = listToStack(l1);
        stack<int> st2 = listToStack(l2);
        
        ListNode* l3 = NULL;
        int carry = 0;
        while(!st1.empty() || !st2.empty() || carry > 0){
            int digit1 = (st1.empty() ? 0 : st1.top());
            int digit2 = (st2.empty() ? 0 : st2.top());
            carry += (digit1 + digit2);
            l3 = new ListNode(carry % 10, l3);
            carry /= 10;
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();
        }
        
        return l3;
    }
};