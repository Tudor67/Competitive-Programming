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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* prevHead1 = new ListNode();
        ListNode* prevHead2 = new ListNode();
        ListNode* tail1 = prevHead1;
        ListNode* tail2 = prevHead2;
        
        int nodeIdx = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            nodeIdx += 1;
            if(nodeIdx % 2 == 1){
                tail1->next = node;
                tail1 = tail1->next;
            }else{
                tail2->next = node;
                tail2 = tail2->next;
            }
        }
        
        tail1->next = prevHead2->next;
        tail2->next = NULL;
        
        prevHead1->next = NULL;
        prevHead2->next = NULL;
        delete prevHead1;
        delete prevHead2;
        
        return head;
    }
};