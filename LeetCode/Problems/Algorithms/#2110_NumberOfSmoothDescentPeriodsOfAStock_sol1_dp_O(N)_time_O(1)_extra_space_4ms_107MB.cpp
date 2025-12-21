class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        const int N = prices.size();

        long long res = 0;
        int smoothLen = 0;

        for(int i = 0; i < N; ++i){
            if(i >= 1 && prices[i - 1] - 1 == prices[i]){
                smoothLen += 1;
            }else{
                smoothLen = 1;
            }
            res += smoothLen;
        }

        return res;
    }
};