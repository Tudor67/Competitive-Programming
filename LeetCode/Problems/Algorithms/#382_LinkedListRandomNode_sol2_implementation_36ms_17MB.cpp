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
    ListNode* head;
    int listSize;
    
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        this->listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            this->listSize += 1;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int nodeIdx = rand() % listSize;
        int nodeVal = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            if(nodeIdx == 0){
                nodeVal = node->val;
                break;
            }
            nodeIdx -= 1;
        }
        return nodeVal;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */