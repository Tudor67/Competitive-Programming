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

        vector<ListNode*> res(k);
        ListNode* node = head;
        for(int i = 0; i < k; ++i){
            int partSize = listSize / k;
            if(i + 1 <= listSize % k){
                partSize += 1;
            }

            res[i] = node;
            for(int j = 0; j < partSize - 1 && node != nullptr; ++j){
                node = node->next;
            }

            if(node != nullptr){
                ListNode* nextNode = node->next;
                node->next = nullptr;
                node = nextNode;
            }
        }

        return res;
    }
};