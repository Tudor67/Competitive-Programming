class Solution {
private:
    const int INF = 1e9;

    int solve(int k, int availCookiesMask, vector<int>& cookies, vector<int>& cookiesSumFor, vector<vector<int>>& memo){
        if(availCookiesMask == 0 || k == 1){
            return cookiesSumFor[availCookiesMask];
        }

        if(memo[k][availCookiesMask] == INF){
            int res = INF;
            for(int submask = availCookiesMask; submask >= 1; submask = (submask - 1) & availCookiesMask){
                int currentRes = max(cookiesSumFor[submask],
                                     solve(k - 1, availCookiesMask ^ submask, cookies, cookiesSumFor, memo));
                res = min(res, currentRes);
            }
            memo[k][availCookiesMask] = res;
        }

        return memo[k][availCookiesMask];
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        const int C = cookies.size();
        const int FULL_MASK = (1 << C) - 1;

        vector<int> cookiesSumFor(FULL_MASK + 1);
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < C; ++bit){
                if((mask >> bit) & 1){
                    cookiesSumFor[mask] += cookies[bit];
                }
            }
        }

        vector<vector<int>> memo(k + 1, vector<int>(FULL_MASK + 1, INF));
        return solve(k, FULL_MASK, cookies, cookiesSumFor, memo);
    }
};