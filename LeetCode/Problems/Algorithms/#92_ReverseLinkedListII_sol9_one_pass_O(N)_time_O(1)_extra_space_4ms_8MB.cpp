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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }

        ListNode* prevHead = new ListNode(0, head);

        ListNode* prevLeftNode = prevHead;
        ListNode* leftNode = head;
        ListNode* rightNode = nullptr;

        ListNode* prevNode = nullptr;
        ListNode* node = head;
        ListNode* nextNode = nullptr;

        for(int i = 1; i <= right; ++i){
            if(i < left - 1){
                node = node->next;
            }else if(i == left - 1){
                prevLeftNode = node;
                node = node->next;
            }else if(i == left){
                leftNode = node;
                prevNode = leftNode;
                node = node->next;
            }else if(left < i){
                rightNode = node;
                nextNode = node->next;
                node->next = prevNode;
                prevNode = node;
                node = nextNode;
            }
        }
        
        prevLeftNode->next = rightNode;
        leftNode->next = node;

        head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;

        return head;
    }
};