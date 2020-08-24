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
        for(ListNode* node = head; node != NULL; node = node->next){
            if(g_set.count(node->val) && (node->next == NULL || !g_set.count(node->next->val))){
                answer += 1;
            }
        }
        
        return answer;
    }
};