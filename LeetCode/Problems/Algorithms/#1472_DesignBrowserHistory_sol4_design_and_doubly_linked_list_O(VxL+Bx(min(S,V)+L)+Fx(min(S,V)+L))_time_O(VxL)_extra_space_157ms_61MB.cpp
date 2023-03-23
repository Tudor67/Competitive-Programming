class DLLNode{
public:
    string val;
    DLLNode* prev;
    DLLNode* next;
    
public:
    DLLNode(string val = "", DLLNode* prev = nullptr, DLLNode* next = nullptr){
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

class DLL{
public:
    DLLNode* head;
    DLLNode* tail;

public:
    DLL(){
        head = nullptr;
        tail = nullptr;
    }
    
    ~DLL(){
        while(head != nullptr){
            DLLNode* ptr = head;
            head = head->next;
            delete ptr;
        }
    }
    
    void pushBack(const string& VAL){
        DLLNode* newNode = new DLLNode(VAL);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    DLLNode* erase(DLLNode* node){
        // Step 1: nullptr
        if(head == nullptr || node == nullptr){
            return nullptr;
        }
        
        // Step 2: special updates when node is head or tail
        if(head == node){
            head = node->next;
        }
        
        if(tail == node){
            tail = node->prev;
        }
        
        // Step 3: update the links of prevNode and nextNode
        DLLNode* prevNode = node->prev;
        DLLNode* nextNode = node->next;
        
        if(prevNode != nullptr){
            prevNode->next = nextNode;
        }
        if(nextNode != nullptr){
            nextNode->prev = prevNode;
        }
        
        // Step 4: delete node
        delete node;
        
        return nextNode;
    }
    
    DLLNode* erase(DLLNode* beginNode, DLLNode* endNode){
        while(beginNode != endNode){
            beginNode = erase(beginNode);
        }
        return beginNode;
    }
};

class BrowserHistory {
private:
    DLL historyList;
    DLLNode* currentIt;

public:
    BrowserHistory(string homepage) {
        historyList.pushBack(homepage);
        currentIt = historyList.head;
    }
    
    void visit(string url) {
        historyList.erase(currentIt->next, historyList.tail->next);
        historyList.pushBack(url);
        currentIt = historyList.tail;
    }
    
    string back(int steps) {
        while(steps >= 1 && currentIt != historyList.head){
            currentIt = currentIt->prev;
            steps -= 1;
        }
        return currentIt->val;
    }
    
    string forward(int steps) {
        while(steps >= 1 && currentIt != historyList.tail){
            currentIt = currentIt->next;
            steps -= 1;
        }
        return currentIt->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */