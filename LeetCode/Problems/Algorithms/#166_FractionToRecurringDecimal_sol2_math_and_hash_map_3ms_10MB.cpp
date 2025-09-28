class Solution {
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
        unordered_map<long long, int> indexOf;
        indexOf[val] = -1;

        for(int i = 0; i < 10'000; ++i){
            val *= 10;
            res += char('0' + val / denominatorAbs);
            val %= denominatorAbs;
            if(val > 0 && indexOf.count(val)){
                int repeatingPartLen = i - indexOf[val];
                res.insert(res.end() - repeatingPartLen, '(');
                res.insert(res.end(), ')');
                break;
            }else{
                indexOf[val] = i;
            }
        }

        while(res.back() == '0'){
            res.pop_back();
        }

        if(res.back() == '.'){
            res.pop_back();
        }

        return res;
    }
};