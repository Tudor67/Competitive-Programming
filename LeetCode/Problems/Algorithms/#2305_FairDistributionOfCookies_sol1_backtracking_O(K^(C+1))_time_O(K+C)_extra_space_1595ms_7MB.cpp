class Solution {
private:
    const int INF = 1e9;

    int solve(int index, vector<int>& sum, vector<int>& cookies){
        if(index == (int)cookies.size()){
            return *max_element(sum.begin(), sum.end());
        }

        int res = INF;
        for(int child = 0; child < (int)sum.size(); ++child){
            sum[child] += cookies[index];
            res = min(res, solve(index + 1, sum, cookies));
            sum[child] -= cookies[index];
        }

        return res;
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sum(k);
        return solve(0, sum, cookies);
    }
};