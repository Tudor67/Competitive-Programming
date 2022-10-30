class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        long long prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            res = max(res, (prefSum + i) / (i + 1));
        }
        
        return res;
    }
};