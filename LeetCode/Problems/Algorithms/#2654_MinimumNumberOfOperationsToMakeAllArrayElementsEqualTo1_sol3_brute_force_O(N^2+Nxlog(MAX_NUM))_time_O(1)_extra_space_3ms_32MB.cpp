class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int ONES = count(nums.begin(), nums.end(), 1);
        const int INF = 1e9;

        if(ONES >= 1){
            return N - ONES;
        }

        int res = INF;
        for(int i = 0; i < N; ++i){
            int g = nums[i];
            for(int j = i; j < N; ++j){
                g = gcd(g, nums[j]);
                if(g == 1){
                    int ops = j - i + N - 1;
                    res = min(res, ops);
                    break;
                }
            }
        }

        if(res == INF){
            res = -1;
        }

        return res;
    }
};