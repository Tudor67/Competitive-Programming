class MyCircularDeque {
private:
    vector<int> v;
    int frontPos;
    int backPos;
    int currentSize;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        v.resize(k);
        frontPos = 1;
        backPos = 0;
        currentSize = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        frontPos = (frontPos - 1 + v.size()) % v.size();
        v[frontPos] = value;
        currentSize += 1;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        backPos = (backPos + 1) % v.size();
        v[backPos] = value;
        currentSize += 1;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        frontPos = (frontPos + 1) % v.size();
        currentSize -= 1;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        backPos = (backPos - 1 + v.size()) % v.size();
        currentSize -= 1;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return v[frontPos];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return v[backPos];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (currentSize == 0);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (currentSize == (int)v.size());
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