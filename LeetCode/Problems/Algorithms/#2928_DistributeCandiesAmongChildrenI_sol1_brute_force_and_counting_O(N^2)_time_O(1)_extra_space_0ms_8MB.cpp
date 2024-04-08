class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ways = 0;
        for(int a = 0; a <= n; ++a){
            for(int b = 0; b + a <= n; ++b){
                int c = n - a - b;
                if(a <= limit && b <= limit && c <= limit){
                    ways += 1;
                }
            }
        }
        return ways;
    }
};