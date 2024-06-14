class Solution {
public:
    int heightChecker(vector<int>& heights) {
        const int N = heights.size();

        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());

        int badIndices = 0;
        for(int i = 0; i < N; ++i){
            badIndices += (int)(sortedHeights[i] != heights[i]);
        }

        return badIndices;
    }
};