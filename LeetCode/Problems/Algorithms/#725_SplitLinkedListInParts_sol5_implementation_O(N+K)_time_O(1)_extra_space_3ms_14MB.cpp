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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int listSize = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            listSize += 1;
        }

        vector<ListNode*> res(k, nullptr);
        ListNode* node = head;
        for(int partIndex = 0; partIndex < k && node != nullptr; ++partIndex){
            res[partIndex] = node;
            int partSize = (listSize / k) + (int)(partIndex < listSize % k);
            for(int i = 1; i <= partSize - 1; ++i){
                node = node->next;
            }
            ListNode* nextNode = node->next;
            node->next = nullptr;
            node = nextNode;
        }

        return res;
    }
};