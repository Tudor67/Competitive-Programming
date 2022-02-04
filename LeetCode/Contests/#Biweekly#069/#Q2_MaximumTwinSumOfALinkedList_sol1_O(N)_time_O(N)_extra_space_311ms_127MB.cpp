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
        vector<int> v;
        for(ListNode* node = head; node != NULL; node = node->next){
            v.push_back(node->val);
        }
        
        const int N = v.size();
        int maxSum = 0;
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            int sum = v[i] + v[j];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};