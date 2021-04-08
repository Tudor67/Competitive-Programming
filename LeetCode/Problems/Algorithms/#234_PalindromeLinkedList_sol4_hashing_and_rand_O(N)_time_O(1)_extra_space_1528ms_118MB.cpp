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
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        
        bool isPalindrome = true;
        for(int iteration = 1; iteration <= 3 && isPalindrome; ++iteration){
            long long sum = 0;
            ListNode* node = head;
            for(int i = 1; i <= listSize; ++i){
                if(listSize % 2 == 1 && i == listSize / 2 + 1){
                    // ignore middle element
                }else{
                    srand(iteration + min(i, listSize - i + 1));
                    long long sign = (i <= listSize / 2 ? 1 : -1);
                    sum += rand() * sign * node->val;
                }
                node = node->next;
            }
            
            if(sum != 0){
                isPalindrome = false;
            }
        }
        
        return isPalindrome;
    }
};