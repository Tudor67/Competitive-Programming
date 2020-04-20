class Solution {
private:
    void back(int k, vector<int>& st, const string& s, vector<string>& answer, const vector<vector<int>>& dp){
        if(st[k] == 0){
            answer.push_back("");
            for(int i = k - 1; i >= 0; --i){
                for(int j = st[i + 1] + 1; j <= st[i]; ++j){
                    answer.back().push_back(s[j]);
                }
                if(i > 0){
                    answer.back() += " ";
                }
            }
        }else{
            for(int prev_pos: dp[st[k]]){
                st[k + 1] = prev_pos - 1;
                back(k + 1, st, s, answer, dp);
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {        
        s = "#" + s;
        const int n = (int)s.length() - 1;
        
        set<string> words;
        for(const string& word: wordDict){
            words.insert(word);
        }
        
        vector<vector<int>> dp(n + 1, vector<int>());
        dp[0].push_back(0);
        
        for(int start_pos = 1; start_pos <= n; ++start_pos){
            if(!dp[start_pos - 1].empty()){
                for(int len = 1; len <= n + 1 - start_pos; ++len){
                    if(words.count(s.substr(start_pos, len))){
                        dp[start_pos + len - 1].push_back(start_pos);
                    }
                }
            }
        }
        
        vector<string> answer;
        vector<int> st(n + 5);
        st[0] = n;
        back(0, st, s, answer, dp);
        
        return answer;
    }
};