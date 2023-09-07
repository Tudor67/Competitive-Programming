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
    ListNode* getKthNode(ListNode* prevHead, int k){
        ListNode* node = prevHead;
        for(int i = 1; i <= k && node != nullptr; ++i){
            node = node->next;
        }
        return node;
    }

    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* prevNode = nullptr;
        ListNode* node = head;
        ListNode* nextNode = nullptr;
        while(prevNode != tail){
            nextNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nextNode;
        }
        return prevNode;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prevHead = new ListNode(0, head);

        ListNode* prevLeftNode = getKthNode(prevHead, left - 1);
        ListNode* leftNode = prevLeftNode->next;
        ListNode* rightNode = getKthNode(prevHead, right);
        ListNode* nextRightNode = rightNode->next;

        prevLeftNode->next = reverse(leftNode, rightNode);
        leftNode->next = nextRightNode;

        head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;

        return head;
    }
};