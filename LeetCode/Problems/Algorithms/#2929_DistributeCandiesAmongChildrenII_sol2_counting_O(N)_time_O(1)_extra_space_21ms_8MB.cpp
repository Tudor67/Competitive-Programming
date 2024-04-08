class Solution {
public:
    long long distributeCandies(int n, int limit) {
        limit = min(limit, n);

        long long ways = 0;
        for(int a = 0; a <= limit; ++a){
            int remSum = n - a;
            if(remSum <= limit){
                ways += (remSum + 1);
            }else if(remSum <= 2 * limit + 1){
                ways += (2 * limit + 1 - remSum);
            }
        }

        return ways;
    }
};