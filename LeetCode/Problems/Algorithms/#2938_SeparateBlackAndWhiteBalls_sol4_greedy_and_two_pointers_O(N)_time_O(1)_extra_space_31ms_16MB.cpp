class Solution {
public:
    long long minimumSteps(string s) {
        const int N = s.length();

        long long steps = 0;
        int l = -1;
        for(int r = 0; r < N; ++r){
            if(s[r] == '0'){
                l += 1;
                steps += (r - l);
            }
        }

        return steps;
    }
};