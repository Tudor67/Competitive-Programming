class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;

        for(const vector<int>& QUERY: queries){
            long long l = QUERY[0];
            long long r = QUERY[1];
            long long opsSum = 0;

            for(long long p4 = 4, opsPerNum = 1; p4 <= 4 * r; p4 *= 4, opsPerNum += 1){
                if(l < p4){
                    // we need opsPerNum operations for each num in the range [l, p4)
                    long long cnt = min(p4, r + 1) - l;
                    opsSum += cnt * opsPerNum;
                    l = p4;
                }
            }

            res += (opsSum + 1) / 2;
        }

        return res;
    }
};