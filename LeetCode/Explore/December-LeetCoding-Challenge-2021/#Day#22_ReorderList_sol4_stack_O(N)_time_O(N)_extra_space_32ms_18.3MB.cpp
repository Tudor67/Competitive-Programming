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
    void reorderList(ListNode* head) {
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        stack<ListNode*> st;
        ListNode* node = head;
        for(int i = 1; i <= listSize; ++i){
            if(i > (listSize + 1) / 2){
                st.push(node);
            }
            node = node->next;
        }
        
        node = head;
        for(int i = 1; i <= listSize / 2; ++i){
            ListNode* tempNode = node->next;
            node->next = st.top();
            st.pop();
            node = node->next;
            node->next = tempNode;
            node = tempNode;
        }
        node->next = NULL;
    }
};