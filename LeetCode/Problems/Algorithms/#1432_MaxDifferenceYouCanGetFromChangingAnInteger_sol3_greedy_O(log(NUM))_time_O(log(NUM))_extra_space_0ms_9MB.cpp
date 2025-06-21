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
        for(char c: minStr){
            if(c > '1'){
                char newChar = (minStr[0] > '1' ? '1' : '0');
                replace(minStr.begin(), minStr.end(), c, newChar);
                break;
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};