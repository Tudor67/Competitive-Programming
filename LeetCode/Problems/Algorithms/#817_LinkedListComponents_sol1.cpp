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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> g_set;
        for(int num: G){
            g_set.insert(num);
        }
        
        int answer = 0;
        ListNode* node = head;
        while(node != NULL){
            while(node != NULL && !g_set.count(node->val)){
                node = node->next;
            }
            
            if(node != NULL){
                answer += 1;
                while(node != NULL && g_set.count(node->val)){
                    g_set.erase(node->val);
                    node = node->next;
                }
            }
        }
        
        return answer;
    }
};