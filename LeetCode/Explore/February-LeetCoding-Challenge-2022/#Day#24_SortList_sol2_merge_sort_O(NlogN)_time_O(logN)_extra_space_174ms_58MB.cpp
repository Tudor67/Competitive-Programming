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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* prevHead = new ListNode(0);
        ListNode* curNode = prevHead;
        while(head1 != NULL || head2 != NULL){
            if(head2 == NULL || (head1 != NULL && head1->val < head2->val)){
                curNode->next = head1;
                head1 = head1->next;
            }else{
                curNode->next = head2;
                head2 = head2->next;
            }
            curNode = curNode->next;
        }
        head1 = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        return head1;
    }
    
    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prevMid = head;
        ListNode* mid = head;
        ListNode* node = head;
        while(node != NULL && node->next != NULL){
            prevMid = mid;
            mid = mid->next;
            node = node->next->next;
        }
        prevMid->next = NULL;
        ListNode* l = mergeSort(head);
        ListNode* r = mergeSort(mid);
        return merge(l, r);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};