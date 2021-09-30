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
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        vector<ListNode*> listParts(k, NULL);
        listParts[0] = head;
        for(int i = 0; i < k - 1; ++i){
            int targetPartSize = (listSize / k) + int((i + 1) % k <= listSize % k);
            ListNode* node = listParts[i];
            for(int partSize = 1; partSize < targetPartSize; ++partSize){
                node = node->next;
            }
            if(node != NULL){
                listParts[i + 1] = node->next;
                node->next = NULL;
            }
        }
        
        return listParts;
    }
};