class MyListNode{
public:
    int key;
    int val;
    MyListNode* prev;
    MyListNode* next;
    
public:
    MyListNode(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class MyList{
public:
    MyListNode* head;
    MyListNode* tail;
    
public:
    MyList(){
        head = NULL;
        tail = NULL;
    }
    
    ~MyList(){
        for(MyListNode* node = head; node != NULL; node = node->next){
            delete node->prev;
        }
        delete tail;
    }
    
    void pushFront(int key, int val){
        MyListNode* node = new MyListNode(key, val);
        if(head == NULL){
            head = node;
            tail = node;
        }else{
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    
    void erase(MyListNode* node){
        if(head == tail){
            head = NULL;
            tail = NULL;
        }else if(node == head){
            head = head->next;
            head->prev = NULL;
        }else if(node == tail){
            tail = tail->prev;
            tail->next = NULL;
        }else{
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
    }
};

class LRUCache {
private:
    int capacity;
    MyList cache;
    unordered_map<int, MyListNode*> nodeInCache;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(!nodeInCache.count(key)){
            return -1;
        }
        int value = nodeInCache[key]->val;
        cache.erase(nodeInCache[key]);
        cache.pushFront(key, value);
        nodeInCache[key] = cache.head;
        return value;
    }
    
    void put(int key, int value) {
        if(nodeInCache.count(key)){
            cache.erase(nodeInCache[key]);
        }else{
            if((int)nodeInCache.size() == capacity){
                nodeInCache.erase(cache.tail->key);
                cache.erase(cache.tail);
            }
        }
        cache.pushFront(key, value);
        nodeInCache[key] = cache.head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */