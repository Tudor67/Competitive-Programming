class Solution {
private:
    int countElementsLessOrEqualThan(vector<vector<int>>& matrix, const int& VAL){
        const int N = matrix.size();
        int count = 0;
        int row = N - 1;
        int col = 0;
        while(row >= 0 && col < N){
            if(matrix[row][col] <= VAL){
                count += (row + 1);
                col += 1;
            }else{
                row -= 1;
            }
        }
        return count;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int N = matrix.size();
        int l = matrix[0][0];
        int r = matrix[N - 1][N - 1];
        while(l != r){
            int mid = (l + r) / 2 - ((l + r) % 2 == -1);
            if(countElementsLessOrEqualThan(matrix, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};

/*
  Binary search the minimum value VAL such that k <= countElementsLessOrEqualThan(matrix, VAL);
  The answer is VAL;
  
  Binary search in range [MIN_ELEM, MAX_ELEM] (i.e., range [matrix[0][0], matrix[N - 1][N - 1]]);
  
  Time complexity: O(N * log(MAX_ELEM - MIN_ELEM))
  Extra-space complexity: O(1)
*/