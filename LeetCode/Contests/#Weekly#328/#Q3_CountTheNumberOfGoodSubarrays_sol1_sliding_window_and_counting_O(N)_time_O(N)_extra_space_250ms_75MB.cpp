class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        const int N = nums.size();
        
        long long res = 0;
        long long pairs = 0;
        unordered_map<int, int> count;
        
        int l = 0;
        for(int r = 0; r < N; ++r){
            count[nums[r]] += 1;
            pairs += (count[nums[r]] - 1);
            
            while(pairs - (count[nums[l]] - 1) >= k){
                pairs -= (count[nums[l]] - 1);
                count[nums[l]] -= 1;
                l += 1;
            }
            
            if(pairs >= k){
                res += (l + 1);
            }
        }
        
        return res;
    }
};