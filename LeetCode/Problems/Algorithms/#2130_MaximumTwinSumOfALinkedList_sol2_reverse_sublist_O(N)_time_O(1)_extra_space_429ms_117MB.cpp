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
    ListNode* reverseList(ListNode* head){
        ListNode* previousNode = NULL;
        ListNode* currentNode = head;
        ListNode* nextNode = NULL;
        while(currentNode != NULL){
            nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        return previousNode;
    }
    
public:
    int pairSum(ListNode* head) {
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        ListNode* prevMid = NULL;
        ListNode* mid = head;
        for(int i = 1; i <= listSize / 2; ++i){
            prevMid = mid;
            mid = mid->next;
        }
        
        ListNode* midRev = reverseList(mid);
        
        int maxSum = 0;
        ListNode* node1 = head;
        ListNode* node2 = midRev;
        for(int i = 1; i <= listSize / 2; ++i){
            int sum = node1->val + node2->val;
            maxSum = max(maxSum, sum);
            node1 = node1->next;
            node2 = node2->next;
        }
        
        prevMid->next = reverseList(midRev);
        
        return maxSum;
    }
};