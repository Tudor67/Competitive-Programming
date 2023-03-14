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
    vector<int> listValues;

public:
    Solution(ListNode* head) {
        for(ListNode* node = head; node != nullptr; node = node->next){
            listValues.push_back(node->val);
        }
        srand(time(nullptr));
    }
    
    int getRandom() {
        return listValues[rand() % listValues.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */