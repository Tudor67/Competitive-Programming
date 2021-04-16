class Solution {
private:
    int countNumsLessOrEqualThan(const int& VAL, const int& ROWS, const int& COLS){
        int cnt = 0;
        for(int row = 1; row <= ROWS; ++row){
            int curCnt = min(VAL / row, COLS);
            if(curCnt > 0){
                cnt += curCnt;
            }else{
                break;
            }
        }
        return cnt;
    }
    
public:
    int findKthNumber(int rows, int cols, int k) {
        int l = 1;
        int r = rows * cols;
        while(l != r){
            int mid = (l + r) / 2;
            if(k <= countNumsLessOrEqualThan(mid, rows, cols)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};