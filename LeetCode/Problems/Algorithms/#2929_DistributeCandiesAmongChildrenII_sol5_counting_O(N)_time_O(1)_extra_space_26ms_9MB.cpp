class Solution {
public:
    long long distributeCandies(int n, int limit) {
        limit = min(limit, n);

        long long res = 0;
        for(int sum12 = 0; sum12 <= min(2 * limit, n); ++sum12){
            long long contrib12 = 0;
            if(sum12 <= limit){
                contrib12 = sum12 + 1;
            }else{
                contrib12 = 2 * limit - sum12 + 1;
            }

            int sum3 = n - sum12;
            if(0 <= sum3 && sum3 <= limit){
                res += contrib12;
            }
        }

        return res;
    }
};