class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int N = s.length();

        string res;
        int ones = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            ones += (s[r] - '0');
            while(l <= r && (s[l] == '0' || ones > k)){
                ones -= (s[l] - '0');
                l += 1;
            }
            if(ones == k){
                int len = r - l + 1;
                if(res.empty() || (int)res.length() > len ||
                   ((int)res.length() == len && res.compare(0, len, s, l, len) > 0)){
                    res = s.substr(l, len);
                }
            }
        }

        return res;
    }
};