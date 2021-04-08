class MyCircularQueue {
private:
    vector<int> values;
    int currentSize;
    int frontPos;
    int backPos;
    
public:
    MyCircularQueue(int k) {
        values.resize(k);
        currentSize = 0;
        frontPos = 0;
        backPos = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        currentSize += 1;
        backPos = (backPos + 1) % values.size();
        values[backPos] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        currentSize -= 1;
        frontPos = (frontPos + 1) % values.size();
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return values[frontPos];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return values[backPos];
    }
    
    bool isEmpty() {
        return (currentSize == 0);
    }
    
    bool isFull() {
        return (currentSize == (int)values.size());
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */