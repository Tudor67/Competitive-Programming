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
        int min_word_length = n + 5;
        int max_word_length = 0;
        for(const string& word: wordDict){
            words.insert(word);
            min_word_length = min((int)word.length(), min_word_length);
            max_word_length = max((int)word.length(), max_word_length);
        }
        
        vector<vector<int>> dp(n + 1, vector<int>());
        dp[0].push_back(0);
        
        for(int start_pos = 1; start_pos <= n + 1 - min_word_length; ++start_pos){
            if(!dp[start_pos - 1].empty()){
                for(int len = min_word_length; len + start_pos - 1 <= n && len <= max_word_length; ++len){
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