class Solution {
public:
    string smallestString(string s) {
        const int N = s.length();

        // Step 1: find the 1st char different from 'a'
        //         apply the operation on the range [posOfFirstNonA, posOfFirstA - 1]
        int i = 0;
        while(i < N){
            if(s[i] == 'a'){
                i += 1;
            }else{
                while(i < N && s[i] != 'a'){
                    s[i] -= 1;
                    i += 1;
                }
                return s;
            }
        }

        // Step 2: s consists only of 'a' chars
        //         apply the operation on the last 'a'
        s[N - 1] = 'z';
        return s;
    }
};