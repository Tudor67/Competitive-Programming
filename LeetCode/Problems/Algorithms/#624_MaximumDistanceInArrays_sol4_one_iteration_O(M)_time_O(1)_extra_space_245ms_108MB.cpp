class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int M = arrays.size();

        int maxDist = 0;
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        for(int i = 1; i < M; ++i){
            maxDist = max(maxDist, arrays[i].back() - minVal);
            maxDist = max(maxDist, maxVal - arrays[i].front());
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }

        return maxDist;
    }
};