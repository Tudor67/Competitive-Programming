class KthLargest {
private:
    vector<int> nums;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;
    }
    
    int add(int val) {
        nums.push_back(val);
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[(int)nums.size() - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */