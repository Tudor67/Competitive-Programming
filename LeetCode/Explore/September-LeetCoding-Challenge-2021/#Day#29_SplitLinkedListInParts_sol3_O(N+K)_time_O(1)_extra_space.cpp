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
        
        int q = listSize / k;
        int r = listSize % k;
        
        vector<ListNode*> listParts;
        ListNode* node = head;
        while(node != NULL){
            listParts.push_back(node);
            int targetPartSize = q + (int)((int)listParts.size() <= r);
            for(int partSize = 2; partSize <= targetPartSize; ++partSize){
                node = node->next;
            }
            if(node != NULL){
                ListNode* temp = node;
                node = node->next;
                temp->next = NULL;
            }
        }
        
        listParts.resize(k, NULL);
        
        return listParts;
    }
};