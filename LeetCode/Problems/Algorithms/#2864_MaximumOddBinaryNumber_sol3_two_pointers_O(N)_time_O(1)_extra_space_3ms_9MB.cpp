class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int N = s.length();

        int i = -1;
        for(int j = 0; j < N; ++j){
            if(s[j] == '1'){
                i += 1;
                swap(s[i], s[j]);
            }
        }

        if(s[N - 1] != '1'){
            swap(s[i], s[N - 1]);
        }

        return s;
    }
};