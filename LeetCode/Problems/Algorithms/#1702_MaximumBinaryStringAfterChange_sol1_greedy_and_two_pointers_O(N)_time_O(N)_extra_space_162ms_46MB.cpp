class Solution {
public:
    string maximumBinaryString(string binary) {
        const int N = binary.length();

        string s = binary;
        int j = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                j = max(j, i + 1);
                while(j < N && s[j] == '1'){
                    j += 1;
                }
                if(j < N){
                    s[j] = '1';
                    s[i] = '1';
                    s[i + 1] = '0';
                }
            }
        }

        return s;
    }
};