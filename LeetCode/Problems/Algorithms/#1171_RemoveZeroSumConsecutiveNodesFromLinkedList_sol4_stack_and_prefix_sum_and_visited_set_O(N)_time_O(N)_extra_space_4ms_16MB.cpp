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
        ListNode prevHead(0, head);

        stack<ListNode*> st;
        unordered_set<int> vis;
        st.push(&prevHead);
        vis.insert(0);

        int prefSum = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            prefSum += node->val;

            if(vis.count(prefSum)){
                int s = prefSum - node->val;
                while(s != prefSum){
                    vis.erase(s);
                    s -= st.top()->val;
                    st.pop();
                }
                st.top()->next = node->next;
            }else{
                st.push(node);
                vis.insert(prefSum);
            }
        }

        head = prevHead.next;
        prevHead.next = nullptr;

        return head;
    }
};