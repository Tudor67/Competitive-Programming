class Solution {
public:
    string shortestPalindrome(string s) {
        const int N = s.length();

        string ss;
        ss.push_back('.');
        for(char c: s){
            ss.push_back(c);
            ss.push_back('.');
        }

        int maxPalindromePrefixLen = 0;
        vector<int> r(ss.length());
        int a = 0;
        int b = 0;
        for(int i = 0; i < (int)ss.length(); ++i){
            if(i <= b){
                r[i] = min(r[a + b - i], b - i + 1);
            }
            while(0 <= i - r[i] && i + r[i] < (int)ss.length() && ss[i - r[i]] == ss[i + r[i]]){
                r[i] += 1;
            }
            if(b <= i + r[i] - 1){
                a = i - r[i] + 1;
                b = i + r[i] - 1;
            }
            if(r[i] == i + 1){
                maxPalindromePrefixLen = i;
            }
        }

        return string(s.rbegin(), s.rend() - maxPalindromePrefixLen) + s;
    }
};