class Solution {
private:
    int countNegativeNumbers(vector<int>& v, const int& N){
        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(v[mid] < 0){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return N - r;
    }
    
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int answer = 0;
        for(int row = 0; row < ROWS; ++row){
            answer += countNegativeNumbers(grid[row], COLS);
        }
        
        return answer;
    }
};