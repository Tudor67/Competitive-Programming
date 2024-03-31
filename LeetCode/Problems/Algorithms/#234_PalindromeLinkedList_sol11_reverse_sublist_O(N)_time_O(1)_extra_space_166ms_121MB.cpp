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
    ListNode* getMiddleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        while(currNode != nullptr){
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }

        ListNode* tail1 = getMiddleNode(head);
        ListNode* head2 = tail1->next;
        ListNode* revHead2 = reverse(head2);

        bool isPal = true;
        for(ListNode *node1 = head, *node2 = revHead2; node2 != nullptr; node1 = node1->next, node2 = node2->next){
            if(node1->val != node2->val){
                isPal = false;
            }
        }

        tail1->next = reverse(revHead2);
        
        return isPal;
    }
};