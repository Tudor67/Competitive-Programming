class Solution {
public:
    int numDecodings(string s) {
        const int N = s.length();
        bool isValid = (s[0] > '0');
        vector<int> dp(N, 0);
        dp[0] = (s[0] > '0');
        for(int i = 1; isValid && i < s.length(); ++i){
            string dd = s.substr(i - 1, 2);
            if(dd == "00" || (dd > "26" && dd.back() == '0')){
                isValid = false;
            }else if(dd == "10" || dd == "20"){
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 1);
            }else if(dd < "10"){
                dp[i] = dp[i - 1];
            }else if(dd <= "26"){
                dp[i] = dp[i - 1] + (i - 2 >= 0 ? dp[i - 2] : 1);
            }else{
                dp[i] = dp[i - 1];
            }
        }
        return isValid * dp[N - 1];
    }
};