class Solution {
public:
    int minOperations(vector<int>& inNums) {
        const int N = inNums.size();

        int minOps = 0;

        vector<int> nums = inNums;
        for(int i = 0; i + 2 < N; ++i){
            if(nums[i] == 0){
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                minOps += 1;
            }
        }

        if(nums[N - 2] == 1 && nums[N - 1] == 1){
            return minOps;
        }

        return -1;
    }
};