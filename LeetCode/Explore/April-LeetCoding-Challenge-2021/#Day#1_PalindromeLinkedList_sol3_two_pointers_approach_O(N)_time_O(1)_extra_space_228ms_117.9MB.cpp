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
    int getListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    ListNode* getKthListNode(ListNode* head, int k){
        for(ListNode* node = head; node != NULL; node = node->next){
            k -= 1;
            if(k == 0){
                return node;
            }
        }
        return NULL;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        while(head != NULL){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        int listSize = getListSize(head);
        ListNode* head1 = head;
        ListNode* tail1 = getKthListNode(head, listSize / 2);
        ListNode* head2 = tail1->next;
        ListNode* tail2 = reverseList(head2);
        
        bool isPalindrome = true;
        for(ListNode *p1 = head1, *p2 = tail2; p1 != NULL && p2 != NULL; p1 = p1->next, p2 = p2->next){
            if(p1->val != p2->val){
                isPalindrome = false;
                break;
            }
        }
        
        head2 = reverseList(tail2);
        tail1->next = head2;
        
        return isPalindrome;
    }
};