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
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }

        ListNode* resTail = head;
        ListNode* node = head->next;
        while(node != nullptr){
            if(numsSet.count(node->val)){
                ListNode* temp = node;
                node = node->next;
                temp->next = nullptr;
                delete temp;
            }else{
                resTail->next = node;
                resTail = resTail->next;
                node = node->next;
            }
        }
        resTail->next = nullptr;

        return head;
    }
};