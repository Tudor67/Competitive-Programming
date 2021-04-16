class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        int answer = INT_MIN;
        vector<int> prefSum(ROWS);
        set<int> prefSumSet;
        for(int col1 = 0; col1 < COLS; ++col1){
            fill(prefSum.begin(), prefSum.end(), 0);
            for(int col2 = col1; col2 < COLS; ++col2){
                for(int row = 0; row < ROWS; ++row){
                    // prefSum[row] = matrix[row][col1] + matrix[row][col1 + 1] + ... + matrix[row][col2]
                    prefSum[row] += matrix[row][col2];
                }
                prefSumSet.clear();
                prefSumSet.insert(0);
                int rectanglePrefSum = 0;
                for(int row = 0; row < ROWS; ++row){
                    // rectanglePrefSum = sum of rectangle with top-left corner (0, col1) and bottom-right corner (row, col2)
                    rectanglePrefSum += prefSum[row];
                    auto it = prefSumSet.lower_bound(rectanglePrefSum - k);
                    if(it != prefSumSet.end()){
                        answer = max(rectanglePrefSum - *it, answer);
                    }
                    prefSumSet.insert(rectanglePrefSum);
                }
            }
        }
        return answer;
    }
};