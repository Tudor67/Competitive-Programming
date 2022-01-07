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
    static const int K = 1;
    ListNode* head;
    
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    
    int getRandom() {
        int chosenVal = head->val;
        int i = 1;
        for(ListNode* node = head->next; node != NULL; node = node->next){
            i += 1;
            int j = 1 + rand() % i;
            if(j <= K){
                chosenVal = node->val;
            }
        }
        return chosenVal;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */