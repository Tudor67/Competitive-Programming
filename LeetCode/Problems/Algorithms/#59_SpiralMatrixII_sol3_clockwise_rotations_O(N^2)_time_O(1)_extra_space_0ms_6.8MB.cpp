class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n, 0));
        
        int y = 0;
        int x = 0;
        int dy = 0;
        int dx = 1;
        for(int val = 1; val <= n * n; ++val){
            a[y][x] = val;
            if(y + dy < 0 || n <= y + dy || x + dx < 0 || n <= x + dx || a[y + dy][x + dx] != 0){
                // clockwise rotation (90 degrees)
                swap(dy, dx);
                dx *= -1;
            }
            y += dy;
            x += dx;
        }
        
        return a;
    }
};