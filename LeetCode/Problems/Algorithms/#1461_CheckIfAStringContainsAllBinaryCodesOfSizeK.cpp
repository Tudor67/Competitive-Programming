class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int MAX_VAL = (1 << k);
        vector<bool> vis(MAX_VAL, false);
        for(int i = 0, num = 0; i < s.length(); ++i){
            num = 2 * num + (s[i] - '0');
            if(i >= k){
                num %= MAX_VAL;
            }
            if(i >= k - 1){
                vis[num] = true;
            }
        }
        bool has_all_codes = (count(vis.begin(), vis.end(), true) == MAX_VAL);
        return has_all_codes;
    }
};