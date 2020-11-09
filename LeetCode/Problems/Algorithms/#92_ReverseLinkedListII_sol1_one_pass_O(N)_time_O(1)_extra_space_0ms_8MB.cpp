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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n){
            return head;
        }
        
        // virtualHead - dummy node that points to the original head of the list
        ListNode* virtualHead = new ListNode(0);
        virtualHead->next = head;
        
        // node1 - first node of the sublist we should reverse
        // node2 - last node of the sublist we should reverse
        ListNode* prevNode1 = NULL;
        ListNode* node1 = NULL;
        ListNode* node2 = NULL;
        
        // prevNode, node, nextNode
        ListNode* prevNode = virtualHead;
        ListNode* node = head;
        ListNode* nextNode = NULL;
        
        // iterate from the first node to the nth node and reverse the [m, n] sublist
        for(int pos = 1; pos <= n; ++pos){
            nextNode = node->next;
            if(m <= pos && pos <= n){
                node->next = prevNode;
                if(pos == m){
                    prevNode1 = prevNode;
                    node1 = node;
                }
                if(pos == n){
                    node2 = node;
                }
            }
            prevNode = node;
            node = nextNode;
        }
        
        // update the first and the last nodes of the reversed sublist
        prevNode1->next = node2;
        node1->next = nextNode;
        
        return virtualHead->next;
    }
};