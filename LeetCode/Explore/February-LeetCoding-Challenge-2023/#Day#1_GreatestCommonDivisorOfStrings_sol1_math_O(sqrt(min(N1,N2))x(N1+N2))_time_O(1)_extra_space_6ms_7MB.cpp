class Solution {
private:
    bool isValid(string& str1, string& str2, int len){
        const int N1 = str1.length();
        const int N2 = str2.length();

        if(N1 % len != 0 || N2 % len != 0){
            return false;
        }

        if(!equal(str1.begin(), str1.begin() + len, str2.begin())){
            return false;
        }

        for(int i = len; i < N1; ++i){
            if(str1[i - len] != str1[i]){
                return false;
            }
        }

        for(int i = len; i < N2; ++i){
            if(str2[i - len] != str2[i]){
                return false;
            }
        }

        return true;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        const int LEN1 = str1.length();
        const int LEN2 = str2.length();

        for(int len = min(LEN1, LEN2); len >= 1; --len){
            if(isValid(str1, str2, len)){
                return str1.substr(0, len);
            }
        }

        return "";
    }
};