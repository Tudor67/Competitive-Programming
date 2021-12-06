class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int Q = queries.size();
        
        vector<int> candlePositions;
        for(int i = 0; i < N; ++i){
            if(s[i] == '|'){
                candlePositions.push_back(i);
            }
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            int lIdx = lower_bound(candlePositions.begin(), candlePositions.end(), l) - candlePositions.begin();
            int rIdx = upper_bound(candlePositions.begin(), candlePositions.end(), r) - candlePositions.begin() - 1;
            if(lIdx <= rIdx){
                int rangeSize = candlePositions[rIdx] - candlePositions[lIdx] + 1;
                int candles = rIdx - lIdx + 1;
                int plates = rangeSize - candles;
                answer[i] = plates;
            }
        }
        
        return answer;
    }
};