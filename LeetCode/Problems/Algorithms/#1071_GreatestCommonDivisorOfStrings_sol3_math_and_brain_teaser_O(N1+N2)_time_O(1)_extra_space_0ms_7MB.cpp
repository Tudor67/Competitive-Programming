class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        const int N1 = str1.length();
        const int N2 = str2.length();

        // check if (str1 + str2 == str2 + str1)
        bool isValid = true;
        for(int i = 0; i < N1 + N2; ++i){
            char c1 = (i < N1 ? str1[i] : str2[i - N1]);
            char c2 = (i < N2 ? str2[i] : str1[i - N2]);
            if(c1 != c2){
                isValid = false;
            }
        }

        if(isValid){
            return str1.substr(0, gcd(N1, N2));
        }

        return "";
    }
};