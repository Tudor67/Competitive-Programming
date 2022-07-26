class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int N = nums1.size();
        
        vector<int> diffs(N);
        for(int i = 0; i < N; ++i){
            diffs[i] = abs(nums1[i] - nums2[i]);
        }
        
        const int MAX_DIFF = *max_element(diffs.begin(), diffs.end());
        vector<int> count(MAX_DIFF + 1);
        for(int diff: diffs){
            count[diff] += 1;
        }
        
        int k = k1 + k2;
        for(int diff = MAX_DIFF; diff >= 1 && k > 0; --diff){
            int take = min(count[diff], k);
            k -= take;
            count[diff] -= take;
            count[diff - 1] += take;
        }
        
        long long res = 0;
        for(int diff = MAX_DIFF; diff >= 0; --diff){
            res += (count[diff] * 1LL * diff * 1LL * diff);
        }
        
        return res;
    }
};