/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1: special case
        if(head == nullptr){
            return nullptr;
        }

        // Step 2: create a copy for each node of the input list
        //         such that a node is followed by its copy
        //         A -> ACopy -> B -> BCopy -> ...
        //         (update only the `->next` fields of the nodes)
        for(Node* node = head; node != nullptr; node = node->next->next){
            Node* nodeCopy = new Node(node->val);
            nodeCopy->next = node->next;
            node->next = nodeCopy;
        }

        // Step 3: update the `->random` fields of the copied nodes
        for(Node* node = head; node != nullptr; node = node->next->next){
            if(node->random != nullptr){
                Node* nodeCopy = node->next;
                nodeCopy->random = node->random->next;
            }
        }

        // Step 4: split the input list and its copy
        Node* headCopy = head->next;
        Node* tailCopy = head->next;
        Node* tail = head;
        while(tailCopy != nullptr){
            tail->next = tail->next->next;
            if(tailCopy->next != nullptr){
                tailCopy->next = tailCopy->next->next;
            }
            tail = tail->next;
            tailCopy = tailCopy->next;
        }

        return headCopy;
    }
};