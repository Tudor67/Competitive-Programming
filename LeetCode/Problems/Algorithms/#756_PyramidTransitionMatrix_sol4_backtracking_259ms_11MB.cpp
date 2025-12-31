class Solution {
private:
    bool check(int row, int col, vector<string>& grid, vector<vector<string>>& candidates){
        if(row < 0){
            return true;
        }

        if(row < col){
            return check(row - 1, 0, grid, candidates);
        }

        char a = grid[row + 1][col];
        char b = grid[row + 1][col + 1];
        for(char c: candidates[a - 'A'][b - 'A']){
            grid[row][col] = c;
            if(check(row, col + 1, grid, candidates)){
                return true;
            }
            grid[row][col] = '.';
        }

        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        const int N = bottom.length();
        const int A = allowed.size();

        vector<string> grid(N);
        for(int row = 0; row < N - 1; ++row){
            grid[row] = string(row + 1, '.');
        }
        grid[N - 1] = bottom;

        vector<vector<string>> candidates(6, vector<string>(6));
        for(string& s: allowed){
            candidates[s[0] - 'A'][s[1] - 'A'].push_back(s[2]);
        }

        return check(N - 2, 0, grid, candidates);
    }
};