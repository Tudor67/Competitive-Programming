class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int N = s.length();

        for(int i = 0; i < N && s[N - 1] == '0'; ++i){
            if(s[i] == '1'){
                swap(s[i], s[N - 1]);
            }
        }

        int l = 0;
        int r = N - 2;
        while(l < r){
            if(s[l] == '1'){
                l += 1;
            }else if(s[r] == '0'){
                r -= 1;
            }else{
                swap(s[l], s[r]);
                l += 1;
                r -= 1;
            }
        }

        return s;
    }
};