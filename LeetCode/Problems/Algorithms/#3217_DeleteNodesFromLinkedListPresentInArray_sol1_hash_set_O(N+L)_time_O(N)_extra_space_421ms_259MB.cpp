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
        
        ListNode* resHead = new ListNode();
        resHead->next = head;
        ListNode* resTail = resHead;
        for(ListNode* node = head; node != nullptr; node = node->next){
            if(!numsSet.count(node->val)){
                resTail->next = node;
                resTail = resTail->next;
            }
        }
        resTail->next = nullptr;

        head = resHead->next;
        resHead->next = nullptr;
        delete resHead;

        return head;
    }
};