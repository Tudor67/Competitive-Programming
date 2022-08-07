class Solution {
private:
    int countValuesLessThanOrEqualTo(vector<vector<int>>& matrix, const int& THRESHOLD){
        const int N = matrix.size();
        
        int count = 0;
        int col = N - 1;
        for(int row = 0; row < N && col >= 0; ++row){
            while(col >= 0 && THRESHOLD < matrix[row][col]){
                col -= 1;
            }
            count += (col + 1);
        }
        
        return count;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int K) {
        const int N = matrix.size();
        const int MIN_VAL = matrix[0][0];
        const int MAX_VAL = matrix[N - 1][N - 1];
        
        // binary search min value x such that countValuesLessThanOrEqualTo(matrix, x) >= K
        int l = MIN_VAL;
        int r = MAX_VAL;
        while(l != r){
            int mid = (l + r) / 2;
            if(2 * mid > l + r){
                // avoid c++ rounding towards zero problem (when working with negative values)
                mid -= 1;
            }
            if(countValuesLessThanOrEqualTo(matrix, mid) >= K){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};