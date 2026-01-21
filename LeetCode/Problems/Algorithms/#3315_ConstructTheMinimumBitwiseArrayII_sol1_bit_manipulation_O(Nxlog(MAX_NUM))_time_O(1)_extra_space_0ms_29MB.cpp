class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> ans(N);
        for(int i = 0; i < N; ++i){
            int bit = 0;
            while((nums[i] >> bit) & 1){
                bit += 1;
            }

            if(bit >= 1){
                ans[i] = nums[i] - (1 << (bit - 1));
            }else{
                ans[i] = -1;
            }
        }

        return ans;
    }
};