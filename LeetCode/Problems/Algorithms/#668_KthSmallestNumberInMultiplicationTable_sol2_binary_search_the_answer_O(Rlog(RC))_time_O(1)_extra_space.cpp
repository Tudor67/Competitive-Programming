class Solution {
private:
    int countLessOrEqual(const int& ROWS, const int& COLS, const int& MAX_PROD){
        int count = 0;
        for(int row = 1; row <= ROWS; ++row){
            count += min(COLS, MAX_PROD / row);
        }
        return count;
    }
    
public:
    int findKthNumber(int ROWS, int COLS, int K) {
        int l = 1;
        int r = ROWS * COLS;
        while(l != r){
            int mid = (l + r) / 2;
            if(countLessOrEqual(ROWS, COLS, mid) < K){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};