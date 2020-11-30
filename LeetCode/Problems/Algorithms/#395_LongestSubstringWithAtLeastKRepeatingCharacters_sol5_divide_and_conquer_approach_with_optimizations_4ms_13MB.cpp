class Solution {
private:
    void solve(const string& S, const int& START_POS, const int& END_POS, const int& K, int& answer){
        if(END_POS - START_POS + 1 < answer){
            return;
        }
        
        vector<int> count(128, 0);
        for(int i = START_POS; i <= END_POS; ++i){
            count[S[i]] += 1;
        }
        
        bool isValid = true;
        int prevInvalidPos = START_POS - 1;
        for(int i = START_POS; i <= END_POS; ++i){
            if(count[S[i]] < K){
                solve(S, prevInvalidPos + 1, i - 1, K, answer);
                prevInvalidPos = i;
                isValid = false;
            }
        }
        
        if(prevInvalidPos + 1 != START_POS && count[S[END_POS]] >= K){
            solve(S, prevInvalidPos + 1, END_POS, K, answer);
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