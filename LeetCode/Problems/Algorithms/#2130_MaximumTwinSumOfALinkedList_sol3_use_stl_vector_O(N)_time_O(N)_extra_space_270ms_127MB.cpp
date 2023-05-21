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
        for(ListNode* node = head; node != nullptr; node = node->next){
            v.push_back(node->val);
        }

        int maxSum = v.front() + v.back();
        int i = 0;
        int j = (int)v.size() - 1;
        while(i < j){
            maxSum = max(maxSum, v[i] + v[j]);
            i += 1;
            j -= 1;
        }

        return maxSum;
    }
};