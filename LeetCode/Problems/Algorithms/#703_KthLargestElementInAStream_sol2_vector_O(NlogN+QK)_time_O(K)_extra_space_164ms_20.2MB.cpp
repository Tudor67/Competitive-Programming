class KthLargest {
private:
    int k;
    vector<int> nums;
    
public:
    KthLargest(int k_, vector<int>& nums_) {
        k = k_;
        nums = nums_;
        sort(nums.begin(), nums.end());
        if(nums.size() > k){
            copy(nums.end() - k, nums.end(), nums.begin());
            nums.resize(k);
        }
    }
    
    int add(int val) {
        if(nums.size() < k || nums.front() < val){
            nums.resize(nums.size() + 1); 
            int pos = upper_bound(nums.begin(), prev(nums.end()), val) - nums.begin();
            copy_backward(nums.begin() + pos, prev(nums.end()), nums.end());
            nums[pos] = val;
            copy(nums.end() - k, nums.end(), nums.begin());
            nums.resize(k);
        }
        return nums.front();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */