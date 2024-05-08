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
        vector<ListNode*> st;
        for(ListNode* node = head; node != nullptr; node = node->next){
            while(!st.empty() && st.back()->val < node->val){
                st.pop_back();
            }
            if(!st.empty()){
                st.back()->next = node;
            }
            st.push_back(node);
        }
        return st[0];
    }
};