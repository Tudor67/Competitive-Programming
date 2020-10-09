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
    bool isPalindrome(ListNode* head) {
        // Split the initial list into l1(first listSize/2 elements) and l2(last listSize/2 elements)
        // Reverse l1
        // Compare l1Reversed with l2
        
        // Step 0: compute listSize
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        bool isPalindrome = true;
        if(listSize >= 2){
            // Step 1: find l2Head
            ListNode* l2Head = head;
            for(int i = 1; i <= (listSize + 1) / 2; ++i){
                l2Head = l2Head->next;
            }
            
            // Step 2: reverse l1 and find l1ReversedHead
            ListNode* prevNode = NULL;
            ListNode* curNode = head;
            for(int i = 1; i <= listSize / 2; ++i){
                ListNode* temp = curNode->next;
                curNode->next = prevNode;
                prevNode = curNode;
                curNode = temp;
            }
            ListNode* l1ReversedHead = prevNode;
            ListNode* connectionToRemainingNodes = curNode;
            
            // Step 3: compare l1Reversed with l2
            ListNode* l1 = l1ReversedHead;
            ListNode* l2 = l2Head;
            while(isPalindrome && l1 != NULL){
                if(l1->val == l2->val){
                    l1 = l1->next;
                    l2 = l2->next;
                }else{
                    isPalindrome = false;
                }
            }
            
            // Step 4: restore the original list (reverse l1Reversed and connect it to the remaining nodes)
            prevNode = NULL;
            curNode = l1ReversedHead;
            while(curNode != NULL){
                ListNode* temp = curNode->next;
                curNode->next = prevNode;
                prevNode = curNode;
                curNode = temp;
            }
            l1ReversedHead->next = connectionToRemainingNodes;
        }
        
        return isPalindrome;
    }
};