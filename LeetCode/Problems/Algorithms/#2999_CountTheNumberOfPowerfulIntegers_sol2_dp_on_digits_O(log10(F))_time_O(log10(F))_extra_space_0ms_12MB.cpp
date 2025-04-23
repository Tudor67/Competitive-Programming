class Solution {
private:
    long long f(long long maxNum, long long digitLimit, string suff){
        string s = to_string(maxNum);
        int sLen = s.length();
        int suffLen = suff.length();

        if(sLen < suffLen){
            return 0;
        }

        vector<long long> p(sLen + 1, 1);
        for(int i = 1; i < (int)p.size(); ++i){
            p[i] = p[i - 1] * (digitLimit + 1);
        }

        long long res = 0;
        for(int i = 0; i < sLen - suffLen; ++i){
            long long maxDigit = min((long long)(s[i] - '0' - 1), digitLimit);
            res += (maxDigit + 1) * p[sLen - suffLen - 1 - i];
            if(s[i] > char('0' + digitLimit)){
                return res;
            }
        }

        if(s.substr(sLen - suffLen) >= suff){
            res += 1;
        }

        return res;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suff) {
        return f(finish, limit, suff) - f(start - 1, limit, suff);
    }
};