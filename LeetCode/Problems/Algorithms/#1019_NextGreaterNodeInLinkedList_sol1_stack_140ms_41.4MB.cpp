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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> answer;
        for(ListNode* node = head; node != NULL; node = node->next){
            answer.push_back(node->val);
        }
        
        stack<int> st;
        for(int i = (int)answer.size() - 1; i >= 0; --i){
            while(!st.empty() && answer[i] >= st.top()){
                st.pop();
            }
            int next_larger = (st.empty() ? 0 : st.top());
            st.push(answer[i]);
            answer[i] = next_larger;
        }
        
        return answer;
    }
};