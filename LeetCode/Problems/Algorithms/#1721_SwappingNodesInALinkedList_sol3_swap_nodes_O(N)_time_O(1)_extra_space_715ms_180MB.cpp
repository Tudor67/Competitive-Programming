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
    ListNode* kThNode(ListNode* node, int k){
        while(k > 0){
            node = node->next;
            k -= 1;
        }
        return node;
    }
    
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        int firstPos = min(k, listSize + 1 - k);
        int secondPos = max(k, listSize + 1 - k);
        
        if(firstPos != secondPos){
            ListNode* prevHead = new ListNode(0, head);
            ListNode* prevFirstNode = kThNode(prevHead, firstPos - 1);
            ListNode* firstNode = prevFirstNode->next;
            ListNode* nextFirstNode = firstNode->next;
            ListNode* prevSecondNode = kThNode(prevHead, secondPos - 1);
            ListNode* secondNode = prevSecondNode->next;
            ListNode* nextSecondNode = secondNode->next;
            
            if(firstPos + 1 == secondPos){
                prevFirstNode->next = secondNode;
                secondNode->next = firstNode;
                firstNode->next = nextSecondNode;
            }else{
                prevFirstNode->next = secondNode;
                secondNode->next = nextFirstNode;
                prevSecondNode->next = firstNode;
                firstNode->next = nextSecondNode;
            }
            
            head = prevHead->next;
            prevHead->next = NULL;
            delete prevHead;
        }
        
        return head;
    }
};