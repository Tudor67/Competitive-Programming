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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* head1 = new ListNode();
        ListNode* head2 = new ListNode();
        ListNode* tail1 = head1;
        ListNode* tail2 = head2;

        for(ListNode* node = head; node != nullptr; node = node->next){
            if(node->val < x){
                tail1->next = node;
                tail1 = tail1->next;
            }else{
                tail2->next = node;
                tail2 = tail2->next;
            }
        }
        
        tail1->next = head2->next;
        tail2->next = nullptr;
        head = head1->next;

        head1->next = nullptr;
        head2->next = nullptr;
        delete head1;
        delete head2;

        return head;
    }
};