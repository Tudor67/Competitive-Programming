class Solution {
public:
    string countAndSay(int n) {
        vector<string> s = {"", "1"};
        for(int i = 2; i <= n; ++i){
            s[i % 2].clear();
            int count = 1;
            for(int j = 1; j <= (int)s[(i - 1) % 2].length(); ++j){
                if(j < (int)s[(i - 1) % 2].length() && s[(i - 1) % 2][j] == s[(i - 1) % 2][j - 1]){
                    count += 1;
                }else{
                    s[i % 2] += to_string(count);
                    s[i % 2] += s[(i - 1) % 2][j - 1];
                    count = 1;
                }
            }
        }
        return s[n % 2];
    }
};