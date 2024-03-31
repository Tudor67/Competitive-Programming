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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }

        ListNode* tail1 = getMiddleNode(head);
        ListNode* head2 = tail1->next;
        ListNode* revHead2 = reverse(head2);
        tail1->next = nullptr;

        ListNode* p1 = head;
        ListNode* p2 = revHead2;
        while(p2 != nullptr){
            ListNode* p1Next = p1->next;
            ListNode* p2Next = p2->next;
            p1->next = p2;
            p2->next = p1Next;
            p1 = p1Next;
            p2 = p2Next;
        }
    }
};