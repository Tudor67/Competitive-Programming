class KthLargest {
private:
    vector<int> v;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->v = nums;
        sort(v.rbegin(), v.rend());
        if((int)v.size() > k){
            v.resize(k);
        }
    }
    
    int add(int val) {
        v.insert(upper_bound(v.begin(), v.end(), val, greater<int>()), val);
        if((int)v.size() == k + 1){
            v.pop_back();
        }
        return v[k - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */