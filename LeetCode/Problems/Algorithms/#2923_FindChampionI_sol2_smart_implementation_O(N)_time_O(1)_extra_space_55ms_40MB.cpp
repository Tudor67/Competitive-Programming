class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        const int N = grid.size();

        int champion = 0;
        for(int i = 1; i < N; ++i){
            if(grid[i][champion] == 1){
                champion = i;
            }
        }

        return champion;
    }
};