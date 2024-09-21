class Solution {
public:
    string shortestPalindrome(string s) {
        const int N = s.length();

        string ps = s + "$" + string(s.rbegin(), s.rend());
        vector<int> lps(ps.length());
        for(int i = 1; i < (int)ps.length(); ++i){
            int k = lps[i - 1];
            while(k > 0 && ps[k] != ps[i]){
                k = lps[k - 1];
            }
            if(ps[k] == ps[i]){
                k += 1;
            }
            lps[i] = k;
        }

        return string(s.rbegin(), s.rend() - lps.back()) + s;
    }
};