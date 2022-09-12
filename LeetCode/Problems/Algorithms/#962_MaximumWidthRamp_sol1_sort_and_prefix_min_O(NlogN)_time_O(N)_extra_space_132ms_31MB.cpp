class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int N = nums.size();
        
        vector<pair<int, int>> sortedNumsAndIds(N);
        for(int i = 0; i < N; ++i){
            sortedNumsAndIds[i] = {nums[i], i};
        }
        
        sort(sortedNumsAndIds.begin(), sortedNumsAndIds.end());
        
        int maxRampWidth = 0;
        int minIdx = sortedNumsAndIds[0].second;
        for(int i = 0; i < N; ++i){
            int idx = sortedNumsAndIds[i].second;
            minIdx = min(minIdx, idx);
            int rampWidth = idx - minIdx;
            maxRampWidth = max(maxRampWidth, rampWidth);
        }
        
        return maxRampWidth;
    }
};