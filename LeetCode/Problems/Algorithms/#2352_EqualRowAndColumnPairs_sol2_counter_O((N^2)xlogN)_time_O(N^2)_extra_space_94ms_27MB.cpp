class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const int N = grid.size();

        map<vector<int>, int> count;
        for(int col = 0; col < N; ++col){
            vector<int> colValues(N);
            for(int i = 0; i < N; ++i){
                colValues[i] = grid[i][col];
            }
            count[colValues] += 1;
        }

        int res = 0;
        for(int row = 0; row < N; ++row){
            if(count.count(grid[row])){
                res += count[grid[row]];
            }
        }

        return res;
    }
};