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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* virtualHead = new ListNode(0, head);
        ListNode* node = virtualHead;
        
        while(node != NULL){
            ListNode* p = node->next;
            bool isDuplicate = false;
            while(p != NULL && p->next != NULL && p->val == p->next->val){
                isDuplicate = true;
                ListNode* temp = p->next;
                delete p;
                p = temp;
            }
            
            if(isDuplicate){
                node->next = p->next;
                delete p;
            }else{
                node = node->next;
            }
        }
        
        return virtualHead->next;
    }
};