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
        int size = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            size += 1;
        }
        return size;
    }
    
    ListNode* getNodeAt(ListNode* head, int k){
        ListNode* node = head;
        for(int i = 0; i < k && node != NULL; ++i){
            node = node->next;
        }
        return node;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = getListSize(headA);
        int sizeB = getListSize(headB);
        
        ListNode* nodeA = getNodeAt(headA, sizeA - sizeB);
        ListNode* nodeB = getNodeAt(headB, sizeB - sizeA);
        
        while(nodeA != nodeB){
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        
        return nodeA;
    }
};