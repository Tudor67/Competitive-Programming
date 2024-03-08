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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listSize = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            listSize += 1;
        }

        ListNode* newHead = nullptr;
        if(listSize == n){
            newHead = head->next;
            head->next = nullptr;
        }else{
            newHead = head;
            ListNode* prevNode = head;
            ListNode* currNode = head->next;
            for(int i = 3; i <= listSize - n + 1; ++i){
                prevNode = prevNode->next;
                currNode = currNode->next;
            }
            prevNode->next = currNode->next;
            currNode->next = nullptr;
        }

        return newHead;
    }
};