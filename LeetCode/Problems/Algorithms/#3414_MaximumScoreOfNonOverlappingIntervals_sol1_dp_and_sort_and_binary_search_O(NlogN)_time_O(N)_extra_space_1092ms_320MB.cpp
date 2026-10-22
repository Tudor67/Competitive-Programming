class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (intervals[lhs][0] < intervals[rhs][0]);
             });
             
        // dp[c][i]: max score for at most c non-overlapping intervals
        //           among intervals[p[i]], intervals[p[i + 1]], ..., intervals[p[N - 1]]
        vector<vector<unsigned int>> dp(5, vector<unsigned int>(N + 1));
        vector<vector<vector<int>>> indices(5, vector<vector<int>>(N + 1));

        for(int c = 1; c <= 4; ++c){
            for(int i = N - 1; i >= 0; --i){
                int l = i + 1;
                int r = N;
                while(l != r){
                    int mid = (l + r) / 2;
                    if(intervals[p[i]][1] >= intervals[p[mid]][0]){
                        l = mid + 1;
                    }else{
                        r = mid;
                    }
                }

                unsigned int takeScore = intervals[p[i]][2] + dp[c - 1][r];
                unsigned int skipScore = dp[c][i + 1];

                vector<int> takeIds = indices[c - 1][r];
                takeIds.push_back(p[i]);
                sort(takeIds.begin(), takeIds.end());

                vector<int> skipIds = indices[c][i + 1];

                if((takeScore > skipScore) || (takeScore == skipScore && takeIds < skipIds)){
                    dp[c][i] = takeScore;
                    indices[c][i] = takeIds;
                }else{
                    dp[c][i] = skipScore;
                    indices[c][i] = skipIds;
                }
            }
        }

        return indices[4][0];
    }
};