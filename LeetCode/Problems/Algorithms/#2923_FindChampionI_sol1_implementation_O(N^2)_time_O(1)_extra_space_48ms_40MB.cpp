class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        const int N = grid.size();
        
        for(int i = 0; i < N; ++i){
            if(count(grid[i].begin(), grid[i].end(), 1) == N - 1){
                return i;
            }
        }
        
        return -1;
    }
};