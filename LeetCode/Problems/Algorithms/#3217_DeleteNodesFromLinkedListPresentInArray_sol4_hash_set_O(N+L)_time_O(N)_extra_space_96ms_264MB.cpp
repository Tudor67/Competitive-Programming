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
        ListNode* resPrevHead = new ListNode();
        ListNode* resTail = resPrevHead;

        unordered_set<int> numsSet(nums.begin(), nums.end());
        for(ListNode* currNode = head; currNode != nullptr; currNode = currNode->next){
            if(!numsSet.count(currNode->val)){
                resTail->next = currNode;
                resTail = resTail->next;
            }
        }
        resTail->next = nullptr;

        head = resPrevHead->next;
        resPrevHead->next = nullptr;
        delete resPrevHead;

        return head;
    }
};