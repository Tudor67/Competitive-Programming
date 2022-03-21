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
    int computeListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    ListNode* getKThNode(ListNode* prevHead, int k){
        ListNode* node = prevHead;
        for(int i = 0; i <= k - 1; ++i){
            node = node->next;
        }
        return node;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int listSize = computeListSize(head);
        if(head == NULL || k % listSize == 0){
            return head;
        }
        
        k %= listSize;
        
        ListNode* prevHead = new ListNode(0, head);
        ListNode* prevNode = getKThNode(prevHead, listSize - k);
        ListNode* node = getKThNode(prevHead, listSize - k + 1);
        ListNode* tail = getKThNode(prevHead, listSize);
        
        prevNode->next = NULL;
        prevHead->next = node;
        tail->next = head;
        
        head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};