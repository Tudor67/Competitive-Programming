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
    ListNode* reverse(ListNode* head){
        ListNode* currentNode = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while(currentNode != nullptr){
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* revHead = reverse(head);

        int prefMax = revHead->val;
        ListNode* resTail = revHead;
        for(ListNode* node = revHead->next; node != nullptr; node = node->next){
            if(prefMax <= node->val){
                prefMax = node->val;
                resTail->next = node;
                resTail = node;
            }
        }
        resTail->next = nullptr;

        return reverse(revHead);
    }
};