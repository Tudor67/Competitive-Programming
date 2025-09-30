class Solution {
public:
    int triangularSum(vector<int>& nums) {
        const int N = nums.size();

        vector<int> currNums = nums;
        vector<int> nextNums(N);
        for(int step = 1; step <= N - 1; ++step){
            for(int i = 0; i < N - step; ++i){
                nextNums[i] = (currNums[i] + currNums[i + 1]) % 10;
            }
            currNums = nextNums;
        }

        return currNums[0];
    }
};