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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        const int INF = 1e9;

        vector<int> res = {INF, -INF};

        int firstValidPos = INF;
        int lastValidPos = INF;
        int pos = 1;

        for(ListNode* node = head; node->next->next != nullptr; node = node->next){
            if((node->val > node->next->val && node->next->val < node->next->next->val) ||
               (node->val < node->next->val && node->next->val > node->next->next->val)){
                if(firstValidPos != INF){
                    res[0] = min(res[0], pos - lastValidPos);
                    res[1] = max(res[1], pos - firstValidPos);
                }
                if(firstValidPos == INF){
                    firstValidPos = pos;
                }
                lastValidPos = pos;
            }
            pos += 1;
        }

        if(res[0] == INF){
            res = {-1, -1};
        }

        return res;
    }
};