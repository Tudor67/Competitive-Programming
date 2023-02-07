class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        const int N1 = str1.length();
        const int N2 = str2.length();

        if(str1 + str2 == str2 + str1){
            return str1.substr(0, gcd(N1, N2));
        }

        return "";
    }
};