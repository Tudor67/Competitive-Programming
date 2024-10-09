class Solution {
private:
    bool isPrime(int num){
        if(num <= 1){
            return false;
        }
        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
    
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          {0, -1}, {0, 1},
                                                          {1, -1}, {1, 0}, {1, 1}};
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        unordered_map<int, int> freq;
        for(int startRow = 0; startRow < ROWS; ++startRow){
            for(int startCol = 0; startCol < COLS; ++startCol){
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int num = 0;
                    for(int row = startRow, col = startCol; 0 <= row && row < ROWS && 0 <= col && col < COLS;
                        row += DIRECTION.first, col += DIRECTION.second){
                        num = num * 10 + mat[row][col];
                        if(num > 10 && isPrime(num)){
                            freq[num] += 1;
                        }
                    }
                }
            }
        }
        
        int res = -1;
        for(const pair<const int, int>& P: freq){
            int num = P.first;
            if((res == -1) ||
               (freq[res] < freq[num]) ||
               (freq[res] == freq[num] && res < num)){
                res = num;
            }
        }
        
        return res;
    }
};