class Solution {
public:
    string smallestGoodBase(string n) {
        const long long N = stoll(n);
        string answer;
        for(long long base = 2; base <= N; ++base){
            long long x = (base - 1) * N + 1;
            while(x % base == 0){
                x /= base;
            }
            if(x == 1){
                answer = to_string(base);
                break;
            }
        }
        return answer;
    }
};