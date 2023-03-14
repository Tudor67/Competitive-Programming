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
    const int K = 1;
    vector<int> reservoir;
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(nullptr));
    }
    
    int getRandom() {
        reservoir.clear();

        int n = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            n += 1;
            if((int)reservoir.size() < K){
                reservoir.push_back(node->val);
            }else{
                int randIndex = rand() % n;
                if(randIndex < K){
                    reservoir[randIndex] = node->val;
                }
            }
        }

        return reservoir[K - 1];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */