class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> resDiagArea = {0, 0};
        for(const vector<int>& DIM: dimensions){
            int h = DIM[0];
            int w = DIM[1];
            resDiagArea = max(resDiagArea, pair<int, int>{h * h + w * w, h * w});
        }
        return resDiagArea.second;
    }
};