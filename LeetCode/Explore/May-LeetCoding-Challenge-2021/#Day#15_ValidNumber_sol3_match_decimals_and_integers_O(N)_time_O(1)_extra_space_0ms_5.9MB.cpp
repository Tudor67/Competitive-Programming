class Solution {
private:
    static bool isSign(const char& C){
        return (C == '+' || C == '-');
    }
    
    static bool isSequenceOfDigits(const string& S, const int& FIRST_POS, const int& LAST_POS){
        if(FIRST_POS > LAST_POS){
            return false;
        }
        for(int i = FIRST_POS; i <= LAST_POS; ++i){
            if(!isdigit(S[i])){
                return false;
            }
        }
        return true;
    }
    
    static bool isDecimal(const string& S, const int& FIRST_POS, const int& LAST_POS){
        if(FIRST_POS > LAST_POS){
            return false;
        }
        if(count_if(S.begin() + FIRST_POS, S.begin() + LAST_POS + 1, ::isdigit) == 0){
            return false;
        }
        const int DOTS = count(S.begin() + FIRST_POS, S.begin() + LAST_POS + 1, '.');
        if(DOTS == 0 || DOTS >= 2){
            return false;
        }else{
            int dotPos = S.find('.');
            if((FIRST_POS == dotPos - 1 && !isSign(S[FIRST_POS]) && !isdigit(S[FIRST_POS])) ||
               (FIRST_POS + 1 <= dotPos - 1 && !isInteger(S, FIRST_POS, dotPos - 1)) ||
               (dotPos + 1 <= LAST_POS && !isSequenceOfDigits(S, dotPos + 1, LAST_POS))){
                return false;
            }
        }
        return true;
    }
    
    static bool isInteger(const string& S, const int& FIRST_POS, const int& LAST_POS){
        if(FIRST_POS > LAST_POS){
            return false;
        }
        if(count_if(S.begin() + FIRST_POS, S.begin() + LAST_POS + 1, ::isdigit) == 0){
            return false;
        }
        if(!isdigit(S[FIRST_POS]) && !isSign(S[FIRST_POS])){
            return false;
        }
        if(FIRST_POS + 1 <= LAST_POS && !isSequenceOfDigits(S, FIRST_POS + 1, LAST_POS)){
            return false;
        }
        return true;
    }
    
public:
    bool isNumber(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        const int N = s.length();
        const int E_COUNT = count(s.begin(), s.end(), 'e');
        
        bool isValid = true;
        if(E_COUNT == 0){
            isValid = isDecimal(s, 0, N - 1) || isInteger(s, 0, N - 1);
        }else if(E_COUNT == 1){
            int ePos = s.find('e');
            isValid = (isDecimal(s, 0, ePos - 1) || isInteger(s, 0, ePos - 1)) && isInteger(s, ePos + 1, N - 1);
        }else{
            isValid = false;
        }
        
        return isValid;
    }
};