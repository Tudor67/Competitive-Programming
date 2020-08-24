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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int list_size = 0;
        for(ListNode* node = root; node != NULL; node = node->next){
            list_size += 1;
        }
        
        vector<ListNode*> answer;
        int q = list_size / k;
        int r = list_size % k;
        ListNode* node = root;
        
        while(node != NULL){
            answer.push_back(node);
            for(int i = 2; node != NULL && i <= q + (r > 0); ++i){
                node = node->next;
            }
            if(node != NULL){
                ListNode* temp = node;
                node = node->next;
                temp->next = NULL;
            }
            if(r > 0){
                r -= 1;
            }
        }
        
        while(answer.size() < k){
            answer.push_back(NULL);
        }
        
        return answer;
    }
};