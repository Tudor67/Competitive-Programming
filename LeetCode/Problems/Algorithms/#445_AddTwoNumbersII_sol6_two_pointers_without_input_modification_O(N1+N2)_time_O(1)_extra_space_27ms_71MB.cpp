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
    int computeListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            listSize += 1;
        }
        return listSize;
    }

    ListNode* reverseList(ListNode* node){
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while(node != nullptr){
            nextNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nextNode;
        }
        return prevNode;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prevL3 = new ListNode();
        ListNode* l3 = prevL3;

        // Step 1: compute sum of digits (by moving from left to right)
        int remElements1 = computeListSize(l1);
        int remElements2 = computeListSize(l2);

        while(remElements1 >= 1){
            int sum = 0;
            if(remElements1 == remElements2){
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
                remElements1 -= 1;
                remElements2 -= 1;
            }else if(remElements1 > remElements2){
                sum = l1->val;
                l1 = l1->next;
                remElements1 -= 1;
            }else{
                sum = l2->val;
                l2 = l2->next;
                remElements2 -= 1;
            }

            l3->next = new ListNode(sum);
            l3 = l3->next;
        }

        // Step 2: update the sum of digits using carry (by moving from right to left)
        //         equivalent to moving from left to right on the reversed list
        l3 = prevL3->next;
        prevL3->next = nullptr;
        delete prevL3;

        ListNode* l3Rev = reverseList(l3);
        ListNode* node = l3Rev;
        int carry = 0;
        while(node != nullptr){
            int sum = node->val + carry;
            node->val = sum % 10;
            if(node->next == nullptr && sum / 10 > 0){
                node->next = new ListNode();
            }
            node = node->next;
            carry = sum / 10;
        }

        l3 = reverseList(l3Rev);
        return l3;
    }
};