class Solution {
public:
    double champagneTower(int poured, int queryRow, int queryGlass) {
        queryRow += 1;
        queryGlass += 1;
        
        const int N = queryRow * (queryRow + 1) / 2;
        vector<double> quantity(N + 1);
        quantity[1] = poured;
        for(int row = 1; row <= queryRow; ++row){
            for(int col = 1; col <= row; ++col){
                int idx = row * (row - 1) / 2 + col;
                double excess = 0;
                if(quantity[idx] > 1){
                    excess = quantity[idx] - 1;
                    quantity[idx] = 1;
                }
                if(idx + row + 1 <= N){
                    quantity[idx + row] += excess / 2;
                    quantity[idx + row + 1] += excess / 2;
                }
            }
        }
        
        return quantity[N - queryRow + queryGlass];
    }
};