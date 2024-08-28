class Solution {
private:
    bool isPowOf10(long long num){
        while(num > 1 && num % 10 == 0){
            num /= 10;
        }
        return (num == 1);
    }

    long long generatePalindrome(long long half, int len){
        string s = to_string(half);
        s.resize(len, '9');
        copy(s.begin(), s.end(), s.rbegin());
        return stoll(s);
    }

public:
    string nearestPalindromic(string numStr) {
        int len = numStr.length();
        long long num = stoll(numStr);
        long long half = stoll(numStr.substr(0, (len + 1) / 2));

        if(len == 1){
            return to_string(num - 1);
        }

        vector<long long> palindromes;
        if(half - 1 == 0){
            palindromes.push_back(generatePalindrome(9, len - 1));
        }else{
            palindromes.push_back(generatePalindrome(half - 1, len - (int)isPowOf10(half)));
        }
        palindromes.push_back(generatePalindrome(half, len));
        palindromes.push_back(generatePalindrome(half + 1, len + (int)isPowOf10(half + 1)));

        long long res = 0;
        for(long long p: palindromes){
            if(p != num &&
               pair<long long, long long>{abs(num - p), p} < pair<long long, long long>{abs(num - res), res}){
                res = p;
            }
        }

        return to_string(res);
    }
};