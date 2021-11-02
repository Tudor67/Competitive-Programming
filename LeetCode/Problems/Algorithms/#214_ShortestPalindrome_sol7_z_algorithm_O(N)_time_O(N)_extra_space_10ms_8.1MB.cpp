class Solution {
public:
    string shortestPalindrome(string s) {
        const string PS = s + "$" + string(s.rbegin(), s.rend());
        const int L = PS.length();
        
        vector<int> z(L);
        int l = 0;
        int r = 0;
        int maxPalindromePrefixLength = 0;
        for(int i = 1; i < L; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < L && PS[z[i]] == PS[i + z[i]]){
                z[i] += 1;
            }
            if(i + z[i] - 1 >= r){
                l = i;
                r = i + z[i] - 1;
            }
            if(i + z[i] == L){
                maxPalindromePrefixLength = z[i];
                break;
            }
        }
        
        return string(s.rbegin(), s.rbegin() + (int)s.length() - maxPalindromePrefixLength) + s;
    }
};