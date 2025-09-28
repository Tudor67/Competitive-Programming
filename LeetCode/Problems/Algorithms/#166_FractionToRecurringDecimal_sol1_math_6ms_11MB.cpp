class Solution {
private:
    int getMinRepeatingPrefixLen(const string& S, const int START_INDEX){
        for(int len = 1; START_INDEX + 2 * len < (int)S.length(); ++len){
            bool isValid = true;
            for(int i = START_INDEX + len; i < (int)S.length(); ++i){
                if(S[i - len] != S[i]){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                return len;
            }
        }
        return 0;
    }

    string getPeriod(const string& S){
        for(int i = 0; i < (int)S.length(); ++i){
            int len = getMinRepeatingPrefixLen(S, i);
            if(len > 0){
                return S.substr(0, i) + "(" + S.substr(i, len) + ")";
            }
        }
        return S;
    }

public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if((numerator < 0 && denominator > 0) ||
           (numerator > 0 && denominator < 0)){
            res += '-';
        }
        
        long long numeratorAbs = abs((long long)numerator);
        long long denominatorAbs = abs((long long)denominator);

        res += to_string(numeratorAbs / denominatorAbs);
        res += '.';

        long long val = numeratorAbs % denominatorAbs;
        for(int i = 0; i < 10'000; ++i){
            val *= 10;
            res += char('0' + val / denominatorAbs);
            val %= denominatorAbs;
        }

        while(res.back() == '0'){
            res.pop_back();
        }

        if(res.back() == '.'){
            res.pop_back();
        }else{
            size_t indexOfDot = res.find('.');
            res = res.substr(0, indexOfDot + 1) + getPeriod(res.substr(indexOfDot + 1));
        }

        return res;
    }
};