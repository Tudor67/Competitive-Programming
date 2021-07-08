class Solution {
private:
    int countElementsLessOrEqualThan(vector<vector<int>>& matrix, const int& VAL){
        const int N = matrix.size();
        int count = 0;
        for(int row = 0; row < N; ++row){
            count += upper_bound(matrix[row].begin(), matrix[row].end(), VAL) - matrix[row].begin();
        }
        return count;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int N = matrix.size();
        int l = matrix[0][0] - 1;
        int r = matrix[N - 1][N - 1] - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(countElementsLessOrEqualThan(matrix, mid) >= k){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        return r + 1;
    }
};

/*
  Binary search the maximum value VAL such that countElementsLessOrEqualThan(matrix, VAL) <= k - 1;
  The answer is VAL + 1;
  
  Binary search in range [MIN_ELEM - 1, MAX_ELEM - 1] (i.e., range [matrix[0][0] - 1, matrix[N - 1][N - 1] - 1]);
  
  Time complexity: O(N * log(N) * log(MAX_ELEM - MIN_ELEM))
  Extra-space complexity: O(1)
*/