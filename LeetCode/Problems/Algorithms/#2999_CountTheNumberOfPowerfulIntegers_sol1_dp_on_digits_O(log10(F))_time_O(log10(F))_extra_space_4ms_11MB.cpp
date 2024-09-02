class Solution {
private:
    long long countPowerfulNums(long long maxNum, int limit, string suff){
        string maxNumStr = to_string(maxNum);
        int maxNumLen = maxNumStr.length();
        int suffLen = suff.length();

        if(maxNumLen < suffLen){
            return 0;
        }

        // dp[i]: number of strings of length i consisting of digits: 0, 1, 2, ..., limit
        //        leading zeros are allowed
        vector<long long> dp(maxNumLen + 1, 1);
        for(long long i = 1; i <= maxNumLen; ++i){
            dp[i] = (limit + 1) * dp[i - 1];
        }

        long long res = 0;
        int remLen = maxNumLen - suffLen;
        for(int i = 0; i < maxNumLen - suffLen; ++i){
            long long maxValidDigit = min(maxNumStr[i] - '0' - 1, limit);
            res += (maxValidDigit + 1) * dp[remLen - 1];
            remLen -= 1;
            if(maxNumStr[i] - '0' > limit){
                break;
            }
        }

        if(*max_element(maxNumStr.begin(), maxNumStr.end() - suffLen) - '0' <= limit &&
           suff <= maxNumStr.substr(maxNumLen - suffLen)){
            res += 1;
        }

        return res;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countPowerfulNums(finish, limit, s) - countPowerfulNums(start - 1, limit, s);
    }
};