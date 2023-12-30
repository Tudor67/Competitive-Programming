class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        map<int, int> f;
        
        int l = 0;
        for(int r = 0; r < N; ++r){
            f[nums[r]] += 1;
            while(f.rbegin()->first - f.begin()->first > 2){
                f[nums[l]] -= 1;
                if(f[nums[l]] == 0){
                    f.erase(nums[l]);
                }
                l += 1;
            }
            res += (r - l + 1);
        }
        
        return res;
    }
};