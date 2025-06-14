class Solution {
private:
    void replace(string& s, char oldChar, char newChar){
        for(char& c: s){
            if(c == oldChar){
                c = newChar;
            }
        }
    }

public:
    int minMaxDifference(int num) {
        string maxStr = to_string(num);
        for(char c: maxStr){
            if(c != '9'){
                replace(maxStr, c, '9');
                break;
            }
        }

        string minStr = to_string(num);
        replace(minStr, minStr[0], '0');

        return stoi(maxStr) - stoi(minStr);
    }
};