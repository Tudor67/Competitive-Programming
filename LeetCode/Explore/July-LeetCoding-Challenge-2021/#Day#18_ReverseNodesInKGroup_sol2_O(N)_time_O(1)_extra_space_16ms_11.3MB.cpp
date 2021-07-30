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
    int getListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        const int TOTAL_STEPS = getListSize(head) / k;
        ListNode* prevHead = new ListNode(0, head);
        ListNode* sublistPrevHead = prevHead;
        ListNode* sublistHead = head;
        
        for(int step = 1; step <= TOTAL_STEPS; ++step){
            // reverse the sublist of size k which starts at sublistHead
            ListNode* prevNode = NULL;
            ListNode* curNode = sublistHead;
            ListNode* nextNode = NULL;
            for(int i = 1; i <= k; ++i){
                nextNode = curNode->next;
                curNode->next = prevNode;
                prevNode = curNode;
                curNode = nextNode;
            }
            
            // connect the reversed sublist to list
            sublistPrevHead->next = prevNode;
            sublistHead->next = curNode;
            
            // update sublistPrevHead and sublistHead for the next step
            sublistPrevHead = sublistHead;
            sublistHead = curNode;
        }
        
        return prevHead->next;
    }
};