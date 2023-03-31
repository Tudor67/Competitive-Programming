class Solution {
private:
    bool isScramble(string s1, string s2, unordered_map<string, bool>& memo) {
        const int N = s1.length();

        if(s1 == s2){
            return true;
        }

        string state = s1 + "$" + s2;
        if(memo.count(state)){
            return memo[state];
        }
        
        for(int i = 0; i + 1 < N; ++i){
            string x = s1.substr(0, i + 1);
            string y = s1.substr(i + 1);
            if((isScramble(x, s2.substr(0, x.length()), memo) && isScramble(y, s2.substr(x.length()), memo)) ||
               (isScramble(y, s2.substr(0, y.length()), memo) && isScramble(x, s2.substr(y.length()), memo))){
                memo[state] = true;
                return true;
            }
        }

        memo[state] = false;
        return false;
    }
    
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> memo;
        return isScramble(s1, s2, memo);
    }
};