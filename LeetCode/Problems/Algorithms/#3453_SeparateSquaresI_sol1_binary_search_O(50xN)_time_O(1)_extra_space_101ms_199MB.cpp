class Solution {
private:
    double computeAreaDiff(vector<vector<int>>& squares, double yThreshold){
        double areaDiff = 0;
        for(vector<int>& square: squares){
            double y1 = square[1];
            double len = square[2];
            double y2 = y1 + len;
            if(yThreshold <= y1){
                areaDiff += len * len;
            }else if(y2 <= yThreshold){
                areaDiff -= len * len;
            }else{
                double dy2 = y2 - yThreshold;
                areaDiff += dy2 * len;
                double dy1 = yThreshold - y1;
                areaDiff -= dy1 * len;
            }
        }
        return areaDiff;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        double l = 0;
        double r = 2e9 + 5;
        while(abs(r - l) > 1e-6){
            double mid = (l + r) / 2;
            if(computeAreaDiff(squares, mid) > 0){
                l = mid;
            }else{
                r = mid;
            }
        }
        return r;
    }
};