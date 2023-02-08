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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aPrevNode = nullptr;
        ListNode* bNode = nullptr;

        ListNode* currentNode = list1;
        for(int i = 0; i <= b; ++i){
            if(i == a - 1){
                aPrevNode = currentNode;
            }
            if(i == b){
                bNode = currentNode;
            }
            currentNode = currentNode->next;
        }

        ListNode* tail2 = list2;
        while(tail2->next != nullptr){
            tail2 = tail2->next;
        }

        aPrevNode->next = list2;
        tail2->next = bNode->next;
        bNode->next = nullptr;

        return list1;
    }
};