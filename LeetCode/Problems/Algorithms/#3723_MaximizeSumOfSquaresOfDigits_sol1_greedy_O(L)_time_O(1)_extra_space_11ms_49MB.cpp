class Solution {
public:
    string maxSumOfSquares(int len, int sum) {
        if(9 * len < sum){
            return "";
        }

        string s(len, '0');
        for(int i = 0; i < len && sum > 0; ++i){
            int digit = min(9, sum);
            sum -= digit;
            s[i] = char('0' + digit);
        }
        
        return s;
    }
};