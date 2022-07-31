class NumArray {
private:
    const int N;
    const int BLOCK_SIZE;
    const int BLOCKS;
    vector<int> nums;
    vector<int> blocksSum;
    
    int getBlockIndex(int index){
        return index / BLOCK_SIZE;
    }
    
    bool isBlockStart(int index){
        return (index % BLOCK_SIZE == 0);
    }
    
public:
    NumArray(vector<int>& nums): N(nums.size()), BLOCK_SIZE(sqrt(N)), BLOCKS((N + BLOCK_SIZE - 1) / BLOCK_SIZE){
        this->nums = nums;
        this->blocksSum.resize(BLOCKS);
        for(int i = 0; i < N; ++i){
            this->blocksSum[getBlockIndex(i)] += this->nums[i];
        }
    }
    
    void update(int index, int val) {
        blocksSum[getBlockIndex(index)] -= nums[index];
        nums[index] = val;
        blocksSum[getBlockIndex(index)] += val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        while(left <= right && !isBlockStart(left)){
            sum += nums[left];
            left += 1;
        }
        while(left + BLOCK_SIZE - 1 <= right){
            sum += blocksSum[getBlockIndex(left)];
            left += BLOCK_SIZE;
        }
        while(left <= right){
            sum += nums[left];
            left += 1;
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