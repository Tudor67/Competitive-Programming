class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        const int N = nums.size();
        
        vector<long long> res(N);
        int prefMax = nums[0];
        for(int i = 0; i < N; ++i){
            prefMax = max(prefMax, nums[i]);
            res[i] = nums[i] + prefMax;
            if(i >= 1){
                res[i] += res[i - 1];
            }
        }
        
        return res;
    }
};