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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;
        int firstValidIndex = -1;
        int prevValidIndex = -1;
        int currIndex = 1;

        for(ListNode* prevNode = head; prevNode->next != nullptr && prevNode->next->next != nullptr; prevNode = prevNode->next){
            ListNode* currNode = prevNode->next;
            ListNode* nextNode = currNode->next;
            if((prevNode->val < currNode->val && currNode->val > nextNode->val) ||
               (prevNode->val > currNode->val && currNode->val < nextNode->val)){
                if(firstValidIndex == -1){
                    firstValidIndex = currIndex;
                }else{
                    minDistance = min(minDistance, currIndex - prevValidIndex);
                    maxDistance = max(maxDistance, currIndex - firstValidIndex);
                }
                prevValidIndex = currIndex;
            }
            currIndex += 1;
        }

        if(minDistance == INT_MAX){
            minDistance = -1;
            maxDistance = -1;
        }
        
        return {minDistance, maxDistance};
    }
};