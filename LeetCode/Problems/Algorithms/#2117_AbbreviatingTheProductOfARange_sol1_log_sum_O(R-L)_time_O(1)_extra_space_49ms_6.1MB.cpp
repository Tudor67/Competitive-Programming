class Solution {
public:
    string abbreviateProduct(int left, int right) {
        const long long POW_10_12 = 1e12;
        const long long POW_10_5 = 1e5;
        
        long long trailingZeros = 0;
        long double logSum = 0;
        long long suff = 1;
        for(long long i = left; i <= right; ++i){
            logSum += log10((long double)i);
            suff *= i;
            while(suff > 0 && suff % 10 == 0){
                suff /= 10;
                trailingZeros += 1;
            }
            suff %= POW_10_12;
        }
        
        logSum -= trailingZeros;
        
        if(logSum < 10){
            return to_string(suff) + "e" + to_string(trailingZeros);
        }
        
        long long pref = pow((long double)10, 4 + logSum - floor(logSum));
        string prefStr = to_string(pref).substr(0, 5);
        string suffStr = to_string(suff % POW_10_5);
        if((int)suffStr.length() < 5){
            suffStr = string(5 - (int)suffStr.length(), '0') + suffStr;
        }
        
        return prefStr + "..." + suffStr + "e" + to_string(trailingZeros);
    }
};