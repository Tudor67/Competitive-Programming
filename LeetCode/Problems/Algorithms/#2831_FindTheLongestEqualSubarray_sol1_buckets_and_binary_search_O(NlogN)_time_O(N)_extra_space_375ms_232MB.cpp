class Solution {
private:
    int computeMaxLenOfEqualSubarray(const vector<int>& SORTED_INDICES, const int K){
        int maxLen = 0;
        for(int i = 0; i < (int)SORTED_INDICES.size(); ++i){
            int l = i;
            int r = (int)SORTED_INDICES.size() - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                int equalElements = mid - i + 1;
                int totalElements = SORTED_INDICES[mid] - SORTED_INDICES[i] + 1;
                if(totalElements - equalElements <= K){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            maxLen = max(maxLen, r - i + 1);
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