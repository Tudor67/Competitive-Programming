class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        const int N = nums.size();

        vector<pair<int, int>> sortedRanges(N);
        for(int i = 0; i < N; ++i){
            sortedRanges[i] = {nums[i][0], nums[i][1]};
        }

        sort(sortedRanges.begin(), sortedRanges.end());

        int res = 0;
        int maxTakenPoint = -1;
        for(const pair<int, int>& RANGE: sortedRanges){
            int a = RANGE.first;
            int b = RANGE.second;
            if(maxTakenPoint < a){
                res += (b - a + 1);
            }else if(maxTakenPoint < b){
                res += (b - maxTakenPoint);
            }
            maxTakenPoint = max(maxTakenPoint, b);
        }

        return res;
    }
};