class NumArray {
private:
    vector<int> prefixSum;
    
public:
    NumArray(vector<int>& nums) {
        const int N = nums.size();
        prefixSum.resize(N);
        prefixSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left >= 1){
            return prefixSum[right] - prefixSum[left - 1];
        }
        return prefixSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */