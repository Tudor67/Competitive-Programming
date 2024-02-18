class Solution {
private:
    int computeMaxLenOfEqualSubarray(const vector<int>& SORTED_INDICES, const int K){
        int maxLen = 0;
        int l = 0;
        for(int r = 0; r < (int)SORTED_INDICES.size(); ++r){
            while((SORTED_INDICES[r] - SORTED_INDICES[l] + 1) - (r - l + 1) > K){
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }

public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }
        
        int res = 0;
        for(const pair<const int, vector<int>>& P: numToIndices){
            const vector<int>& SORTED_INDICES = P.second;
            res = max(res, computeMaxLenOfEqualSubarray(SORTED_INDICES, k));
        }
        
        return res;
    }
};