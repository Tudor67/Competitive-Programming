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
    ListNode* computePrevMidNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prevNode = nullptr;
        ListNode* node = head;
        while(node != nullptr){
            ListNode* nextNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nextNode;
        }
        return prevNode;
    }

public:
    int pairSum(ListNode* head) {
        // Step 1: find the middle node of the list
        ListNode* prevMidNode = computePrevMidNode(head);
        ListNode* midNode = prevMidNode->next;
        prevMidNode->next = nullptr;

        // Step 2: reverse the second half of the list
        ListNode* revHead = reverseList(midNode);

        // Step 3: compute the max sum of twin nodes
        //         by traversing the first half of the list and the second (reversed) half of the list
        ListNode* node1 = head;
        ListNode* node2 = revHead;
        int maxSum = node1->val + node2->val;
        while(node1 != nullptr){
            maxSum = max(maxSum, node1->val + node2->val);
            node1 = node1->next;
            node2 = node2->next;
        }

        // Step 4: restore the original list by reversing again the second half of the list
        //         and connecting it to the first half of the list
        midNode = reverseList(revHead);
        prevMidNode->next = midNode;

        return maxSum;
    }
};