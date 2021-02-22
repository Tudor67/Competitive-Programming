class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> letterPos;
        for(int i = 0; i < (int)S.length(); ++i){
            if(isalpha(S[i])){
                letterPos.push_back(i);
            }
        }
        
        vector<string> answer;
        const int M = letterPos.size();
        const int FULL_MASK = (1 << M) - 1;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            answer.push_back(S);
            for(int bit = 0; bit < M; ++bit){
                if((mask >> bit) & 1){
                    answer.back()[letterPos[bit]] = tolower(S[letterPos[bit]]);
                }else{
                    answer.back()[letterPos[bit]] = toupper(S[letterPos[bit]]);
                }
            }
        }
        
        return answer;
    }
};