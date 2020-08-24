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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* virtual_start = new ListNode(0, head);
        stack<pair<ListNode*, int>> st;
        st.push({virtual_start, 0});
        unordered_set<int> vis;
        vis.insert(0);
        
        int pref_sum = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            pref_sum += node->val;
            if(vis.find(pref_sum) != vis.end()){
                int s = node->val;
                while(s != 0){
                    s += st.top().first->val;
                    vis.erase(st.top().second);
                    st.pop();
                }
                // skip the last sequence of nodes that sum to 0
                st.top().first->next = node->next;
            }else{
                st.push({node, pref_sum});
                vis.insert(pref_sum);
            }
        }
        
        return virtual_start->next;
    }
};