class Solution {
public:
    int maxDiff(int num) {
        string minStr = to_string(num);
        string maxStr = to_string(num);

        for(char oldDigit = '0'; oldDigit <= '9'; ++oldDigit){
            for(char newDigit = '0'; newDigit <= '9'; ++newDigit){
                string str = to_string(num);
                replace(str.begin(), str.end(), oldDigit, newDigit);
                if(str[0] != '0'){
                    minStr = min(minStr, str);
                    maxStr = max(maxStr, str);
                }
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};