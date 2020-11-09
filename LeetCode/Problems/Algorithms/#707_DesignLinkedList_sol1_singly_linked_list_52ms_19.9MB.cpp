struct MyListNode{
    int val;
    MyListNode* next;
    
    MyListNode(int val, MyListNode* next): val(val), next(next){}
    MyListNode(int val): MyListNode(val, NULL){}
};

class MyLinkedList {
private:
    MyListNode* head;
    MyListNode* tail;
    int listSize;
    
    MyListNode* getNodeAt(int index){
        MyListNode* node = head;
        for(int i = 0; i < index; ++i){
            node = node->next;
        }
        return node;
    }
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        listSize = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= listSize){
            return -1;
        }
        return getNodeAt(index)->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyListNode* newHead = new MyListNode(val);
        newHead->next = head;
        head = newHead;
        if(tail == NULL){
            tail = newHead;
        }
        listSize += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyListNode* newTail = new MyListNode(val);
        if(tail == NULL){
            head = newTail;
        }else{
            tail->next = newTail;
        }
        tail = newTail;
        listSize += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || listSize < index){
            return;
        }else if(index == 0){
            addAtHead(val);
        }else if(index == listSize){
            addAtTail(val);
        }else{
            MyListNode* node = getNodeAt(index - 1);
            MyListNode* temp = node->next;
            node->next = new MyListNode(val, temp);
            listSize += 1;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || listSize <= index){
            return;
        }else if(index == 0){
            MyListNode* temp = head->next;
            delete head;
            head = temp;
            listSize -= 1;
            if(listSize == 0){
                tail = NULL;
            }
        }else if(index == listSize - 1){
            MyListNode* node = getNodeAt(index - 1);
            delete node->next;
            node->next = NULL;
            tail = node;
            listSize -= 1;
        }else{
            MyListNode* node = getNodeAt(index - 1);
            MyListNode* temp = node->next->next;
            delete node->next;
            node->next = temp;
            listSize -= 1;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */