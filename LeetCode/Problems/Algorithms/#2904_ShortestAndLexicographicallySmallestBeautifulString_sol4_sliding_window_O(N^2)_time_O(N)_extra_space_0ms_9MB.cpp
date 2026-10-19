class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int N = s.length();

        pair<int, string> res = {INT_MAX, ""};

        int ones = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            ones += (s[r] - '0');
            while(l <= r && (s[l] == '0' || ones > k)){
                ones -= (s[l] - '0');
                l += 1;
            }

            if(ones == k && r - l + 1 <= res.first){
                res = min(res, pair<int, string>{r - l + 1, s.substr(l, r - l + 1)});
            }
        }

        return res.second;
    }
};