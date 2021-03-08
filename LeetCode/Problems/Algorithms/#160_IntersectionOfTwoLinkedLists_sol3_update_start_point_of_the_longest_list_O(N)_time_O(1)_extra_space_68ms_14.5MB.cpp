/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {        
        ListNode* pA = headA;
        ListNode* pB = headB;
        
        int listSizeA = getListSize(pA);
        int listSizeB = getListSize(pB);
        
        if(listSizeA < listSizeB){
            for(int i = 1; i <= listSizeB - listSizeA; ++i){
                pB = pB->next;
            }
        }else{
            for(int i = 1; i <= listSizeA - listSizeB; ++i){
                pA = pA->next;
            }
        }
        
        while(pA != pB){
            pA = pA->next;
            pB = pB->next;
        }
        
        return pA;
    }
};