class Solution {
private:
    void mirror(string& s, int targetLen){
        s.resize(targetLen, '*');
        for(int i = 0, j = targetLen - 1; i < j; ++i, --j){
            s[j] = s[i];
        }
    }

    bool isPalindrome(long long num, int base){
        string s;
        while(num > 0){
            s += char('0' + (num % base));
            num /= base;
        }
        return equal(s.begin(), s.end(), s.rbegin());
    }

public:
    long long kMirror(int k, int n) {
        vector<int> pow10(10, 1);
        for(int i = 1; i < (int)pow10.size(); ++i){
            pow10[i] = pow10[i - 1] * 10;
        }

        long long sumOfValidNums = 0;
        for(int targetLen = 1; targetLen <= 18 && n >= 1; ++targetLen){
            for(int pref = pow10[(targetLen - 1) / 2]; pref < pow10[(targetLen - 1) / 2 + 1] && n >= 1; ++pref){
                string s = to_string(pref);
                mirror(s, targetLen);
                if(isPalindrome(stoll(s), k)){
                    sumOfValidNums += stoll(s);
                    n -= 1;
                }
            }
        }

        return sumOfValidNums;
    }
};