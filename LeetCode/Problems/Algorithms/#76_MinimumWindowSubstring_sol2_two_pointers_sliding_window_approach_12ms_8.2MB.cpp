class Solution {
public:
    string minWindow(string s, string t) {
        // count chars of string t
        vector<int> t_cnt(256, 0);
        for(char c: t){
            t_cnt[c] += 1;
        }
        
        // count unique chars of string t
        int t_unique_chars = 0;
        for(int c = 0; c < t_cnt.size(); ++c){
            t_unique_chars += (t_cnt[c] > 0);
        }
        
        // sliding window approach
        vector<int> w_cnt(256, 0);
        int matches = 0;
        int best_l = -1;
        int best_r = -1;
        for(int l = 0, r = 0; r < s.length(); ++r){
            w_cnt[s[r]] += 1;
            matches += (w_cnt[s[r]] == t_cnt[s[r]]);
            
            // update answer
            if(matches == t_unique_chars){
                for(; l < r && w_cnt[s[l]] - 1 >= t_cnt[s[l]]; ++l){
                    w_cnt[s[l]] -= 1;
                }
                if(best_l == -1 || r - l < best_r - best_l){
                    best_l = l;
                    best_r = r;
                }
            }
        }
        
        string answer;
        if(best_l != -1){
            answer = s.substr(best_l, best_r - best_l + 1);
        }
        
        return answer;
    }
};