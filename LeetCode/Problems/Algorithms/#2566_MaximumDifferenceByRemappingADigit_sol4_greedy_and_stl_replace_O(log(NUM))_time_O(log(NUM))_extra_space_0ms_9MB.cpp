class Solution {
public:
    int minMaxDifference(int num) {
        string maxStr = to_string(num);
        for(char c: maxStr){
            if(c != '9'){
                replace(maxStr.begin(), maxStr.end(), c, '9');
                break;
            }
        }

        string minStr = to_string(num);
        replace(minStr.rbegin(), minStr.rend(), minStr[0], '0');

        return stoi(maxStr) - stoi(minStr);
    }
};