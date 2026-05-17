class Solution {
public:
    int rotatedDigits(int n) {
        // Count good numbers in the range [1, n + 1)
        ++n;

        // Digit DP: count strictly smaller prefixes
        string s = to_string(n);
        int len = s.length();

        vector<bool> isValidDigit(10, true);
        isValidDigit[3] = false;
        isValidDigit[4] = false;
        isValidDigit[7] = false;

        vector<bool> isChangingDigit(10, true);
        isChangingDigit[0] = false;
        isChangingDigit[1] = false;
        isChangingDigit[8] = false;

        vector<int> p3(len, 1);
        vector<int> p7(len, 1);
        for(int i = 1; i < len; ++i){
            p3[i] = p3[i - 1] * 3;
            p7[i] = p7[i - 1] * 7;
        }

        int goodNums = 0;
        bool prefixHasChangeableDigits = false;
        for(int i = 0; i < len; ++i){
            for(int digit = 0; digit < s[i] - '0'; ++digit){
                if(!isValidDigit[digit]){
                    continue;
                }

                if(prefixHasChangeableDigits || isChangingDigit[digit]){
                    goodNums += p7[len - 1 - i];
                }else{
                    goodNums += p7[len - 1 - i] - p3[len - 1 - i];
                }
            }

            if(isChangingDigit[s[i] - '0']){
                prefixHasChangeableDigits = true;
            }

            if(!isValidDigit[s[i] - '0']){
                break;
            }
        }

        return goodNums;
    }
};