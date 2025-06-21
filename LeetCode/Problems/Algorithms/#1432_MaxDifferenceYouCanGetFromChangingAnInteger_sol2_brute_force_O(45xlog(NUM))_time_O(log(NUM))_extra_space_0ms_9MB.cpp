class Solution {
public:
    int maxDiff(int num) {
        string maxStr = to_string(num);
        for(char c: maxStr){
            if(c != '9'){
                replace(maxStr.begin(), maxStr.end(), c, '9');
                break;
            }
        }

        string minStr = to_string(num);
        for(char oldDigit = '1'; oldDigit <= '9'; ++oldDigit){
            for(char newDigit = '0'; newDigit < oldDigit; ++newDigit){
                string str = to_string(num);
                replace(str.begin(), str.end(), oldDigit, newDigit);
                if(str[0] != '0'){
                    minStr = min(minStr, str);
                }
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};