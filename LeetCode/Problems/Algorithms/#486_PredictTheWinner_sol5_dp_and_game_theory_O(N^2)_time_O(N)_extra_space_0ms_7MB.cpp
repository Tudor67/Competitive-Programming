class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int N = nums.size();

        // At (len)th iteration:
        //    maxDiff[len % 2][i]: max difference between the current player and his opponent for nums[i .. i + len - 1]
        //                         when both players play optimally
        vector<vector<int>> maxDiff(2, vector<int>(N));
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                if(len == 1){
                    maxDiff[len % 2][i] = nums[i];
                }else{
                    maxDiff[len % 2][i] = max(nums[i] - maxDiff[(len - 1) % 2][i + 1],
                                              nums[i + len - 1] - maxDiff[(len - 1) % 2][i]);
                }
            }
        }

        return (maxDiff[N % 2][0] >= 0);
    }
};