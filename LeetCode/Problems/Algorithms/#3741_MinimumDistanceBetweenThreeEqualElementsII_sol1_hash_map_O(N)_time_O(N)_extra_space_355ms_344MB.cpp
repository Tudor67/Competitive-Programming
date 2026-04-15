class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int N = nums.size();
        const int INF = INT_MAX;

        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }

        int minDist = INF;
        for(const auto& [num, indices]: numToIndices){
            for(int i = 2; i < (int)indices.size(); ++i){
                int currDist = 2 * (indices[i] - indices[i - 2]);
                minDist = min(minDist, currDist);
            }
        }

        if(minDist != INF){
            return minDist;
        }

        return -1;
    }
};