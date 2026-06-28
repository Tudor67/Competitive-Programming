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
    int pairSum(ListNode* head) {
        vector<int> values;
        for(ListNode* node = head; node != nullptr; node = node->next){
            values.push_back(node->val);
        }

        int maxTwinSum = 0;
        for(int i = 0, j = (int)values.size() - 1; i < j; ++i, --j){
            int twinSum = values[i] + values[j];
            maxTwinSum = max(maxTwinSum, twinSum);
        }

        return maxTwinSum;
    }
};