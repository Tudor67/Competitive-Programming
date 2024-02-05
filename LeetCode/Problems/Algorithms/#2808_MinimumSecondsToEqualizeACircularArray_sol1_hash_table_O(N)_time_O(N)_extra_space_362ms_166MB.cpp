class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, vector<int>> numToPositions;
        for(int i = 0; i < N; ++i){
            numToPositions[nums[i]].push_back(i);
        }

        int res = N;
        for(pair<const int, vector<int>>& P: numToPositions){
            vector<int>& positions = P.second;
            positions.push_back(positions.front() + N);

            int cost = 0;
            for(int i = 0; i + 1 < (int)positions.size(); ++i){
                int d = positions[i + 1] - positions[i] - 1;
                cost = max(cost, (d + 1) / 2);
            }

            res = min(res, cost);
        }

        return res;
    }
};