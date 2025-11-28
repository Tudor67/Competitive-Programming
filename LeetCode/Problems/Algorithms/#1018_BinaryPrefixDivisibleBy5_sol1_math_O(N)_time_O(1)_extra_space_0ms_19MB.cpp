class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        const int N = nums.size();

        vector<bool> res(N);
        int prefRem = 0;
        
        for(int i = 0; i < N; ++i){
            prefRem = (prefRem * 2 + nums[i]) % 5;
            res[i] = (prefRem == 0);
        }

        return res;
    }
};