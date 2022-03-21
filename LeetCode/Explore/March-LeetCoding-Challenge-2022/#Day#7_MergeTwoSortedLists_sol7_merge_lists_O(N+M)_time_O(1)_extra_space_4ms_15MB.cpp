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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prevHead = new ListNode(0);
        ListNode* currentNode = prevHead;
        while(list1 != NULL || list2 != NULL){
            if(list2 == NULL || (list1 != NULL && list1->val < list2->val)){
                currentNode->next = list1;
                list1 = list1->next;
            }else{
                currentNode->next = list2;
                list2 = list2->next;
            }
            currentNode = currentNode->next;
        }
        
        ListNode* head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};