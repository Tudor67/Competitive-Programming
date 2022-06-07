class Solution {
private:
    void back(int level, int n, int visMaskCols, int visMaskMainDiags, int visMaskSecDiags, int& res){
        if(level == n){
            res += 1;
        }else{
            int row = level;
            for(int col = 0; col < n; ++col){
                int mainDiagIdx = row - col + n;
                int secDiagIdx = row + col;
                if(!((visMaskCols >> col) & 1) && !((visMaskMainDiags >> mainDiagIdx) & 1) && !((visMaskSecDiags >> secDiagIdx) & 1)){
                    back(level + 1, n, visMaskCols | (1 << col), visMaskMainDiags | (1 << mainDiagIdx), visMaskSecDiags | (1 << secDiagIdx), res);
                }
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        int res = 0;
        back(0, n, 0, 0, 0, res);
        return res;
    }
};