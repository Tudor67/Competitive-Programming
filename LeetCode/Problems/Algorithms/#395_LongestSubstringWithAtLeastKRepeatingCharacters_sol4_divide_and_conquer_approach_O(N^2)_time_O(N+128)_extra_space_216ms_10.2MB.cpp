class Solution {
private:
    const char MIN_CHAR = 'a';
    const char MAX_CHAR = 'z';
    vector<int> count;
    
    void solve(const string& S, const int& START_POS, const int& END_POS, const int& K, int& answer){
        if(END_POS - START_POS + 1 < answer){
            return;
        }
        
        count.resize(MAX_CHAR + 1);
        fill(count.begin() + MIN_CHAR, count.begin() + MAX_CHAR + 1, 0);
        for(int i = START_POS; i <= END_POS; ++i){
            count[S[i]] += 1;
        }
        
        bool isValid = true;
        for(int i = START_POS; isValid && i <= END_POS; ++i){
            if(count[S[i]] < K){
                solve(S, START_POS, i - 1, K, answer);
                solve(S, i + 1, END_POS, K, answer);
                isValid = false;
            }
        }
        
        if(isValid){
            answer = max(END_POS - START_POS + 1, answer);
        }
    }
    
public:
    int longestSubstring(string s, int k) {
        const int N = s.length();
        int answer = 0;
        solve(s, 0, N - 1, k, answer);
        return answer;
    }
};