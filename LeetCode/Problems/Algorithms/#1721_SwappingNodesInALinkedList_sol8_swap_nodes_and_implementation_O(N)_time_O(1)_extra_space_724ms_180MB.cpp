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

    ListNode* kthNode(ListNode* head, int k){
        ListNode* node = head;
        for(int i = 1; i <= k - 1 && node != nullptr; ++i){
            node = node->next;
        }
        return node;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        // create a node that points to the head
        ListNode* prevHead = new ListNode();
        prevHead->next = head;

        // compute list size
        int listSize = computeListSize(head);
        int firstPos = min(k, listSize - k + 1);
        int secondPos = max(k, listSize - k + 1);

        // find the kth and (listSize - k + 1)th nodes of the input list
        // and their predecessors/previous nodes
        ListNode* prevFirstNode = kthNode(prevHead, firstPos);
        ListNode* firstNode = prevFirstNode->next;
        ListNode* prevSecondNode = kthNode(prevHead, secondPos);
        ListNode* secondNode = prevSecondNode->next;

        // swap the kth and (listSize - k + 1)th nodes
        if(firstNode == secondNode){
            // ok
        }else if(firstNode->next == secondNode){
            ListNode* nextSecondNode = secondNode->next;
            prevFirstNode->next = secondNode;
            secondNode->next = firstNode;
            firstNode->next = nextSecondNode;
        }else{
            ListNode* nextFirstNode = firstNode->next;
            ListNode* nextSecondNode = secondNode->next;
            prevFirstNode->next = secondNode;
            secondNode->next = nextFirstNode;
            prevSecondNode->next = firstNode;
            firstNode->next = nextSecondNode;
        }

        // delete the node that points to the head
        head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;

        return head;
    }
};