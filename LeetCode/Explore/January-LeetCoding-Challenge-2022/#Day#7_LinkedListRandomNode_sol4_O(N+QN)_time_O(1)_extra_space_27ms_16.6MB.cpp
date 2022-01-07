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
    Solution(ListNode* head) {
        this->head = head;
        this->listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            this->listSize += 1;
        }
        srand(time(NULL));
    }
    
    int getRandom() {
        int randIdx = rand() % listSize;
        ListNode* node = head;
        for(int i = 1; i <= randIdx; ++i){
            node = node->next;
        }
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */