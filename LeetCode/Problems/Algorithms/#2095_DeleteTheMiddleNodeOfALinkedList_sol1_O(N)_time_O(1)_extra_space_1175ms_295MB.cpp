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
    ListNode* deleteMiddle(ListNode* head) {
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        if(listSize <= 1){
            delete head;
            head = NULL;
        }else{
            ListNode* node = head;
            for(int i = 1; i <= listSize / 2 - 1; ++i){
                node = node->next;
            }
            
            ListNode* tempNode = node->next;
            node->next = node->next->next;
            tempNode->next = NULL;
            delete tempNode;
        }
        
        return head;
    }
};