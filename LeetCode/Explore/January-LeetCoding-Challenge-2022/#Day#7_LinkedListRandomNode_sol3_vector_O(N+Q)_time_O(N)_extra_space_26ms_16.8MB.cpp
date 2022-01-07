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
    vector<int> values;
    
public:
    Solution(ListNode* head) {
        for(ListNode* node = head; node != NULL; node = node->next){
            values.push_back(node->val);
        }
        srand(time(NULL));
    }
    
    int getRandom() {
        int randIdx = rand() % values.size();
        return values[randIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */