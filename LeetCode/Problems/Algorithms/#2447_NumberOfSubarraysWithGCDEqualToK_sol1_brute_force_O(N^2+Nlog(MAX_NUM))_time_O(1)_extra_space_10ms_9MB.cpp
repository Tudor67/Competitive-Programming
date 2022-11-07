class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            int g = nums[i];
            for(int j = i; j < N; ++j){
                g = gcd(g, nums[j]);
                if(g == k){
                    res += 1;
                }
                if(g < k){
                    break;
                }
            }
        }
        
        return res;
    }
};