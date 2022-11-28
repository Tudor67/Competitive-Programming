class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        // dp2[i][d]: number of all arithmetic subsequences of length == 2
        //            with members difference d and with the last element nums[i]
        // dp3[i][d]: number of all arithmetic subsequences of length >= 3
        //            with members difference d and with the last element nums[i]
        long long res = 0;
        unordered_map<long long, long long> dp2[N];
        unordered_map<long long, long long> dp3[N];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long d = (long long)nums[i] - (long long)nums[j];
                dp2[i][d] += 1;
                if(dp2[j].count(d)){
                    dp3[i][d] += dp2[j][d];
                }
                if(dp3[j].count(d)){
                    dp3[i][d] += dp3[j][d];
                }
            }
            for(const pair<long long, long long>& P: dp3[i]){
                res += P.second;
            }
        }
        
        return res;
    }
};