class Solution {
private:
    string specialConversion(int num, const int BASE, const int LEN){
        string s(LEN, 'a');
        for(int i = LEN - 1; i >= 0; --i){
            s[i] = char('a' + num % BASE);
            num /= BASE;
        }
        return s;
    }

    bool isValid(const string& S){
        for(int i = 0; i + 1 < (int)S.length(); ++i){
            if(S[i] == S[i + 1]){
                return false;
            }
        }
        return true;
    }

public:
    string getHappyString(int n, int k) {
        const int BASE = 3;

        int distinctNums = 1;
        for(int i = 1; i <= n; ++i){
            distinctNums *= BASE;
        }

        for(int num = 0; num < distinctNums; ++num){
            string s = specialConversion(num, BASE, n);

            if(isValid(s)){
                k -= 1;
            }

            if(k == 0){
                return s;
            }
        }

        return "";
    }
};