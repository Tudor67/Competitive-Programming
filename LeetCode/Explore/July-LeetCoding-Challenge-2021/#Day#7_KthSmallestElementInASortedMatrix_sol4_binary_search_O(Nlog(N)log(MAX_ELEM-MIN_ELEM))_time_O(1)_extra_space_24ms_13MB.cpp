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
  
  Time complexity: O(N * log(N) * log(MAX_ELEM - MIN_ELEM))
  Extra-space complexity: O(1)
*/