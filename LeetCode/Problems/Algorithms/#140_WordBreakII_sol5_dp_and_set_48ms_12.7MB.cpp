class Solution {
private:
    void back(const string& S, int pos, const vector<vector<int>>& PREV,
              vector<int>& st, vector<string>& answer){
        if(pos == 0){
            answer.push_back("");
            for(int i = (int)st.size() - 1; i >= 1; --i){
                answer.back() += (S.substr(st[i] + 1, st[i - 1] - st[i])) + " ";
            }
            answer.back().pop_back();
        }else{
            for(int prev_pos: PREV[pos]){
                st.push_back(prev_pos);
                back(S, prev_pos, PREV, st, answer);
                st.pop_back();
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(string word: wordDict){
            dict.insert(word);
        }
        
        const int N = s.length();
        vector<bool> is_valid(N + 1, false);
        vector<vector<int>> prev(N + 1);
        
        s = "#" + s;
        is_valid[0] = true;
        prev[0].push_back(0);
        
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= i; ++j){
                if(is_valid[j - 1]){
                    string word = s.substr(j, i - j + 1);
                    if(dict.count(word)){
                        is_valid[i] = true;
                        prev[i].push_back(j - 1);
                    }
                }
            }
        }
        
        vector<string> answer;
        vector<int> st;
        st.push_back(N);
        back(s, N, prev, st, answer);
        
        return answer;
    }
};