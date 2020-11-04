class KthLargest {
private:
    int k;
    multiset<int> values;
    
public:
    KthLargest(int k_, vector<int>& nums_) {
        k = k_;
        values = multiset<int>(nums_.begin(), nums_.end());
        while(values.size() > k){
            values.erase(values.begin());
        }
    }
    
    int add(int val) {
        values.insert(val);
        if(values.size() > k){
            values.erase(values.begin());
        }
        return *values.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */