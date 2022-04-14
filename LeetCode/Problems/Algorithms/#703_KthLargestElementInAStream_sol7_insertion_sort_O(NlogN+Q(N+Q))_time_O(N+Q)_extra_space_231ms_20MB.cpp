class KthLargest {
private:
    vector<int> nums;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;
        sort(this->nums.begin(), this->nums.end());
    }
    
    int add(int val) {
        nums.push_back(val);
        int pos = upper_bound(nums.begin(), nums.end() - 1, val) - nums.begin();
        copy_backward(nums.begin() + pos, nums.end() - 1, nums.end());
        nums[pos] = val;
        return nums[(int)nums.size() - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */