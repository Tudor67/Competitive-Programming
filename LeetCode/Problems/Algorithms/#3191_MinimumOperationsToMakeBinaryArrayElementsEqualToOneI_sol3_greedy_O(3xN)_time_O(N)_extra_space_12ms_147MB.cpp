class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        vector<int> currNums = nums;
        int minOps = 0;

        for(int i = 0; i + 2 < N; ++i){
            if(currNums[i] == 0){
                currNums[i] ^= 1;
                currNums[i + 1] ^= 1;
                currNums[i + 2] ^= 1;
                minOps += 1;
            }
        }

        if(currNums[N - 2] == 1 && currNums[N - 1] == 1){
            return minOps;
        }

        return -1;
    }
};