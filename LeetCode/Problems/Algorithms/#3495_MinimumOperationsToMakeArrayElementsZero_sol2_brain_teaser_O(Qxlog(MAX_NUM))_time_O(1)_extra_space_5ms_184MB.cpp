class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;

        for(const vector<int>& QUERY: queries){
            long long qL = QUERY[0];
            long long qR = QUERY[1];

            long long currL = 1;
            long long currR = 4 * currL - 1;
            long long currOpsPerNum = 1;
            long long opsSum = 0;

            while(currL <= qR){
                long long intersectL = max(currL, qL);
                long long intersectR = min(currR, qR);
                if(intersectL <= intersectR){
                    opsSum += (intersectR - intersectL + 1) * currOpsPerNum;
                }
                currL *= 4;
                currR = 4 * currL - 1;
                currOpsPerNum += 1; 
            }

            res += (opsSum + 1) / 2;
        }

        return res;
    }
};