class Solution {
private:
    int score(const string& S, int& pos){
        int sum = 0;
        while(pos < (int)S.length()){
            if(S[pos] == '('){
                if(S[pos + 1] == '('){
                    pos += 1;
                    sum += 2 * score(S, pos);
                }else{
                    pos += 2;
                    sum += 1;
                }
            }else{
                pos += 1;
                break;
            }
        }
        return sum;
    }
    
public:
    int scoreOfParentheses(string S) {
        int pos = 0;
        return score(S, pos);
    }
};