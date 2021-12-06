class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int Q = queries.size();
        
        vector<int> closestRightCandlePos(N, N);
        for(int i = N - 1; i >= 0; --i){
            if(s[i] == '|'){
                closestRightCandlePos[i] = i;
            }else if(i + 1 < N){
                closestRightCandlePos[i] = closestRightCandlePos[i + 1];
            }
        }
        
        vector<int> closestLeftCandlePos(N, -1);
        for(int i = 0; i < N; ++i){
            if(s[i] == '|'){
                closestLeftCandlePos[i] = i;
            }else if(i - 1 >= 0){
                closestLeftCandlePos[i] = closestLeftCandlePos[i - 1];
            }
        }
        
        vector<int> candlePrefCount(N);
        candlePrefCount[0] = (int)(s[0] == '|');
        for(int i = 1; i < N; ++i){
            candlePrefCount[i] = candlePrefCount[i - 1];
            candlePrefCount[i] += (int)(s[i] == '|');
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            int a = closestRightCandlePos[l];
            int b = closestLeftCandlePos[r];
            if(a <= b){
                int rangeSize = b - a + 1;
                int candles = candlePrefCount[b];
                if(a - 1 >= 0){
                    candles -= candlePrefCount[a - 1];
                }
                answer[i] = rangeSize - candles;
            }
        }
        
        return answer;
    }
};