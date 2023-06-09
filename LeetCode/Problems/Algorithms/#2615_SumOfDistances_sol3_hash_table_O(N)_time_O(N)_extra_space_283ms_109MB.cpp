class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        const long long N = nums.size();
        
        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }
        
        vector<long long> res(N);
        for(const pair<int, vector<int>>& P: numToIndices){
            const vector<int>& INDICES = P.second;

            long long totalSize = INDICES.size();
            res[INDICES[0]] = accumulate(INDICES.begin(), INDICES.end(), 0LL) - INDICES[0] * totalSize;
            for(long long j = 1; j < totalSize; ++j){
                res[INDICES[j]] = res[INDICES[j - 1]] + (INDICES[j] - INDICES[j - 1]) * (j - (totalSize - j));
            }
        }
        
        return res;
    }
};