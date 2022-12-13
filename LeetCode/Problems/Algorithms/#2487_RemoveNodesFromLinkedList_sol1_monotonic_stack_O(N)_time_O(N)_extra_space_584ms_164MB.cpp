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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        for(ListNode* node = head; node != nullptr; node = node->next){
            while(!st.empty() && st.top()->val < node->val){
                st.top()->next = nullptr;
                st.pop();
            }
            if(!st.empty()){
                st.top()->next = node;
            }
            st.push(node);
        }

        while((int)st.size() >= 2){
            st.pop();
        }
        
        return st.top();
    }
};