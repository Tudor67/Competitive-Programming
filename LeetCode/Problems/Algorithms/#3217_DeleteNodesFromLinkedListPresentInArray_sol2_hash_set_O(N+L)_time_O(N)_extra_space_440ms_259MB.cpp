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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet(nums.begin(), nums.end());

        while(numsSet.count(head->val)){
            head = head->next;
        }
        
        ListNode* resTail = head;
        for(ListNode* node = head->next; node != nullptr; node = node->next){
            if(!numsSet.count(node->val)){
                resTail->next = node;
                resTail = resTail->next;
            }
        }
        resTail->next = nullptr;

        return head;
    }
};