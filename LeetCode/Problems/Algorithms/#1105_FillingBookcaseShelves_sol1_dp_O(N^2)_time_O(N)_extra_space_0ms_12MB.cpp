class Solution {
private:
    int getVal(vector<int>& dp, int i){
        if(0 <= i && i < (int)dp.size()){
            return dp[i];
        }
        return 0;
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        const int N = books.size();
        const int INF = 1e9;

        // dp[i]: min possible height for books[0 .. i]
        vector<int> dp(N, INF);
        
        for(int i = 0; i < N; ++i){
            int totalWidth = 0;
            int maxHeight = 0;
            for(int j = i; j >= 0; --j){
                totalWidth += books[j][0];
                maxHeight = max(maxHeight, books[j][1]);
                if(totalWidth <= shelfWidth){
                    dp[i] = min(dp[i], getVal(dp, j - 1) + maxHeight);
                }else{
                    break;
                }
            }
        }

        return dp[N - 1];
    }
};