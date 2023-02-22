class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        vector<bool> vis(N + 1, false);
        vector<int> diff(N + 1);

        for(int j = 0; j < N; ++j){
            int suffCountGreater = 0;
            for(int l = N - 1; l > j; --l){
                if(nums[j] < nums[l]){
                    suffCountGreater += 1;
                }else{
                    diff[nums[l] - 1] += suffCountGreater;
                }
            }

            int ikPairs = 0;
            for(int num = nums[j] - 1; num >= 0; --num){
                ikPairs += diff[num];
                if(vis[num]){
                    res += ikPairs;
                }
                diff[num] = 0;
            }

            vis[nums[j]] = true;
        }
        
        return res;
    }
};