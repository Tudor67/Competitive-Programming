class MyCircularDeque {
private:
    vector<int> v;
    int currSize;
    int frontIndex;
    int lastIndex;

public:
    MyCircularDeque(int k) {
        v.assign(k, 0);
        currSize = 0;
        frontIndex = 1;
        lastIndex = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        currSize += 1;
        frontIndex = (frontIndex - 1 + (int)v.size()) % (int)v.size();
        v[frontIndex] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        currSize += 1;
        lastIndex = (lastIndex + 1) % (int)v.size();
        v[lastIndex] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        currSize -= 1;
        frontIndex = (frontIndex + 1) % (int)v.size();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        currSize -= 1;
        lastIndex = (lastIndex - 1 + (int)v.size()) % (int)v.size();
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return v[frontIndex];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return v[lastIndex];
    }
    
    bool isEmpty() {
        return (currSize == 0);
    }
    
    bool isFull() {
        return ((int)v.size() == currSize);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */