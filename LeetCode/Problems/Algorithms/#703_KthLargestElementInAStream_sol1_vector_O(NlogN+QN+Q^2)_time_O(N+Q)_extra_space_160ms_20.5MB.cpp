class KthLargest {
private:
    int k;
    vector<int> nums;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
    }
    
    int add(int val) {
        nums.resize(nums.size() + 1); 
        int pos = upper_bound(nums.begin(), prev(nums.end()), val) - nums.begin();
        copy_backward(nums.begin() + pos, prev(nums.end()), nums.end());
        nums[pos] = val;
        return nums[(int)nums.size() - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */