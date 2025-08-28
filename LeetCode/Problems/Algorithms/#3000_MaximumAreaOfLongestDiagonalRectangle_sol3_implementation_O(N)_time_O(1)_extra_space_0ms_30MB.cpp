class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int resSqrDiag = 0;
        int resArea = 0;
        for(const vector<int>& DIM: dimensions){
            int h = DIM[0];
            int w = DIM[1];
            int sqrDiag = h * h + w * w;
            int area = h * w;
            if((sqrDiag > resSqrDiag) || (sqrDiag == resSqrDiag && area > resArea)){
                resSqrDiag = sqrDiag;
                resArea = area;
            }
        }
        return resArea;
    }
};