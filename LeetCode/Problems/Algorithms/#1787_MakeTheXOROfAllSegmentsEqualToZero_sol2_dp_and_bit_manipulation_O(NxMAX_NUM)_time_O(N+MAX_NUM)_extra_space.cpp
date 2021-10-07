class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = max(1, *max_element(nums.begin(), nums.end()));
        const int MAX_BIT = (int)floor(log2(MAX_NUM));
        const int FULL_MASK = (1 << (MAX_BIT + 1)) - 1;
        
        // buckets[i] (with 0 <= i <= k - 1) is a counter for {nums[i], nums[i + k], nums[i + 2 * k], ..., nums[i + c * k]}
        vector<unordered_map<int, int>> buckets(k);
        for(int i = 0; i < N; ++i){
            buckets[i % k][nums[i]] += 1;
        }
        
        // At step i:
        //    maxKept[i][mask]: max number of elements from buckets[0 .. i] that we can keep
        //                      such that the xor of i elements will be equal to mask;
        vector<vector<int>> maxKept(2, vector<int>(FULL_MASK + 1));
        for(auto [mask, maskFreq]: buckets[0]){
            maxKept[0][mask] = maskFreq;
        }
        
        for(int i = 1; i < k; ++i){
            int prevMaxKept = *max_element(maxKept[(i - 1) % 2].begin(), maxKept[(i - 1) % 2].end());
            fill(maxKept[i % 2].begin(), maxKept[i % 2].end(), prevMaxKept);
            for(int mask1 = 0; mask1 <= FULL_MASK; ++mask1){
                for(auto [mask2, mask2Freq]: buckets[i]){
                    maxKept[i % 2][mask1 ^ mask2] = max(maxKept[i % 2][mask1 ^ mask2], maxKept[(i - 1) % 2][mask1] + mask2Freq);
                }
            }
        }
        
        return N - maxKept[(k - 1) % 2][0];
    }
};