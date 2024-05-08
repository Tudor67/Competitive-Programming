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
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = nullptr;
        while(currNode != nullptr){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* revHead = reverse(head);
        
        int maxVal = revHead->val;
        ListNode* prevNode = revHead;
        ListNode* currNode = revHead->next;
        while(currNode != nullptr){
            if(currNode->val < maxVal){
                prevNode->next = currNode->next;
                currNode = currNode->next;
            }else{
                maxVal = currNode->val;
                prevNode = currNode;
                currNode = currNode->next;
            }
        }

        return reverse(revHead);
    }
};