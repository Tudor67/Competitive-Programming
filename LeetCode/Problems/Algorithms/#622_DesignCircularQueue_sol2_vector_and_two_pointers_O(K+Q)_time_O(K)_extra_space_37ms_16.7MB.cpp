class MyCircularQueue {
private:
    int maxSize;
    int currentSize;
    vector<int> data;
    int frontIdx;
    int backIdx;
    
public:
    MyCircularQueue(int k) {
        maxSize = k;
        currentSize = 0;
        data.resize(maxSize);
        frontIdx = 0;
        backIdx = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        currentSize += 1;
        backIdx = (backIdx + 1) % maxSize;
        data[backIdx] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        currentSize -= 1;
        frontIdx = (frontIdx + 1) % maxSize;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return data[frontIdx];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return data[backIdx];
    }
    
    bool isEmpty() {
        return (currentSize == 0);
    }
    
    bool isFull() {
        return (currentSize == maxSize);
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