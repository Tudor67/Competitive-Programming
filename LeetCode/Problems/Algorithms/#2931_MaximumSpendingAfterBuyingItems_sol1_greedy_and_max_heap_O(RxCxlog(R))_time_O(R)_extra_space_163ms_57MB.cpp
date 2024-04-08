class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        const int ROWS = values.size();
        const int COLS = values[0].size();

        priority_queue<tuple<int, int, int>> maxHeap;
        for(int row = 0; row < ROWS; ++row){
            maxHeap.push({values[row][0], row, 0});
        }

        long long res = 0;
        for(long long d = ROWS * COLS; d >= 1; --d){
            int row = get<1>(maxHeap.top());
            int col = get<2>(maxHeap.top());
            maxHeap.pop();

            res += d * values[row][col];

            if(col + 1 < COLS){
                maxHeap.push({values[row][col + 1], row, col + 1});
            }
        }

        return res;
    }
};