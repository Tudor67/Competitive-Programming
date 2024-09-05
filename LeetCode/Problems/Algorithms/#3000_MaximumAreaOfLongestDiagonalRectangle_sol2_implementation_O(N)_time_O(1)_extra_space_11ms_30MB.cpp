class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int resSqrDiag = 0;
        int resArea = 0;

        for(const vector<int>& DIMENSION: dimensions){
            int h = DIMENSION[0];
            int w = DIMENSION[1];
            int sqrDiag = h * h + w * w;
            int area = h * w;
            
            if((resSqrDiag < sqrDiag) ||
               (resSqrDiag == sqrDiag && resArea < area)){
                resSqrDiag = sqrDiag;
                resArea = area;
            }
        }

        return resArea;
    }
};