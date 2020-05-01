class LRUCache {
private:
    int first_key;
    int last_key;
    int capacity;
    unordered_map<int, int> val;
    unordered_map<int, int> prev;
    unordered_map<int, int> next;
    // Simulate a combination of queue and doubly linked list (with prev, next and val):
    // 1.) max size = capacity: O(capacity) space
    // 2.) get first and last element: O(1)
    // 3.) insert a new element at a given position: O(1)
    // 4.) move an existing element to the first or to the last position: O(1)    
    
    void update_last_key(int key, int value){
        if(val.count(key)){
            if(key == first_key && key != last_key){
                int temp = first_key;
                first_key = next[first_key];
                prev[first_key] = -1;
                prev.erase(temp);
                next.erase(temp);
                val.erase(temp);
                // update last_key
                next[last_key] = key;
                prev[key] = last_key;
                next[key] = -1;
                val[key] = value;
                last_key = key;
            }else if(key != last_key){
                next[prev[key]] = next[key];
                prev[next[key]] = prev[key];
                // update last_key
                next[last_key] = key;
                prev[key] = last_key;
                next[key] = -1;
                val[key] = value;
                last_key = key;
            }else{
                val[key] = value;
            }
        }else{
            // update last_key
            next[last_key] = key;
            prev[key] = last_key;
            next[key] = -1;
            val[key] = value;
            last_key = key;
        }
        
        if(val.size() == capacity + 1){
            // remove first_key: least recently used
            int temp = first_key;
            first_key = next[first_key];
            prev[first_key] = -1;
            prev.erase(temp);
            next.erase(temp);
            val.erase(temp);
        }
    }
    
    void print(){
        int key = first_key;
        while(key != -1){
            cout << "(" << key << ", " << val[key] << ") -> ";
            key = next[key];
        }
        cout << endl;
    }
    
public:
    LRUCache(int capacity) {
        this->first_key = -1;
        this->last_key = -1;
        this->capacity = capacity;
    }
    
    int get(int key) {
        //cout << "get: \n";
        //if(!val.empty()) print();
        if(val.count(key)){
            if(capacity > 1){
                update_last_key(key, val[key]);
            }
            return val[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 1){
            val.erase(first_key);
            val[key] = value;
            first_key = key;
        }else{
            if(first_key == -1){
                first_key = key;
                last_key = key;
                prev[key] = -1;
                next[key] = -1;
                val[key] = value;
            }else{
                // update the last_key: most recently used
                update_last_key(key, value);
            }
        }
        //cout << "put: \n";
        //print();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */