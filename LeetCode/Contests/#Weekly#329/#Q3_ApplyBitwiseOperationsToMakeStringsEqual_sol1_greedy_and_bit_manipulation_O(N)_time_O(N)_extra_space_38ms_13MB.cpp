class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        const int N = s.length();
        
        int sOnes = count(s.begin(), s.end(), '1');
        for(int i = 0; i < N; ++i){
            if(s[i] == '0' && target[i] == '1'){
                if(sOnes >= 1){
                    // s[i] is changed from 0 to 1 with | operation
                    // s[j] stays unchanged (i.e., 1)
                    // newS[i] = oldS[i] | oldS[j] = 0 | 1 = 1;
                    // newS[j] = oldS[i] ^ oldS[j] = 0 ^ 1 = 1;
                    sOnes += 1;
                    s[i] = '1';
                }
            }
        }
        
        for(int j = 0; j < N; ++j){
            if(s[j] == '1' && target[j] == '0'){
                if(sOnes >= 2){
                    // s[i] stays unchanged (i.e., 1)
                    // s[j] is changed from 1 to 0 with ^ operation
                    // newS[i] = oldS[i] | oldS[j] = 1 | 1 = 1;
                    // newS[j] = oldS[i] ^ oldS[j] = 1 ^ 1 = 0;
                    sOnes -= 1;
                    s[j] = '0';
                }
            }
        }

        return (s == target);
    }
};