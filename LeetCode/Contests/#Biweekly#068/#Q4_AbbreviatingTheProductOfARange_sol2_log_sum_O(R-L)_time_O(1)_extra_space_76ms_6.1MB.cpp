class Solution {
public:
    string abbreviateProduct(int left, int right) {
        // Step 1: count trailing zeros
        long long div2 = 0;
        long long div5 = 0;
        for(int i = left; i <= right; ++i){
            long long num = i;
            while(num % 2 == 0){
                num /= 2;
                div2 += 1;
            }
            while(num % 5 == 0){
                num /= 5;
                div5 += 1;
            }
        }
        
        long long trailingZeros = min(div2, div5);
        
        // Step 2: compute last 10 digits
        const long long POW_10_10 = 1e10;
        long long suff = 1;
        for(int i = 1; i <= div2 - trailingZeros; ++i){
            suff *= 2;
            suff %= POW_10_10;
        }
        
        for(int i = 1; i <= div5 - trailingZeros; ++i){
            suff *= 5;
            suff %= POW_10_10;
        }
        
        for(int i = left; i <= right; ++i){
            long long num = i;
            while(num % 2 == 0){
                num /= 2;
            }
            while(num % 5 == 0){
                num /= 5;
            }
            suff *= num;
            suff %= POW_10_10;
        }
        
        // Step 3: compute log10(left * (left + 1) * ... * right) = log10(left) + log10(left + 1) + ... + log10(right)
        long double logSum = 0;
        for(int i = left; i <= right; ++i){
            logSum += log10((long double)i);
        }
        
        // Step 4: return the result
        logSum -= trailingZeros;
        if(logSum < 10){
            return to_string(suff) + "e" + to_string(trailingZeros);
        }
        
        const long long POW_10_5 = 1e5;
        long long pref = pow((long double)10, 4 + logSum - floor(logSum));
        string prefStr = to_string(pref).substr(0, 5);
        string suffStr = to_string(suff % POW_10_5);
        if((int)suffStr.length() < 5){
            suffStr = string(5 - (int)suffStr.length(), '0') + suffStr;
        }
        
        return prefStr + "..." + suffStr + "e" + to_string(trailingZeros);
    }
};