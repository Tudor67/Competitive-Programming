class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long currCommas = 1;
        for(long long left = 1000; left <= n; left *= 1000){
            long long right = min(n, left * 1000 - 1);
            totalCommas += currCommas * (right - left + 1);
            currCommas += 1;
        }
        return totalCommas;
    }
};