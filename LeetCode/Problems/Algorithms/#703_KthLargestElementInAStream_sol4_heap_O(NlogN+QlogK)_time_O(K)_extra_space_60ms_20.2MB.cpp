class KthLargest {
private:
    using MinHeap = priority_queue<int, vector<int>, greater<int>>;
    MinHeap minHeap;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        minHeap = MinHeap(nums.begin(), nums.end());
        while(minHeap.size() > k){
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */