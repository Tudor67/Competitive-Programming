class Solution {
private:
    char nextChar(char c){
        if(c == 'z'){
            return 'a';
        }
        return c + 1;
    }

public:
    bool canMakeSubsequence(string str1, string str2) {
        const int N1 = str1.length();
        const int N2 = str2.length();

        int i2 = 0;
        for(int i1 = 0; i1 < N1 && i2 < N2; ++i1){
            if(str1[i1] == str2[i2] || nextChar(str1[i1]) == str2[i2]){
                i2 += 1;
            }
        }

        return(i2 == N2);
    }
};