class Solution {
public:
    long long minimumSteps(string s) {
        const int N = s.length();
        const long long ZEROS = count(s.begin(), s.end(), '0');

        long long steps = -(ZEROS - 1) * ZEROS / 2;
        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                steps += i;
            }
        }

        return steps;
    }
};