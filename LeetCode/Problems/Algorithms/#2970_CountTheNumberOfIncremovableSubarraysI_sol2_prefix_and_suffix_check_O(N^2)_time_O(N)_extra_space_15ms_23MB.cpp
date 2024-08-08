class Solution {
private:
    bool isIncremovable(vector<int>& nums, int l, int r,
                        vector<bool>& isIncPrefix, vector<bool>& isIncSuffix){
        const int N = nums.size();
        
        if(l - 1 >= 0 && !isIncPrefix[l - 1]){
            return false;
        }

        if(r + 1 < N && !isIncSuffix[r + 1]){
            return false;
        }

        if(l - 1 >= 0 && r + 1 < N && nums[l - 1] >= nums[r + 1]){
            return false;
        }

        return true;
    }

public:
    int incremovableSubarrayCount(vector<int>& nums) {
        const int N = nums.size();

        vector<bool> isIncPrefix(N);
        isIncPrefix[0] = true;
        for(int i = 1; i < N; ++i){
            isIncPrefix[i] = isIncPrefix[i - 1] && (nums[i - 1] < nums[i]);
        }

        vector<bool> isIncSuffix(N);
        isIncSuffix[N - 1] = true;
        for(int i = N - 2; i >= 0; --i){
            isIncSuffix[i] = (nums[i] < nums[i + 1]) && isIncSuffix[i + 1];
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i; j < N; ++j){
                if(isIncremovable(nums, i, j, isIncPrefix, isIncSuffix)){
                    res += 1;
                }
            }
        }

        return res;
    }
};