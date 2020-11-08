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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* virtualHead = new ListNode(0, head);
        ListNode* prev = virtualHead;
        
        while(prev->next != NULL){
            ListNode* cur = prev->next;
            
            ListNode* aux = virtualHead;
            while(aux->next->val < cur->val && aux->next != cur){
                aux = aux->next;
            }
            
            if(aux->next != cur){
                ListNode* temp = cur->next;
                cur->next = aux->next;
                aux->next = cur;
                prev->next = temp;
            }else{
                prev = prev->next;
            }
        }
        
        return virtualHead->next;
    }
};