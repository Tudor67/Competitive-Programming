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
    ListNode* getKthNode(ListNode* head, int k){
        ListNode* node = head;
        while(node->next != nullptr && k >= 1){
            node = node->next;
            k -= 1;
        }
        return node;
    }

public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aPrevNode = getKthNode(list1, a - 1);
        ListNode* bNode = getKthNode(list1, b);
        ListNode* list2Tail = getKthNode(list2, INT_MAX);

        aPrevNode->next = list2;
        list2Tail->next = bNode->next;
        bNode->next = nullptr;

        return list1;
    }
};