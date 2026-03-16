class Solution {
private:
    char kThValidChar(char prevChar, int k){
        int prevCharIndex = prevChar - 'a' + 1;
        if(k < prevCharIndex){
            return 'a' - 1 + k;
        }
        return 'a' + k;
    }

public:
    string getHappyString(int n, int k) {
        int distinctHappyStrings = 3;
        for(int i = 2; i <= n; ++i){
            distinctHappyStrings *= 2;
        }

        if(distinctHappyStrings < k){
            return "";
        }

        string res(n, 'a');
        if(k <= distinctHappyStrings / 3){
            res[0] = 'a';
        }else if(k <= 2 * distinctHappyStrings / 3){
            res[0] = 'b';
            k -= distinctHappyStrings / 3;
        }else{
            res[0] = 'c';
            k -= 2 * distinctHappyStrings / 3;
        }

        for(int i = 1; i < n; ++i){
            int remHappyStrings = (1 << (n - i));
            if(k <= remHappyStrings / 2){
                res[i] = kThValidChar(res[i - 1], 1);
            }else{
                k -= remHappyStrings / 2;
                res[i] = kThValidChar(res[i - 1], 2);
            }
        }

        return res;
    }
};