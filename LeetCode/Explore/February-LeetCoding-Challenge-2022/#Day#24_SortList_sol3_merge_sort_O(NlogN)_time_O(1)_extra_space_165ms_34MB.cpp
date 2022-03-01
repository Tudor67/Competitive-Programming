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
private:
    ListNode* getKthNode(ListNode* head, int k){
        ListNode* node = head;
        while(node != NULL && node->next != NULL && k > 1){
            node = node->next;
            k -= 1;
        }
        return node;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* prevHead = new ListNode();
        ListNode* node = prevHead;
        
        while(l1 != NULL || l2 != NULL){
            if(l2 == NULL || (l1 != NULL && l1->val < l2->val)){
                node->next = l1;
                l1 = l1->next;
            }else{
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        
        node = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return node;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        ListNode* prevHead = new ListNode(0, head);
        
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        for(int subListSize = 1; subListSize < listSize; subListSize *= 2){
            ListNode* l1PrevHead = prevHead;
            while(l1PrevHead->next != NULL){
                ListNode* l1Head = l1PrevHead->next;
                ListNode* l1Tail = getKthNode(l1Head, subListSize);
                if(l1Tail->next == NULL){
                    break;
                }
                
                ListNode* l2Head = l1Tail->next;
                ListNode* l2Tail = getKthNode(l2Head, subListSize);
                ListNode* l3Head = l2Tail->next;
                l1Tail->next = NULL;
                l2Tail->next = NULL;
                
                l1PrevHead->next = mergeTwoLists(l1Head, l2Head);
                
                while(l1PrevHead->next != NULL){
                    l1PrevHead = l1PrevHead->next;
                }
                l1PrevHead->next = l3Head;
            }
        }
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};