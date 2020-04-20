class Solution {
    int comb(int n, int k){
        vector<int> fact(n + 1);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i){
            fact[i] = i * fact[i - 1];
        }
        return fact[n] / (fact[n - k] * fact[k]);
    }
    
public:
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26, 0);
        for(char c: tiles){
            ++cnt[c - 'A'];
        }
        
        int n = tiles.length();
        vector<vector<int>> ans(2, vector<int>(n + 1, 0));
        ans[0][0] = 1;
        ans[1][0] = 1;
        
        int prev_step = 0;
        int cur_step = 1;
        for(int letter_cnt: cnt){
            if(letter_cnt > 0){
                ans[cur_step] = ans[prev_step];
                for(int i = 0; i + letter_cnt <= n; ++i){
                    for(int j = 1; j <= letter_cnt; ++j){
                        ans[cur_step][i + j] += ans[prev_step][i] * comb(i + j, j);
                    }
                }
                cur_step ^= 1;
                prev_step ^= 1;
            }
        }
        
        int sum = 0;
        for(int i = 1; i < ans[prev_step].size(); ++i){
            sum += ans[prev_step][i];
        }
        
        return sum;
    }
};