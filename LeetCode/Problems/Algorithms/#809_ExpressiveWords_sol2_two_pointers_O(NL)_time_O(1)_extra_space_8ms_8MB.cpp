class Solution {    
    bool isValid(const string& WORD, const string& S){
        const int L1 = WORD.length();
        const int L2 = S.length();
        
        int i1 = 0;
        int i2 = 0;
        while(i1 < L1 && i2 < L2){
            int c1 = 1;
            while(i1 + c1 < L1 && WORD[i1] == WORD[i1 + c1]){
                c1 += 1;
            }
            
            int c2 = 1;
            while(i2 + c2 < L2 && S[i2] == S[i2 + c2]){
                c2 += 1;
            }
            
            if(WORD[i1] == S[i2] && ((c1 == c2) || (c1 < c2 && c2 >= 3))){
                i1 += c1;
                i2 += c2;
            }else{
                return false;
            }
        }
        
        return (i1 == L1 && i2 == L2);
    }
    
public:
    int expressiveWords(string s, vector<string>& words) {
        int answer = 0;
        for(const string& WORD: words){
            if(isValid(WORD, s)){
                answer += 1;
            }
        }
        return answer;
    }
};