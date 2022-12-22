class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int N = nums.size();

        // Step 1: sort and unique
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        const int U = v.size();

        // Step 2: DP
        // maxLen[i]: length of the longest square streak when the last element is v[i]
        vector<int> maxLen(U, 1);
        for(int i = 0; i < U; ++i){
            int j = lower_bound(v.begin(), v.end(), (long long)v[i] * (long long)v[i]) - v.begin();
            if(j < U && (long long)v[i] * (long long)v[i] == v[j]){
                maxLen[j] = maxLen[i] + 1;
            }
        }

        int res = *max_element(maxLen.begin(), maxLen.end());
        if(res < 2){
            res = -1;
        }

        return res;
    }
};