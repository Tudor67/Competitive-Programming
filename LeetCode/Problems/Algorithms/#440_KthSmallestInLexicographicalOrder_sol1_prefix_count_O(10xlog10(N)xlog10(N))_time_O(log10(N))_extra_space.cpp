class Solution {
private:
    long long prefixCount(long long x, long long n, vector<long long>& sumOfPows){
        // compute how many numbers in range [1 .. n] have the prefix to_string(x)
        string xStr = to_string(x);
        string nStr = to_string(n);
        
        if(x > n){
            return 0;
        }
        
        if(xStr.length() == nStr.length()){
            // x = 1234  |  x = 1234
            // n = 3524  |  n = 1234
            return 1;
        }
        
        if(xStr.length() < nStr.length()){
            if(xStr.compare(0, xStr.length(), nStr, 0, xStr.length()) < 0){
                // x = 1234
                // n = 1256789
                return sumOfPows[(int)nStr.length() - (int)xStr.length()];
            }else if(xStr.compare(0, xStr.length(), nStr, 0, xStr.length()) == 0){
                // x = 1234    |  x = 1234
                // n = 123478  |  x = 123400
                return 1LL + sumOfPows[(int)nStr.length() - (int)xStr.length() - 1] + stoll(nStr.substr(xStr.length()));
            }else{
                // x = 1234
                // n = 111111
                return sumOfPows[(int)nStr.length() - (int)xStr.length() - 1];
            }
        }
        
        return 0;
    }
    
public:
    int findKthNumber(int n, int k) {
        // sumOfPows[i] = 10^0 + 10^1 + 10^2 + 10^3 + ... + 10^i
        vector<long long> sumOfPows(10);
        sumOfPows[0] = 1;
        for(int i = 1; i < (int)sumOfPows.size(); ++i){
            sumOfPows[i] = sumOfPows[i - 1] * 10 + 1;
        }
        
        long long x = 1;
        while(k > 1){
            long long count = prefixCount(x, n, sumOfPows);
            if(count < k){
                x += 1;
                k -= count;
            }else{
                x *= 10;
                k -= 1;
            }
        }
        
        return x;
    }
};