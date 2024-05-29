class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i] % k, nums[i]};
        }
        
        sort(v.begin(), v.end());

        vector<int> dp(N);
        int j = 0;
        int dpPrefSum = 0;
        for(int i = 0; i < N; ++i){
            while(j < i && (v[j].first != v[i].first || v[j].second + k < v[i].second)){
                dpPrefSum += dp[j];
                j += 1;
            }
            
            if(i > 0 && v[i - 1].second == v[i].second){
                dp[i] = 2 * dp[i - 1];
            }else{
                dp[i] = dpPrefSum + 1;
            }
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};