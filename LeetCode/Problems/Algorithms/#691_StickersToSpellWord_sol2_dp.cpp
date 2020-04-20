class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        vector<int> dp(1 << n, -1);
        
        // dp[state] - minimum numbers of stickers to spell out letters from the target
        //             that are located at positions j, where ((state & (1 << j)) != 0)
        dp[0] = 0;
        for(int cur_state = 0; cur_state < (1 << n); ++cur_state){
            if(dp[cur_state] != -1){
                for(const string& sticker: stickers){
                    int next_state = cur_state;
                    for(char sticker_letter: sticker){
                        for(int j = 0; j < target.size(); ++j){
                            if(sticker_letter == target[j] && (0 == (next_state & (1 << j)))){
                                next_state |= (1 << j);
                                break;
                            }
                        }
                    }
                    if(dp[next_state] == -1 || dp[cur_state] + 1 < dp[next_state]){
                        dp[next_state] = dp[cur_state] + 1;
                    }
                }   
            }
        }
        
        return dp[(1 << n) - 1];
    }
};