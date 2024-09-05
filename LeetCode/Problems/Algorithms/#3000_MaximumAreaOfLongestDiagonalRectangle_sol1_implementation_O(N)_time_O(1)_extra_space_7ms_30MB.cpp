class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> res;
        for(const vector<int>& DIMENSION: dimensions){
            int h = DIMENSION[0];
            int w = DIMENSION[1];
            res = max(res, {h * h + w * w, h * w});
        }
        return res.second;
    }
};