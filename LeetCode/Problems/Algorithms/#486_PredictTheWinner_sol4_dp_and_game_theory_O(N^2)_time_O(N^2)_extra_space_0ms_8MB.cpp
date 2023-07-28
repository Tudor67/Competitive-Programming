class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int N = nums.size();

        // maxDiff[len][i]: max difference between the current player and his opponent for nums[i .. i + len - 1]
        //                  when both players play optimally
        vector<vector<int>> maxDiff(N + 1, vector<int>(N));
        for(int len = 1; len <= N; ++len){
            for(int i = 0; i + len - 1 < N; ++i){
                if(len == 1){
                    maxDiff[len][i] = nums[i];
                }else{
                    maxDiff[len][i] = max(nums[i] - maxDiff[len - 1][i + 1],
                                          nums[i + len - 1] - maxDiff[len - 1][i]);
                }
            }
        }

        return (maxDiff[N][0] >= 0);
    }
};