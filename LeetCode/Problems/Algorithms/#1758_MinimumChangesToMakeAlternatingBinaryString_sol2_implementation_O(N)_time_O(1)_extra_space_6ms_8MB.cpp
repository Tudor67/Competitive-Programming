class Solution {
public:
    int minOperations(string s) {
        const int N = s.length();

        int ops = 0;
        for(int i = 0; i < N; ++i){
            if(i % 2 != (s[i] - '0') % 2){
                ops += 1;
            }
        }

        return min(ops, N - ops);
    }
};