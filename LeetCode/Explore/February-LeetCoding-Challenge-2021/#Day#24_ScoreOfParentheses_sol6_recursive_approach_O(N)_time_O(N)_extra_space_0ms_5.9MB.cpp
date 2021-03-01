class Solution {
private:
    pair<int, int> score(const string& S, const int& START_POS){
        int sum = 0;
        int i = START_POS;
        while(i < (int)S.length()){
            if(S[i] == '('){
                if(S[i + 1] == '('){
                    pair<int, int> p = score(S, i + 1);
                    sum += 2 * p.first;
                    i = p.second;
                }else{
                    sum += 1;
                    i += 2;
                }
            }else{
                break;
            }
        }
        return {sum, i + 1};
    }
    
public:
    int scoreOfParentheses(string S) {
        return score(S, 0).first;
    }
};