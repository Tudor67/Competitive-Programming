class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        const int N = nums.size();

        vector<int> prefScore(N);
        prefScore[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefScore[i] = prefScore[i - 1] & nums[i];
        }

        int res = 1;
        int score = nums[N - 1];
        for(int i = N - 1; i >= 1; --i){
            score = score & nums[i];
            if(prefScore[i - 1] == 0 && score == 0){
                res += 1;
                score = nums[i - 1];
            }
        }

        return res;
    }
};