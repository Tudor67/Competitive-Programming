class NumArray {
private:
    const int N;
    const int SQRT_N;
    vector<int> nums;
    vector<int> blockSum;
    
public:
    NumArray(vector<int>& nums): N(nums.size()), SQRT_N(sqrt(N)) {
        this->nums = nums;
        this->blockSum.resize((N + SQRT_N - 1) / SQRT_N, 0);
        for(int i = 0; i <= N - 1; ++i){
            this->blockSum[i / SQRT_N] += this->nums[i];
        }
    }
    
    void update(int index, int val) {
        blockSum[index / SQRT_N] += val - nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int startBlock = left / SQRT_N;
        int endBlock = right / SQRT_N;
        int sum = 0;
        if(startBlock == endBlock){
            for(int k = left; k <= right; ++k){
                sum += nums[k];
            }
        }else{
            for(int k = left; k <= (startBlock + 1) * SQRT_N - 1; ++k){
                sum += nums[k];
            }
            for(int k = startBlock + 1; k <= endBlock - 1; ++k){
                sum += blockSum[k];
            }
            for(int k = endBlock * SQRT_N; k <= right; ++k){
                sum += nums[k];
            }
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