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
        ListNode* oddHead = new ListNode();
        ListNode* evenHead = new ListNode();
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        
        int index = 1;
        for(ListNode* node = head; node != nullptr; node = node->next){
            if(index % 2 == 1){
                oddTail->next = node;
                oddTail = oddTail->next;
            }else{
                evenTail->next = node;
                evenTail = evenTail->next;
            }
            index += 1;
        }

        evenTail->next = nullptr;
        oddTail->next = evenHead->next;

        oddHead->next = nullptr;
        evenHead->next = nullptr;
        delete oddHead;
        delete evenHead;

        return head;
    }
};