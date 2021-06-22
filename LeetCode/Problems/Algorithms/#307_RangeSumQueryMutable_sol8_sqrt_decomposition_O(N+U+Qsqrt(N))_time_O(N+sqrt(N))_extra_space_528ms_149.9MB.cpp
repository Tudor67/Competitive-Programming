class NumArray {
private:
    const int N;
    const int BLOCK_SIZE;
    const int MAX_BLOCK;
    vector<int> nums;
    vector<int> blockSum;
    
public:
    NumArray(vector<int>& nums): N(nums.size()), BLOCK_SIZE(sqrt(N)), MAX_BLOCK((N - 1) / BLOCK_SIZE) {
        this->nums = nums;
        this->blockSum.resize(MAX_BLOCK + 1, 0);
        for(int i = 0; i < N; ++i){
            blockSum[i / BLOCK_SIZE] += nums[i];
        }
    }
    
    void update(int index, int val) {
        blockSum[index / BLOCK_SIZE] -= nums[index];
        nums[index] = val;
        blockSum[index / BLOCK_SIZE] += nums[index];
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        while(left <= right && left % BLOCK_SIZE != 0){
            sum += nums[left];
            left += 1;
        }
        while(left + BLOCK_SIZE - 1 <= right){
            sum += blockSum[left / BLOCK_SIZE];
            left += BLOCK_SIZE;
        }
        while(left <= right){
            sum += nums[right];
            right -= 1;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */