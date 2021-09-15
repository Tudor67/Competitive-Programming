class Solution {
private:
    int calculate(const string& S, int sign, int& idx, const int& N){
        int res = 0;
        while(idx < N){
            if(S[idx] == '('){
                int nextSign = (idx > 0 && S[idx - 1] == '-' ? -sign : sign);
                idx += 1;
                res += calculate(S, nextSign, idx, N);
                idx += 1;
            }else if(idx + 1 < N && S[idx + 1] == '('){
                idx += 1;
            }else{
                int currentSign = 1;
                int currentNum = 0;
                while(idx < N && S[idx] != ')' && S[idx] != '('){
                    if(S[idx] == '-' || S[idx] == '+'){
                        res += sign * currentSign * currentNum;
                        currentSign = (S[idx] == '-' ? -1 : 1);
                        currentNum = 0;
                    }else{
                        currentNum = 10 * currentNum + (S[idx] - '0');
                    }
                    idx += 1;
                }
                if(S[idx] == ')'){
                    res += sign * currentSign * currentNum;
                    return res;
                }
            }
        }
        return res;
    }
    
public:
    int calculate(string initialStr) {
        string s;
        for(char c: initialStr){
            if(c != ' '){
                s += c;
            }
        }
        
        s = "(" + s + ")";
        
        const int N = s.length();
        int sign = 1;
        int idx = 0;
        int res = calculate(s, sign, idx, N);
        
        return res;
    }
};