class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        string s = S;
        for(int i = 0; i < (int)s.length(); ++i){
            s[i] = tolower(s[i]);
        }
        
        vector<int> letterPos;
        for(int i = 0; i < (int)s.length(); ++i){
            if(isalpha(s[i])){
                letterPos.push_back(i);
            }
        }
        
        vector<string> answer;
        const int M = letterPos.size();
        const int FULL_MASK = (1 << M) - 1;
        for(unsigned int mask = 0; mask <= FULL_MASK; ++mask){
            answer.push_back(s);
            for(unsigned int x = mask; x > 0; x &= (x - 1)){
                int bit = __builtin_ctz(x);
                answer.back()[letterPos[bit]] = toupper(S[letterPos[bit]]);
            }
        }
        
        return answer;
    }
};